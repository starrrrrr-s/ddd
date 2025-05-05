/********************************************************************************
** Form generated from reading UI file 'RegisterDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QPushButton *btnsubmit;
    QLabel *labps;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *labname;
    QLineEdit *editname;
    QLabel *labnum;
    QLineEdit *editnum;
    QLabel *labpass;
    QLineEdit *editpass;
    QLabel *labpass2;
    QLineEdit *editconfirm;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName("RegisterDialog");
        RegisterDialog->resize(400, 300);
        btnsubmit = new QPushButton(RegisterDialog);
        btnsubmit->setObjectName("btnsubmit");
        btnsubmit->setGeometry(QRect(140, 190, 80, 24));
        labps = new QLabel(RegisterDialog);
        labps->setObjectName("labps");
        labps->setGeometry(QRect(20, 230, 361, 16));
        widget = new QWidget(RegisterDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 40, 281, 131));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labname = new QLabel(widget);
        labname->setObjectName("labname");

        gridLayout->addWidget(labname, 0, 0, 1, 1);

        editname = new QLineEdit(widget);
        editname->setObjectName("editname");
        editname->setMaxLength(11);

        gridLayout->addWidget(editname, 0, 1, 1, 1);

        labnum = new QLabel(widget);
        labnum->setObjectName("labnum");

        gridLayout->addWidget(labnum, 1, 0, 1, 1);

        editnum = new QLineEdit(widget);
        editnum->setObjectName("editnum");
        editnum->setMaxLength(11);

        gridLayout->addWidget(editnum, 1, 1, 1, 1);

        labpass = new QLabel(widget);
        labpass->setObjectName("labpass");

        gridLayout->addWidget(labpass, 2, 0, 1, 1);

        editpass = new QLineEdit(widget);
        editpass->setObjectName("editpass");
        editpass->setMaxLength(8);

        gridLayout->addWidget(editpass, 2, 1, 1, 1);

        labpass2 = new QLabel(widget);
        labpass2->setObjectName("labpass2");

        gridLayout->addWidget(labpass2, 3, 0, 1, 1);

        editconfirm = new QLineEdit(widget);
        editconfirm->setObjectName("editconfirm");
        editconfirm->setMaxLength(8);

        gridLayout->addWidget(editconfirm, 3, 1, 1, 1);

#if QT_CONFIG(shortcut)
        labname->setBuddy(editname);
        labnum->setBuddy(editnum);
        labpass->setBuddy(editpass);
        labpass2->setBuddy(editpass);
#endif // QT_CONFIG(shortcut)

        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QCoreApplication::translate("RegisterDialog", "Dialog", nullptr));
        btnsubmit->setText(QCoreApplication::translate("RegisterDialog", "\346\217\220\344\272\244", nullptr));
        labps->setText(QCoreApplication::translate("RegisterDialog", "\346\263\250\346\204\217\357\274\232\347\224\250\346\210\267\345\220\215\346\234\200\351\225\27711\344\275\215\357\274\214\345\257\206\347\240\201\346\234\200\351\225\2778\344\275\215\357\274\214\346\211\213\346\234\272\345\217\267\350\257\267\350\276\223\345\205\24511\344\275\215\346\255\243\347\241\256\346\240\274\345\274\217", nullptr));
        labname->setText(QCoreApplication::translate("RegisterDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        labnum->setText(QCoreApplication::translate("RegisterDialog", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        labpass->setText(QCoreApplication::translate("RegisterDialog", "\345\257\206   \347\240\201\357\274\232", nullptr));
        labpass2->setText(QCoreApplication::translate("RegisterDialog", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
