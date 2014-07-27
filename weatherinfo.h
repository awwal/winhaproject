#ifndef WEATHERINFO_H
#define WEATHERINFO_H
#include <QWidget>
#include<QNetworkAccessManager>
#include <QDebug>
#include <QTemporaryFile>
#include <QFile>
#include <QMessageBox>
#include <QWidget>
#include <QtNetwork>
#include <QXmlStreamReader>
#include <QtXml/QXmlStreamReader>
#include <QDomElement>
#include <QXmlDefaultHandler>
#include <QString>

class WeatherInfo : public QWidget
{
    Q_OBJECT
public:
    explicit WeatherInfo(QWidget *parent = 0);
    QString getTemp();
    QString getCondition();

signals:

    void valuesReady(QString temp, QString cond);

private slots:
    void handleNetworkData(QNetworkReply *networkReply);


private:
    QString temp, condition;
    QNetworkAccessManager networkManager;


};

#endif // WEATHERINFO_H
