#include "mailwidget.h"
#include "QDebug"
#include <QtGui>
#include <QtWebKit>

//#define DEBUG
#define URL "https://webmail.puv.fi/horde/imp/login.php"


const int NCOLS = 6;
MailWidget::MailWidget(QProgressBar* bar,QWidget *parent) :  QWidget(parent)
{
     QNetworkProxyFactory::setUseSystemConfiguration(true);
    this->progressBar=bar;
}

void MailWidget::restart()
{
    this->webView=new QWebView();

    resetProgressBar();
    tableWidget = new QTableWidget();

    //TODO add spacer
    verticalLayout = new QVBoxLayout(this);
    verticalLayout->addWidget(tableWidget);
}

void MailWidget::initSession(QString username, QString password)
{
  qDebug()<<"initSession username"<<username<<password  ;
    restart();
    userName=username;
    passWord=password;
    webView->load(QUrl(URL));
    connect(webView, SIGNAL(loadFinished(bool)),this, SLOT(loginPage(bool)));
}

QWebElement MailWidget::document() const {
    return webView->page()->mainFrame()->documentElement();
}


void MailWidget::mailPage(bool ok){


    if(!ok){
        emit statusUpdate("Login UnSucessful");
        return;
    }

    QString location = webView->url().toString();
    //as seen on the site , the url ends with failed when login fails
    if(location.endsWith("failed")){
        emit statusUpdate("Invalid Username or password");
        emit doneFinally(false);
        return;
    }


    emit statusUpdate("Login Sucessful");

    QWebElement quotaEl= document().findFirst("td.control table tbody tr td b a");
    QString percentQuota = quotaEl.toPlainText();


    QWebElement inboxEl= document().findFirst("div.header span span");
    QString inboxState = inboxEl.toPlainText();


    QStringList headings;
    headings<<""<<"Number"<<"Date"<<"From"<<"Subject"<<"Size";

    //unread mails
    QWebElementCollection unseenEl= document().findAll("tr.unseen td");
    if(unseenEl.count()==0){

        emit statusUpdate("No new Email");
        //no new emails
        return;
    }

    QList<QStringList> allRows;
    int count=0;
    QStringList rowValues;

    foreach(QWebElement elem, unseenEl ){

        rowValues<<elem.toPlainText();
        if(++count%NCOLS==0){

            allRows.append(QStringList(rowValues));
            rowValues.clear();
        }
    }
    createTable(headings,allRows);
    delete webView;
    emit doneFinally(true);
    QString pq = "  " + percentQuota;
    emit statusUpdate("Done  " + pq);
    this->disconnect();
}


void MailWidget::createTable(QStringList& tableHeader, QList<QStringList>& content)  {
    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(NCOLS);

    for(int i=0;i!=tableHeader.length();i++){

        QTableWidgetItem *headerItem = new QTableWidgetItem();
        headerItem->setText(tableHeader.at(i));
        headerItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(i, headerItem);
    }
    //        qDebug()<<tableHeader<<content;
    int rowNo=0;
    foreach(QStringList rowValues, content)
    {

        if(rowValues.length()>NCOLS){
            qDebug()<<"TODO handle error here";
            break;
        }
        tableWidget->insertRow(tableWidget->rowCount());//add one more row


        for(int col=0;col<NCOLS;col++){
            QTableWidgetItem *itemCol = new QTableWidgetItem(rowValues.at(col),0);
            itemCol->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
            tableWidget->setItem(rowNo,col, itemCol);
        }
        rowNo++;

    }

    tableWidget->setAlternatingRowColors(true);


    //hide uninteresting columns , resize the rest to size layout
    tableWidget->hideColumn(0);
    tableWidget->hideColumn(1);
    tableWidget->hideColumn(5);
    tableWidget->setColumnWidth(2,tableWidget->size().width()/3);
    tableWidget->setColumnWidth(3,tableWidget->size().width()/3);
    tableWidget->setColumnWidth(4,tableWidget->size().width()/3);




}

void MailWidget::resetProgressBar(){
    webView->disconnect();
    progressBar->setValue(0);
    connect(webView, SIGNAL(loadProgress(int)), progressBar, SLOT(setValue(int)));
}

void MailWidget::loginPage(bool ok){
    if(!ok){

         qDebug()<<webView->url();
        emit statusUpdate("");

        QMessageBox msg(QMessageBox::Critical,"Connectivity issue","Perhaps your internet connectivity is down or the webmail website is down or Openssl has not been installed on your system. see the application manual",NULL,this,Qt::Dialog);
        msg.exec();
        emit doneFinally(false);
        return;
    }
    emit statusUpdate("Attempting to Login");
    resetProgressBar();
    connect(webView, SIGNAL(loadFinished(bool)),this, SLOT(mailPage(bool)));

    QWebElement forme=  document().findFirst("form[name=imp_login]");
    QWebElement we=  forme.findFirst("input[name=imapuser]");
    we.setAttribute("value",userName);
    QWebElement pe= forme.findFirst("input[name=pass]");
    pe.setAttribute("value",passWord);
    QWebElement fe=  document().findFirst("form[name=imp_login]");
    fe.evaluateJavaScript("this.submit();");



}
MailWidget::~MailWidget()
{
    delete verticalLayout;
    delete webView;
    delete tableWidget;
}

void MailWidget::changeEvent(QEvent *e)
{

}



