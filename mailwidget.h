#ifndef MAINWIDGET_H
#define MAINWIDGET_H


#include <QWidget>
#include <QWebView>
#include <QVBoxLayout>
#include "QTableWidget"
#include <QtGui/QWidget>
#include <QtGui/QVBoxLayout>
#include <QProgressBar>


class MailWidget : public QWidget {
    Q_OBJECT
public:
    MailWidget(QProgressBar* bar, QWidget *parent = 0 );
    void initSession(QString,QString);

    ~MailWidget();

protected:
    void changeEvent(QEvent *e);

private:
    void restart();

    QProgressBar* progressBar;
    QWebView *webView;
    QTableWidget *tableWidget;
    QWebElement document() const;
    void createTable(QStringList& tableHeader, QList<QStringList>& content)  ;
    QString userName ;
    QString passWord;
    QVBoxLayout *verticalLayout;
    void resetProgressBar();

private slots:

    void loginPage(bool ok);
    void mailPage(bool ok);


signals:
    void statusUpdate(QString value);
    void doneFinally(bool);


};

#endif
