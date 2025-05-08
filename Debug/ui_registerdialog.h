/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

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

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_password_2;
    QLabel *label_message;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_create;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QStringLiteral("RegisterDialog"));
        RegisterDialog->resize(300, 160);
        RegisterDialog->setMinimumSize(QSize(0, 160));
        RegisterDialog->setMaximumSize(QSize(16777215, 160));
        gridLayout = new QGridLayout(RegisterDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(RegisterDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(RegisterDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(RegisterDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_username = new QLineEdit(RegisterDialog);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));
        lineEdit_username->setMaxLength(32);

        gridLayout->addWidget(lineEdit_username, 0, 1, 1, 1);

        lineEdit_password = new QLineEdit(RegisterDialog);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setMaxLength(128);
        lineEdit_password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_password, 1, 1, 1, 1);

        lineEdit_password_2 = new QLineEdit(RegisterDialog);
        lineEdit_password_2->setObjectName(QStringLiteral("lineEdit_password_2"));
        lineEdit_password_2->setMaxLength(128);
        lineEdit_password_2->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_password_2, 2, 1, 1, 1);

        label_message = new QLabel(RegisterDialog);
        label_message->setObjectName(QStringLiteral("label_message"));
        label_message->setStyleSheet(QStringLiteral("color:red;"));

        gridLayout->addWidget(label_message, 3, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_create = new QPushButton(RegisterDialog);
        pushButton_create->setObjectName(QStringLiteral("pushButton_create"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_create->sizePolicy().hasHeightForWidth());
        pushButton_create->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_create);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 2);


        retranslateUi(RegisterDialog);

        pushButton_create->setDefault(true);


        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "Register", nullptr));
        label_3->setText(QApplication::translate("RegisterDialog", "Reenter Password:", nullptr));
        label->setText(QApplication::translate("RegisterDialog", "Username:", nullptr));
        label_2->setText(QApplication::translate("RegisterDialog", "Password:", nullptr));
        label_message->setText(QString());
        pushButton_create->setText(QApplication::translate("RegisterDialog", "Create Account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
