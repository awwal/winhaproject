/********************************************************************************
** Form generated from reading UI file 'exportoption.ui'
**
** Created: Thu Dec 23 15:06:07 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTOPTION_H
#define UI_EXPORTOPTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExportOption
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *ExportOption)
    {
        if (ExportOption->objectName().isEmpty())
            ExportOption->setObjectName(QString::fromUtf8("ExportOption"));
        ExportOption->resize(393, 98);
        buttonBox = new QDialogButtonBox(ExportOption);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-80, 60, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(ExportOption);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 304, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton1 = new QRadioButton(layoutWidget);
        buttonGroup = new QButtonGroup(ExportOption);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioButton1);
        radioButton1->setObjectName(QString::fromUtf8("radioButton1"));

        horizontalLayout->addWidget(radioButton1);

        radioButton2 = new QRadioButton(layoutWidget);
        buttonGroup->addButton(radioButton2);
        radioButton2->setObjectName(QString::fromUtf8("radioButton2"));

        horizontalLayout->addWidget(radioButton2);

        radioButton3 = new QRadioButton(layoutWidget);
        radioButton3->setObjectName(QString::fromUtf8("radioButton3"));

        horizontalLayout->addWidget(radioButton3);


        retranslateUi(ExportOption);
        QObject::connect(buttonBox, SIGNAL(accepted()), ExportOption, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ExportOption, SLOT(reject()));

        QMetaObject::connectSlotsByName(ExportOption);
    } // setupUi

    void retranslateUi(QDialog *ExportOption)
    {
        ExportOption->setWindowTitle(QApplication::translate("ExportOption", "Dialog", 0, QApplication::UnicodeUTF8));
        radioButton1->setText(QApplication::translate("ExportOption", "As Pdf", 0, QApplication::UnicodeUTF8));
        radioButton2->setText(QApplication::translate("ExportOption", "As Text File", 0, QApplication::UnicodeUTF8));
        radioButton3->setText(QApplication::translate("ExportOption", "As CSV File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExportOption: public Ui_ExportOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTOPTION_H
