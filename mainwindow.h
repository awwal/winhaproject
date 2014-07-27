#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginform.h"
#include "portalwidget.h"
#include "mailwidget.h"
#include "QWebView"
#include "winhawidget.h"
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    //    QWebView* webView;
    LoginForm* loginwidget;
    MailWidget* mailwidget ;
    PortalWidget* portalwidget;
    Winhawidget* winhawidget;
    QString _userName, _passWord;
    QAction* exit;
    QAction* about;

    QAction* viewMail;
    QAction* viewPortal;
    QAction* viewWinha;


    void setMenuState(bool userHaslogin);
    void addmenu();
private slots:
    void onAboutClicked();

    void on_backButton_clicked();
    void on_nextButton_clicked();

    void setCredentials(QString username, QString password);
    void  showWinha();
    void showWebmail();
    void showPortal();
    void    presentWidgetIndex(int i);
    void    showFooter(bool state);
    void mailWidgetDone(bool state);
    void portalWidgetDone(bool state);
    void winhaWidgetDone(bool state);
    void setWeather(QString temp, QString cond);

};

#endif // MAINWINDOW_H
