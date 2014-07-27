#include "portalwidget.h"

#include "QDebug"
#include <QtGui>
#include <QtWebKit>
#include <QMap>
#define URL "https://portal.puv.fi/"



QString toString(int i){

    QString str = QString::number(i,10);
    return str;

}

PortalWidget::PortalWidget(QProgressBar* bar,QWidget *parent) :  QWidget(parent)
{

 this->progressBar=bar;


}

void PortalWidget::restart(){

    this->webView=new QWebView();
     progressBar->setValue(0);
    tableWidget = new QTableWidget();
    verticalLayout = new QVBoxLayout(this);
    verticalLayout->addWidget(tableWidget);

}

void PortalWidget::initSession(QString username, QString password){


    userName=username;
    passWord=password;

    webView->load(QUrl(URL));
    connect(webView, SIGNAL(loadFinished(bool)),this, SLOT(loginPage(bool)));
    connect(webView, SIGNAL(loadProgress(int)),this->progressBar, SLOT(setValue(int)));



}

QWebElement PortalWidget::document() const {
    return webView->page()->mainFrame()->documentElement();
}

void PortalWidget::resetProgressBar(){
    webView->disconnect();
    progressBar->setValue(0);
    connect(webView, SIGNAL(loadProgress(int)), progressBar, SLOT(setValue(int)));
}
void PortalWidget::loginPage(bool ok){
    if(!ok){
        emit statusUpdate("Problem with page");
         emit doneFinally(false);
        return;
    }


    emit statusUpdate("Attempting to Login");
    resetProgressBar();

    connect(webView, SIGNAL(loadFinished(bool)),this, SLOT(portalPage(bool)));


    QWebElement forme=  document().findFirst("form[id=login]");
    QWebElement we=  forme.findFirst("input[id=login_username]");
    we.setAttribute("value",userName);
    QWebElement pe= forme.findFirst("input[id=login_password]");
    pe.setAttribute("value",passWord);

    forme.evaluateJavaScript("this.submit();");



}

QDate* parseDate(QString link){



    QStringList list= link.split("&amp;", QString::KeepEmptyParts,Qt::CaseSensitive);

    QString course = list[1];



    QString day= list[2];
    day = day.remove("cal_d=",Qt::CaseSensitive);

    QString month= list[3];
    month = month.remove("cal_m=",Qt::CaseSensitive);


    QString year=list[4];
    QStringList yersplit = year.split('#');
    year=yersplit[0];
    year = year.remove("cal_y=",Qt::CaseSensitive);

    bool ok;
    int d = day.toInt(&ok,10);
    int m= month.toInt(&ok,10);
    int y = year.toInt(&ok,10);

    QDate* date = new QDate(y,m,d);

    return date;

}


void PortalWidget::createTable(QMap<QString,QDate*> map){
    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(2);

    QTableWidgetItem *headerItem = new QTableWidgetItem();
    headerItem->setText("EVENT");
    headerItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter | Qt::AlignHCenter);
    tableWidget->setHorizontalHeaderItem(0, headerItem);

    headerItem = new QTableWidgetItem();
    headerItem->setText("DATE");
    headerItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter | Qt::AlignHCenter);
    tableWidget->setHorizontalHeaderItem(1, headerItem);

    int rowNo=0;
    QMap<QString, QDate*>::const_iterator i;
    for (i = map.constBegin(); i != map.constEnd(); ++i)
    {
//        qDebug() << i.key() << ": " << i.value() ;
        QDate* d = i.value();
        QString dateStr = (*d).toString();

        tableWidget->insertRow(tableWidget->rowCount());//add one more row

        QTableWidgetItem *itemCol = new QTableWidgetItem( i.key(),0);
        if(QDate::currentDate()==(*d)){
            itemCol->setBackgroundColor(QColor("red"));
        }
        itemCol->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter );

        tableWidget->setItem(rowNo,0, itemCol);

        itemCol = new QTableWidgetItem(dateStr,0);
        itemCol->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter | Qt::AlignHCenter);
        tableWidget->setItem(rowNo,1, itemCol);

        rowNo++;
    }


    tableWidget->alternatingRowColors();

    tableWidget->setColumnWidth(0,2*tableWidget->size().width()/3);// two-third
    tableWidget->setColumnWidth(1,tableWidget->size().width()/3-10);//one-third
}


void PortalWidget::calendarPage(bool ok){

    if(!ok){
        qDebug()<<"problem cal";
         emit doneFinally(false);
        return;
    }

   emit statusUpdate("Setting up month calendar");
    QMap<QString,QDate*> events;
    QString title,link;
    QWebElementCollection unseenEl= document().findAll("li.event_course a");
    foreach(QWebElement elem, unseenEl ){

        title=elem.toPlainText();
        link=elem.toOuterXml();

        QDate* date = parseDate(link);
        events.insert(title,date);


    }

    createTable(events);

    progressBar->setValue(0);
     emit doneFinally(true);
     emit statusUpdate("Done");

}





void PortalWidget::portalPage(bool ok){

    //we are in !!:D

    if(!ok){
        return;
    }
     emit statusUpdate("Login Sucessful");

    resetProgressBar();

    connect(webView, SIGNAL(loadFinished(bool)),this, SLOT(calendarPage(bool)));

    QString calendarUrl = "https://portal.puv.fi/calendar/view.php?view=month&amp;course=1";
    QDate today =  QDate::currentDate ();
    int day = today.day();

    calendarUrl.append("&amp;cal_d="+toString(day));
    int month = today.month();
    calendarUrl.append("&amp;cal_m="+toString(month));
    int year = today.year();    
    calendarUrl.append("&amp;cal_y="+toString(year));   
    webView->setUrl(calendarUrl);

}
PortalWidget::~PortalWidget()
{
    delete verticalLayout;
    delete webView;
    delete tableWidget;

}

void PortalWidget::changeEvent(QEvent *e)
{

}
