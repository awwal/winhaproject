/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created: Thu Dec 23 15:06:07 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Winhawindow
{
public:
    QHBoxLayout *horizontalLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QLabel *tempLabel;
    QSpacerItem *horizontalSpacer_5;
    QFormLayout *formLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLineEdit *passwordField;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *loginBtn;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *nameField;
    QSpacerItem *verticalSpacer_2;
    QWidget *page3;
    QWidget *page2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *upperLay;
    QProgressBar *progressBar;
    QLabel *statusLabel;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *backButton;
    QPushButton *exportBtn;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *bottomLay;
    QTableWidget *tableWidget;
    QHBoxLayout *lineEditsLay;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *tnuEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *gpaEdit;

    void setupUi(QWidget *Winhawindow)
    {
        if (Winhawindow->objectName().isEmpty())
            Winhawindow->setObjectName(QString::fromUtf8("Winhawindow"));
        Winhawindow->resize(353, 500);
        Winhawindow->setWindowTitle(QString::fromUtf8("WinhaLive"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/puvicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Winhawindow->setWindowIcon(icon);
        Winhawindow->setWindowFilePath(QString::fromUtf8(""));
        horizontalLayout_3 = new QHBoxLayout(Winhawindow);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        stackedWidget = new QStackedWidget(Winhawindow);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        page1->setAutoFillBackground(false);
        verticalLayout_3 = new QVBoxLayout(page1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        tempLabel = new QLabel(page1);
        tempLabel->setObjectName(QString::fromUtf8("tempLabel"));

        verticalLayout->addWidget(tempLabel);

        horizontalSpacer_5 = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_5);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(page1);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::FieldRole, verticalSpacer);

        label_2 = new QLabel(page1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        passwordField = new QLineEdit(page1);
        passwordField->setObjectName(QString::fromUtf8("passwordField"));
        passwordField->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, passwordField);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        loginBtn = new QPushButton(page1);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        loginBtn->setEnabled(true);

        horizontalLayout->addWidget(loginBtn);

        horizontalSpacer_2 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        formLayout->setLayout(5, QFormLayout::SpanningRole, horizontalLayout);

        nameField = new QLineEdit(page1);
        nameField->setObjectName(QString::fromUtf8("nameField"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameField);

        verticalSpacer_2 = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(4, QFormLayout::FieldRole, verticalSpacer_2);


        verticalLayout->addLayout(formLayout);


        verticalLayout_3->addLayout(verticalLayout);

        stackedWidget->addWidget(page1);
        page3 = new QWidget();
        page3->setObjectName(QString::fromUtf8("page3"));
        stackedWidget->addWidget(page3);
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        verticalLayout_2 = new QVBoxLayout(page2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        upperLay = new QVBoxLayout();
        upperLay->setSpacing(6);
        upperLay->setObjectName(QString::fromUtf8("upperLay"));
        progressBar = new QProgressBar(page2);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        upperLay->addWidget(progressBar);

        statusLabel = new QLabel(page2);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));

        upperLay->addWidget(statusLabel);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        backButton = new QPushButton(page2);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        horizontalLayout_8->addWidget(backButton);

        exportBtn = new QPushButton(page2);
        exportBtn->setObjectName(QString::fromUtf8("exportBtn"));

        horizontalLayout_8->addWidget(exportBtn);

        horizontalSpacer_4 = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        upperLay->addLayout(horizontalLayout_8);


        verticalLayout_2->addLayout(upperLay);

        bottomLay = new QVBoxLayout();
        bottomLay->setSpacing(6);
        bottomLay->setObjectName(QString::fromUtf8("bottomLay"));
        tableWidget = new QTableWidget(page2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        bottomLay->addWidget(tableWidget);

        lineEditsLay = new QHBoxLayout();
        lineEditsLay->setSpacing(6);
        lineEditsLay->setObjectName(QString::fromUtf8("lineEditsLay"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(page2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        tnuEdit = new QLineEdit(page2);
        tnuEdit->setObjectName(QString::fromUtf8("tnuEdit"));

        horizontalLayout_2->addWidget(tnuEdit);


        lineEditsLay->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(page2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        gpaEdit = new QLineEdit(page2);
        gpaEdit->setObjectName(QString::fromUtf8("gpaEdit"));

        horizontalLayout_6->addWidget(gpaEdit);


        lineEditsLay->addLayout(horizontalLayout_6);


        bottomLay->addLayout(lineEditsLay);


        verticalLayout_2->addLayout(bottomLay);

        stackedWidget->addWidget(page2);

        horizontalLayout_3->addWidget(stackedWidget);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(nameField);
        label_2->setBuddy(passwordField);
        label_3->setBuddy(tnuEdit);
        label_4->setBuddy(gpaEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(Winhawindow);
        QObject::connect(nameField, SIGNAL(textChanged(QString)), Winhawindow, SLOT(setWindowTitle(QString)));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Winhawindow);
    } // setupUi

    void retranslateUi(QWidget *Winhawindow)
    {
        tempLabel->setText(QApplication::translate("Winhawindow", "Temp:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Winhawindow", "UserName", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Winhawindow", "Password", 0, QApplication::UnicodeUTF8));
        loginBtn->setText(QApplication::translate("Winhawindow", "&Login", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QApplication::translate("Winhawindow", "Begin", 0, QApplication::UnicodeUTF8));
        backButton->setText(QApplication::translate("Winhawindow", "B&ack", 0, QApplication::UnicodeUTF8));
        exportBtn->setText(QApplication::translate("Winhawindow", "Export", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Winhawindow", "TNU", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Winhawindow", "CGPA", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Winhawindow);
    } // retranslateUi

};

namespace Ui {
    class Winhawindow: public Ui_Winhawindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
