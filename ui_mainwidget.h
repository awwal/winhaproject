/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created: Thu Dec 23 14:39:04 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_Mainwidget
{
public:
    QTableWidget *tableWidget;
    QWebView *webView;

    void setupUi(QWidget *Mainwidget)
    {
        if (Mainwidget->objectName().isEmpty())
            Mainwidget->setObjectName(QString::fromUtf8("Mainwidget"));
        Mainwidget->resize(621, 400);
        tableWidget = new QTableWidget(Mainwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 200, 591, 191));
        webView = new QWebView(Mainwidget);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setGeometry(QRect(10, 10, 580, 161));
        webView->setUrl(QUrl("about:blank"));

        retranslateUi(Mainwidget);

        QMetaObject::connectSlotsByName(Mainwidget);
    } // setupUi

    void retranslateUi(QWidget *Mainwidget)
    {
        Mainwidget->setWindowTitle(QApplication::translate("Mainwidget", "Mainwidget", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Mainwidget: public Ui_Mainwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
