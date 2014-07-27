#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!QSslSocket::supportsSsl()) {
        QMessageBox::information(0, "Secure Socket Client",
                                 "This system does not support OpenSSL.");
        return -1;
    }
    MainWindow w;
    #if defined(Q_WS_S60)
     w.showMaximized();
    #else
        w.show();
    #endif
    return a.exec();
}
