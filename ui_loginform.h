/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created: Sat 22. Jan 10:21:59 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginForm
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *usernamelabel;
    QLineEdit *usernamefield;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passwordLabel;
    QLineEdit *passwordfield;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName(QString::fromUtf8("LoginForm"));
        LoginForm->resize(320, 480);
        LoginForm->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(LoginForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 188, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        usernamelabel = new QLabel(LoginForm);
        usernamelabel->setObjectName(QString::fromUtf8("usernamelabel"));
        usernamelabel->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(usernamelabel);

        usernamefield = new QLineEdit(LoginForm);
        usernamefield->setObjectName(QString::fromUtf8("usernamefield"));

        horizontalLayout->addWidget(usernamefield);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 45, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        passwordLabel = new QLabel(LoginForm);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        horizontalLayout_2->addWidget(passwordLabel);

        passwordfield = new QLineEdit(LoginForm);
        passwordfield->setObjectName(QString::fromUtf8("passwordfield"));
        passwordfield->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText);
        passwordfield->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(passwordfield);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 44, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton = new QPushButton(LoginForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        checkBox = new QCheckBox(LoginForm);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);

        verticalSpacer_4 = new QSpacerItem(20, 45, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

#ifndef QT_NO_SHORTCUT
        usernamelabel->setBuddy(usernamefield);
        passwordLabel->setBuddy(passwordfield);
#endif // QT_NO_SHORTCUT

        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QWidget *LoginForm)
    {
        LoginForm->setWindowTitle(QApplication::translate("LoginForm", "Form", 0, QApplication::UnicodeUTF8));
        usernamelabel->setText(QApplication::translate("LoginForm", "UserName", 0, QApplication::UnicodeUTF8));
        passwordLabel->setText(QApplication::translate("LoginForm", "Password", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("LoginForm", "Log&in", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("LoginForm", "Save Password", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
