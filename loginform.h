#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QSettings>
#include <QSslSocket>

QByteArray decryptPassword(QByteArray );
QByteArray encryptPassword(QString );


namespace Ui {
    class LoginForm;
}

class LoginForm : public QWidget {
    Q_OBJECT
public:
    LoginForm(QWidget *parent = 0);
    ~LoginForm();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::LoginForm *ui;
    QSettings* _settings;

private slots:

    void on_passwordfield_returnPressed();
    void on_pushButton_clicked();


signals:
    void loginDone(QString username, QString password);

};

#endif // LOGINFORM_H
