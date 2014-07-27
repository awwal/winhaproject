#include "winhawidget.h"

#include "QDebug"
#include <QtGui>
#include <QtWebKit>


//#define DEBUG
#define URL "https://secure.puv.fi/wille/elogon.asp"
const int NCOLS =9;
const int APP_WIDTH=350;
const int APP_HEIGHT=500;

Winhawidget::Winhawidget(QProgressBar* bar,QWidget *parent) :     QWidget(parent)

{

    exportBtn = new QPushButton("Ex&port");
    exportBtn->setVisible(false);

    this->webView=new QWebView();
    this->progressBar=bar;
    progressBar->setValue(0);
    tableWidget = new QTableWidget();


    QLabel* tlabel = new QLabel("TNU",this);
    QLabel* glabel= new QLabel("CGPA",this);
    tnuEdit= new QLineEdit(this);
    tlabel->setBuddy(tnuEdit);
    gpaEdit = new QLineEdit(this);
    glabel->setBuddy(gpaEdit);

    QHBoxLayout*  hlay= new QHBoxLayout();
    hlay->setObjectName("qhboxlayoutinwinhawidget");
    hlay->setSpacing(6);
    hlay->addWidget(tlabel);
    hlay->addWidget(tnuEdit);
    hlay->addWidget(glabel);
    hlay->addWidget(gpaEdit);


    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setObjectName("vlayinwinhawidget");
    verticalLayout->addWidget(exportBtn);
    verticalLayout->addWidget(tableWidget);
    verticalLayout->addLayout(hlay);


    connect(webView, SIGNAL(loadFinished(bool)),this, SLOT(loginPage(bool)));
    connect(webView, SIGNAL(loadProgress(int)),this->progressBar, SLOT(setValue(int)));
    connect(exportBtn,SIGNAL(clicked()),this,SLOT(onExportBtnClicked()));

    gpHandler = new GPHandler(this);
    tableWidget->resize(2*APP_WIDTH,tableWidget->geometry().height());






}

void Winhawidget::setUserCredentials(QString username, QString password){


    userName=username;
    passWord=password;

    webView->load(QUrl(URL));



}




void Winhawidget::onExportBtnClicked(){
    ExportOption exportOption(this);
    exportOption.exec();
    if(exportOption.optionPicked==-1)return;
    else if(exportOption.optionPicked==1){
        gpHandler->exportToPdf();
    }
    else if(exportOption.optionPicked==2){
        gpHandler->exportToText();
    }
    else if(exportOption.optionPicked==3){
        qDebug()<<"option 3";
        gpHandler->exportToCSV();
    }
}


Winhawidget::~Winhawidget()
{
    delete  gpHandler;
    delete verticalLayout;

}

void Winhawidget::changeEvent(QEvent *e)
{

}


void Winhawidget::createTable(QStringList& tableHeader, QList<QStringList>& content)  {

    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(9);

    for(int i=0;i!=tableHeader.length();i++){

        QTableWidgetItem *headerItem = new QTableWidgetItem();
        headerItem->setText(tableHeader.at(i));
        headerItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(i, headerItem);
    }
    //    qDebug()<<tableHeader;
    int rowNo=0;
    foreach(QStringList rowValues, content)
    {
        //        qDebug()<<rowValues;
        if(rowValues.length()>9){
            qDebug()<<"what";
            break;
        }
        tableWidget->insertRow(tableWidget->rowCount());
        gpHandler->updateGP(rowValues.at(0),rowValues.at(2),rowValues.at(5) );


        for(int col=0;col<9;col++){
            QTableWidgetItem *itemCol = new QTableWidgetItem(rowValues.at(col),0);
            itemCol->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
            tableWidget->setItem(rowNo,col, itemCol);
        }
        rowNo++;

    }

    tnuEdit->setText(gpHandler->getTNU());
    gpaEdit->setText(gpHandler->getCGP());

}
QWebElement Winhawidget::document() const {
    return webView->page()->mainFrame()->documentElement();
}
void Winhawidget::resetProgressBar(){
    webView->disconnect();
    progressBar->setValue(0);
    connect(webView, SIGNAL(loadProgress(int)),  progressBar, SLOT(setValue(int)));
}
void Winhawidget::loginPage(bool ok){
    if(!ok){

        return;
    }
    emit statusUpdate("Attempting to Login");
    resetProgressBar();
    connect(webView, SIGNAL(loadFinished(bool)),this, SLOT(winhaPage(bool)));



    QWebElement forme=  document().findFirst("form[name=Inputti]");
    QWebElement we=  forme.findFirst("input[name=dfUsernameHidden]");
    we.setAttribute("value",userName);
    QWebElement pe= forme.findFirst("input[name=dfPasswordHidden]");
    pe.setAttribute("value",passWord);
    QWebElement fe=  document().findFirst("form[name=Inputti]");

    fe.evaluateJavaScript("this.submit();");



}

void Winhawidget::completionPage(bool ok){

    if(!ok){

        return;
    }

    emit statusUpdate("Parsing your completed courses ..");

    resetProgressBar();


    exportBtn->setVisible(true);

    QStringList headings;
    QWebElement table=  document().findFirst(".tdTblFieldName");
    if(table.isNull()){
        emit statusUpdate("Seriously are you a student ?");

        emit doneFinally(false);
        return;
    }


    this->resize(2*APP_WIDTH,this->geometry().height()+10);
    tableWidget->resizeColumnsToContents();
    tableWidget->resize(670,tableWidget->geometry().height()+10);
    for(int i=0;i<NCOLS;i++){
        headings<<table.toPlainText();
        table=  table.nextSibling();
    }
    //classes tdTblFieldData are tablerows that contain the values
    QWebElementCollection tablerow=  document().findAll(".tdTblFieldData");
    QList<QStringList> allRows;
    QStringList rowValues;
    int count=0;
    foreach(QWebElement elem, tablerow ){
        rowValues<<elem.toPlainText();
        if(++count%9==0){
            allRows.append(QStringList(rowValues));
            rowValues.clear();
        }

    }

    createTable(headings,allRows);
    //TODO actual logout
    webView->setUrl(QUrl("about:blank"));
    progressBar->setValue(0);
    emit doneFinally(true);
    emit statusUpdate("Done");
}



void Winhawidget::preCompletionPage(bool ok){
    if(!ok){
        emit doneFinally(false);
        return;
    }

    webView->disconnect();
    resetProgressBar();
    connect(webView, SIGNAL(loadFinished(bool)),this, SLOT(completionPage(bool)));

    QWebElement forme=  document().findFirst("form[name=hopshae]");
    //    QWebElement tableEl=  forme.findFirst("table.tblBgColor");

    QWebElementCollection completionEl=  forme.findAll("input[name=rbRajaus]");
    foreach(QWebElement radel, completionEl){
        if(radel.attribute("value").compare("rbSuoritukset")==0){
            radel.setAttribute("checked","true");

        }
        else{
            radel.removeAttribute("checked");
        }

    }
    QWebElement fe=  document().findFirst("form[name=hopshae]");
    fe.evaluateJavaScript("this.submit();");

    emit statusUpdate("Ready to get Courses");


}
void Winhawidget::winhaPage(bool ok){
    if(!ok){
        emit doneFinally(false);
        return;
    }

    //https://secure.puv.fi/wille/elogon.asp?dfUsername?dfPassword?dfUsernameHuoltaja
    //    https://secure.puv.fi/wille/emain.asp success


    QString location = webView->url().toString();
    if(location.endsWith("?dfUsername?dfPassword?dfUsernameHuoltaja")){


        emit statusUpdate("Invalid Username");
        emit doneFinally(false);
        return;
    }



    resetProgressBar();
    connect(webView, SIGNAL(loadFinished(bool)),this, SLOT(preCompletionPage(bool)));
    webView->load(QUrl("https://secure.puv.fi/wille/eHopshae.Asp"));
    emit statusUpdate("Selecting your completion ..");

}




