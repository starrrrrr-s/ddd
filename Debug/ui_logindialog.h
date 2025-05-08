/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_login;
    QPushButton *pushButton_register;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_message;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(250, 140);
        LoginDialog->setMinimumSize(QSize(0, 140));
        LoginDialog->setMaximumSize(QSize(16777215, 140));
        LoginDialog->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        gridLayout = new QGridLayout(LoginDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        gridLayout->setVerticalSpacing(2);
        gridLayout->setContentsMargins(9, 25, 14, 21);
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label = new QLabel(LoginDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        lineEdit_username = new QLineEdit(LoginDialog);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));
        lineEdit_username->setMaxLength(32);

        gridLayout->addWidget(lineEdit_username, 0, 2, 1, 1);

        lineEdit_password = new QLineEdit(LoginDialog);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setMaxLength(128);
        lineEdit_password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_password, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_login = new QPushButton(LoginDialog);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_login->sizePolicy().hasHeightForWidth());
        pushButton_login->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_login);

        pushButton_register = new QPushButton(LoginDialog);
        pushButton_register->setObjectName(QStringLiteral("pushButton_register"));
        sizePolicy.setHeightForWidth(pushButton_register->sizePolicy().hasHeightForWidth());
        pushButton_register->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_register);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 3, 1, 1, 2);

        label_message = new QLabel(LoginDialog);
        label_message->setObjectName(QStringLiteral("label_message"));
        label_message->setStyleSheet(QStringLiteral("color:red;"));

        gridLayout->addWidget(label_message, 2, 1, 1, 2);


        retranslateUi(LoginDialog);

        pushButton_login->setDefault(true);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Login", nullptr));
        label_2->setText(QApplication::translate("LoginDialog", "Password:", nullptr));
        label->setText(QApplication::translate("LoginDialog", "Username:", nullptr));
        pushButton_login->setText(QApplication::translate("LoginDialog", "Login", nullptr));
        pushButton_register->setText(QApplication::translate("LoginDialog", "Register", nullptr));
        label_message->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
