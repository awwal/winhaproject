#ifndef WINHAWINDOW_H
#define WINHAWINDOW_H

#include <QWidget>
#include <QWebView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QWidget>
#include <QWebView>
#include <QVBoxLayout>
#include "QTableWidget"
#include <QtGui/QWidget>
#include <QtGui/QVBoxLayout>
#include <QProgressBar>
#include "gphandler.h"
#include "weatherinfo.h"
#include <QtGui/QLabel>


class Winhawidget : public QWidget {
    Q_OBJECT
public:
    Winhawidget(QProgressBar* bar,QWidget *parent = 0);
    ~Winhawidget();
    void setUserCredentials(QString,QString);
protected:
    void changeEvent(QEvent *e);

private:
    QPushButton* exportBtn;
    QWebView *webView;
    void resetProgressBar();
    void updateGP(QString credit, QString grade,QString attention);
    void createTable(QStringList& header, QList<QStringList>& content);
    QProgressBar* progressBar;
    QLineEdit *tnuEdit;
    QLineEdit *gpaEdit;
    QTableWidget *tableWidget;
    QWebElement document() const;
    GPHandler* gpHandler;

    QString userName;
    QString passWord;
    QVBoxLayout *verticalLayout;


private slots:


    void preCompletionPage(bool ok);
    void completionPage(bool ok);
    void loginPage(bool ok);
    void winhaPage(bool ok);
    void onExportBtnClicked();


signals:
    void statusUpdate(QString value);
    void doneFinally(bool);


};

#endif // WINHAWINDOW_H
