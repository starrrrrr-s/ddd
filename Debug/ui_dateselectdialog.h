/********************************************************************************
** Form generated from reading UI file 'dateselectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATESELECTDIALOG_H
#define UI_DATESELECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DateSelectDialog
{
public:
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;

    void setupUi(QDialog *DateSelectDialog)
    {
        if (DateSelectDialog->objectName().isEmpty())
            DateSelectDialog->setObjectName(QStringLiteral("DateSelectDialog"));
        DateSelectDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(DateSelectDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        calendarWidget = new QCalendarWidget(DateSelectDialog);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setFirstDayOfWeek(Qt::Monday);

        verticalLayout->addWidget(calendarWidget);


        retranslateUi(DateSelectDialog);

        QMetaObject::connectSlotsByName(DateSelectDialog);
    } // setupUi

    void retranslateUi(QDialog *DateSelectDialog)
    {
        DateSelectDialog->setWindowTitle(QApplication::translate("DateSelectDialog", "Select Date ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DateSelectDialog: public Ui_DateSelectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATESELECTDIALOG_H
