#ifndef PORTALWIDGET_H
#define PORTALWIDGET_H

#include <QWidget>
#include <QWidget>
#include <QWebView>
#include <QVBoxLayout>
#include "QTableWidget"
#include <QtGui/QWidget>
#include <QtGui/QVBoxLayout>
#include <QProgressBar>

class PortalWidget : public QWidget {
    Q_OBJECT
public:
    PortalWidget(QProgressBar* bar,QWidget *parent = 0);
    ~PortalWidget();
    void initSession(QString,QString);
    void restart();
protected:
    QWebElement document() const;
    void changeEvent(QEvent *e);
    void createTable(QMap<QString,QDate*> events);


private slots:
    void loginPage(bool ok);
    void portalPage(bool ok);
    void calendarPage(bool ok);

private:
    QString userName ;
    QString passWord;
    QWebView *webView;
    QTableWidget *tableWidget;

    QProgressBar* progressBar;
    QVBoxLayout *verticalLayout;
    void resetProgressBar();
signals:
    void statusUpdate(QString value);
    void doneFinally(bool);



};

#endif // PORTALWIDGET_H
