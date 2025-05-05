/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QPushButton *logbtnok;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *loglabname;
    QLineEdit *logeditinput;
    QLabel *loglabpass;
    QLineEdit *logeditpass;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(429, 300);
        logbtnok = new QPushButton(LoginDialog);
        logbtnok->setObjectName("logbtnok");
        logbtnok->setGeometry(QRect(140, 180, 141, 31));
        widget = new QWidget(LoginDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(90, 60, 261, 91));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        loglabname = new QLabel(widget);
        loglabname->setObjectName("loglabname");

        gridLayout->addWidget(loglabname, 0, 0, 1, 1);

        logeditinput = new QLineEdit(widget);
        logeditinput->setObjectName("logeditinput");
        logeditinput->setMaxLength(11);

        gridLayout->addWidget(logeditinput, 0, 1, 1, 1);

        loglabpass = new QLabel(widget);
        loglabpass->setObjectName("loglabpass");

        gridLayout->addWidget(loglabpass, 1, 0, 1, 1);

        logeditpass = new QLineEdit(widget);
        logeditpass->setObjectName("logeditpass");
        logeditpass->setMaxLength(8);

        gridLayout->addWidget(logeditpass, 1, 1, 1, 1);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        logbtnok->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        loglabname->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215/\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        loglabpass->setText(QCoreApplication::translate("LoginDialog", "\345\257\206              \347\240\201\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
