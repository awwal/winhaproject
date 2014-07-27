#include "weatherinfo.h"

#define VAASA_URL "http://weather.yahooapis.com/forecastrss?w=574450&u=c"

WeatherInfo::WeatherInfo(QWidget *parent) :
        QWidget(parent)
{


    connect(&networkManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(handleNetworkData(QNetworkReply*)));

    QUrl url(VAASA_URL);
    networkManager.get(QNetworkRequest(url));



}
QString WeatherInfo::getTemp(){
    return temp;
}
QString WeatherInfo:: getCondition(){
    return condition;
}

void WeatherInfo::handleNetworkData(QNetworkReply *networkReply)
{

    if (!networkReply->error()) {
        QByteArray response(networkReply->readAll());

        QTemporaryFile tempfile;
        if (tempfile.open()) {
            tempfile.write(response);
            tempfile.flush();

        }
        tempfile.close();
        QFile file(tempfile.fileName());
//        qDebug()<<file.exists();
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::critical(this,
                                  "Reading weather info",
                                  "Couldn't open the file downloaded",
                                  QMessageBox::Ok);
            return;
        }


        QString errorStr;
        int errorLine;
        int errorColumn;

        QDomDocument doc;
        if (!doc.setContent(&file, false, &errorStr, &errorLine,   &errorColumn)) {
            qDebug() << "Error: Parse error at line " << errorLine << ", "
                    << "column " << errorColumn << ": "
                    << qPrintable(errorStr);
            return;
        }
        QDomElement root = doc.documentElement();
        if (root.tagName() != "rss") {
            qDebug()<<"not rss";
            return;
        }

        QDomElement channelEl = root.firstChildElement();
        QDomElement itemEl = channelEl.firstChildElement("item");
        QDomElement weatherEl  = itemEl.firstChildElement("yweather:condition");

        temp = weatherEl.attribute("temp");
        condition = weatherEl.attribute("text");
        valuesReady(temp,condition);

    }
    networkReply->deleteLater();

}
