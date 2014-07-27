#include "loginform.h"
#include "ui_loginform.h"
#include "QDebug"

const unsigned char cryptoChar[] = {0x11, 0x13, 0x17, 0x19, 0x23, 0x29, 0x31, 0x37, 0x41, 0x43, 0x47, 0x53, 0x59, 0x61 };


LoginForm::LoginForm(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::LoginForm)
{
    ui->setupUi(this);

    ui->usernamefield->setText("e0800850");
    ui->passwordfield->setText("1Wolexzo");

    ui->usernamefield->setFocus(Qt::OtherFocusReason);
    _settings = new QSettings(QSettings::defaultFormat(), QSettings::UserScope, "winhalive", "login");
    if(_settings->contains("application/username") && (_settings->contains("application/password"))){

        QString username =  _settings->value("application/username").toString();
        QByteArray password =  _settings->value("application/password").toByteArray();

        ui->usernamefield->setText(username);
        ui->passwordfield->setText(decryptPassword(password));
        ui->checkBox->setChecked(true);
    }
}


QByteArray decryptPassword(QByteArray tmpPass){
    QByteArray roastedPass;
    for ( int i = 0; i < tmpPass.length(); i++ )
        roastedPass[i] = tmpPass.at(i) ^ cryptoChar[i];
     return roastedPass;
}

 // Encrypt and save password
QByteArray encryptPassword(QString passwd){
    QByteArray roastedPass;
    for ( int i = 0; i < passwd.length(); i++ )
        roastedPass[i] = passwd.at(i).unicode() ^ cryptoChar[i];
    return roastedPass;

}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void LoginForm::on_pushButton_clicked()
{
    QString uname = ui->usernamefield->text();
    QString pword = ui->passwordfield->text();

    if(ui->checkBox->isChecked() ){

        _settings->setValue("application/username",uname);
        _settings->setValue("application/password",encryptPassword( pword));

    }

    emit loginDone(uname,pword);



}

void LoginForm::on_passwordfield_returnPressed()
{
    on_pushButton_clicked();

}


