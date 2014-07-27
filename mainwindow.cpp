#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QDebug"
const int  LOGIN_WIDTH =350;
MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    addmenu();
    showFooter(false);
    loginwidget = new LoginForm(0);//index 0
    mailwidget = new MailWidget(ui->progressBar,this->centralWidget()); //index 1
    portalwidget = new PortalWidget(ui->progressBar,this->centralWidget());//index 2
    winhawidget = new Winhawidget(ui->progressBar,this->centralWidget());//index 3


    ui->stackedWidget->addWidget(loginwidget);
    ui->stackedWidget->addWidget(mailwidget);
    ui->stackedWidget->addWidget(portalwidget);
    ui->stackedWidget->addWidget(winhawidget);


    //start with the login
    ui->stackedWidget->setCurrentWidget(loginwidget);
    connect(loginwidget,SIGNAL(loginDone(QString,QString)),this,SLOT(setCredentials(QString,QString)));
    connect(ui->stackedWidget,SIGNAL(currentChanged(int)),this,SLOT(presentWidgetIndex(int)));


    //    QPalette palette;
    //    palette.setBrush(this->backgroundRole(), QBrush(QImage(":/images/icons/nicevamk.png")));
    //    this->setPalette(palette);

    //
    WeatherInfo *w = new WeatherInfo(this);
    connect(w, SIGNAL(valuesReady(QString,QString)), this, SLOT(setWeather(QString,QString)));



}

void MainWindow::setMenuState(bool userHasLogin){
    viewMail->setVisible(userHasLogin);
    viewPortal->setVisible(userHasLogin);
    viewWinha->setVisible(userHasLogin);
}

void MainWindow::addmenu()
{
    exit = new QAction("Quit",this);
    about = new QAction("About",this);
    viewMail= new QAction("View &Mail",this);
    viewPortal= new QAction("View &Portal",this);
    viewWinha= new QAction("View &Grades",this);


    connect(exit, SIGNAL(triggered()), SLOT(close()) );
    connect(about, SIGNAL(triggered()), SLOT(onAboutClicked()));

    connect(viewMail, SIGNAL(triggered()), SLOT(showWebmail()));
    connect(viewPortal, SIGNAL(triggered()), SLOT(showPortal()));

    connect(viewWinha, SIGNAL(triggered()), SLOT(showWinha()));

    QMenu* menu = menuBar()->addMenu( "Actions" );

    menu->addAction(viewMail);
    menu->addAction(viewPortal);
    menu->addAction(viewWinha);
    menu->addAction( about );
    menu->addAction( exit );
    createPopupMenu();
    setMenuState(false);
}

void MainWindow::setWeather(QString temp, QString cond){
    //  176 degree symbol
    QString str = this->windowTitle()+ " Weather: " +temp + QChar(176) +"C "+ cond;
    this->setWindowTitle(str);
}


void   MainWindow:: showFooter(bool state){
    ui->backButton->setVisible(state);
    ui->progressBar->setVisible(state);
    ui->nextButton->setVisible(state);
}


void   MainWindow:: presentWidgetIndex(int i){
    qDebug()<<" widget now "<<i;
}

void MainWindow::setCredentials(QString username, QString password)
{

    if(username.isEmpty()|| password.isEmpty()){

        return;
    }

    setMenuState(true);
    _userName=username;
    _passWord=password;
    //first to show
    showWebmail();
}
void MainWindow::showPortal()
{
    this->resize(600,this->size().height());
    portalwidget->restart();
    portalwidget->initSession(_userName,_passWord);
    ui->stackedWidget->setCurrentWidget(portalwidget);
    connect(portalwidget,SIGNAL(statusUpdate(QString)),ui->statusbar,SLOT(showMessage(QString)));
}


void MainWindow::showWinha()
{
    this->resize(800,this->size().height());   
    winhawidget->setUserCredentials(_userName,_passWord);
    ui->stackedWidget->setCurrentWidget(winhawidget);
    connect(winhawidget,SIGNAL(statusUpdate(QString)),ui->statusbar,SLOT(showMessage(QString)));
    connect(winhawidget,SIGNAL(doneFinally(bool)),this,SLOT(winhaWidgetDone(bool)));

}

void MainWindow::showWebmail()
{
    this->resize(600,this->size().height()); //expand

    ui->stackedWidget->removeWidget(mailwidget);
    mailwidget = new MailWidget(ui->progressBar,this);
    ui->stackedWidget->insertWidget(1,mailwidget);
    mailwidget->initSession(_userName,_passWord);
    ui->stackedWidget->setCurrentWidget(mailwidget);
    connect(mailwidget,SIGNAL(statusUpdate(QString)),ui->statusbar,SLOT(showMessage(QString)));
    connect(mailwidget,SIGNAL(doneFinally(bool)),this,SLOT(mailWidgetDone(bool)));


}

void MainWindow::winhaWidgetDone(bool status)
{

    if(status)
        this->showMaximized();
    else {

        this->resize(LOGIN_WIDTH,this->size().height());
        ui->stackedWidget->setCurrentWidget(loginwidget);
    }

}

void MainWindow::portalWidgetDone(bool status)
{

    if(status)
        this->showMaximized();
    else {

        this->resize(LOGIN_WIDTH,this->size().height());
        ui->stackedWidget->setCurrentWidget(loginwidget);
    }

}

void MainWindow::mailWidgetDone(bool status)
{



    if(status){
        showFooter(true);
    }
    else{
        setMenuState(false);
        this->resize(LOGIN_WIDTH,this->size().height());
        ui->stackedWidget->setCurrentWidget(loginwidget);
    }

}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_nextButton_clicked()
{
    QWidget* currentWidget= ui->stackedWidget->currentWidget();

    if(currentWidget==mailwidget)
    {

        showPortal();

    }
    else if(currentWidget==portalwidget){

        ui->nextButton->setEnabled(false);
        showWinha();
    }




}

void MainWindow::on_backButton_clicked()
{
    QWidget* currentWidget= ui->stackedWidget->currentWidget();
    if(currentWidget==mailwidget)
    {
        //go back to login
        showFooter(false);
        this->resize(LOGIN_WIDTH,this->size().height());
        ui->stackedWidget->setCurrentIndex(0);

    }


    else if(currentWidget==portalwidget)
    {
        //go back to mail
        ui->stackedWidget->setCurrentIndex(1);

    }
    else if (currentWidget==winhawidget){

        //go back to portal
        ui->nextButton->setEnabled(true);
        ui->stackedWidget->setCurrentIndex(2);
    }

}


void MainWindow::onAboutClicked()
{
    QMessageBox msgBox;
    msgBox.setText("Vamk Mobile Author ( talktolawal@gmail.com 2011) ");
    msgBox.exec();
}
