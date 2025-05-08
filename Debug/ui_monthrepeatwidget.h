/********************************************************************************
** Form generated from reading UI file 'monthrepeatwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTHREPEATWIDGET_H
#define UI_MONTHREPEATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MonthRepeatWidget
{
public:
    QGridLayout *gridLayout;
    QRadioButton *radioButton_day;
    QRadioButton *radioButton_weekday;
    QComboBox *comboBox_day;
    QComboBox *comboBox_weekday_1;
    QComboBox *comboBox_weekday_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *MonthRepeatWidget)
    {
        if (MonthRepeatWidget->objectName().isEmpty())
            MonthRepeatWidget->setObjectName(QStringLiteral("MonthRepeatWidget"));
        MonthRepeatWidget->resize(254, 64);
        gridLayout = new QGridLayout(MonthRepeatWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        radioButton_day = new QRadioButton(MonthRepeatWidget);
        radioButton_day->setObjectName(QStringLiteral("radioButton_day"));
        radioButton_day->setChecked(true);

        gridLayout->addWidget(radioButton_day, 0, 0, 1, 1);

        radioButton_weekday = new QRadioButton(MonthRepeatWidget);
        radioButton_weekday->setObjectName(QStringLiteral("radioButton_weekday"));

        gridLayout->addWidget(radioButton_weekday, 1, 0, 1, 1);

        comboBox_day = new QComboBox(MonthRepeatWidget);
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->addItem(QString());
        comboBox_day->setObjectName(QStringLiteral("comboBox_day"));

        gridLayout->addWidget(comboBox_day, 0, 1, 1, 1);

        comboBox_weekday_1 = new QComboBox(MonthRepeatWidget);
        comboBox_weekday_1->addItem(QString());
        comboBox_weekday_1->addItem(QString());
        comboBox_weekday_1->addItem(QString());
        comboBox_weekday_1->addItem(QString());
        comboBox_weekday_1->addItem(QString());
        comboBox_weekday_1->addItem(QString());
        comboBox_weekday_1->setObjectName(QStringLiteral("comboBox_weekday_1"));

        gridLayout->addWidget(comboBox_weekday_1, 1, 1, 1, 1);

        comboBox_weekday_2 = new QComboBox(MonthRepeatWidget);
        comboBox_weekday_2->setObjectName(QStringLiteral("comboBox_weekday_2"));

        gridLayout->addWidget(comboBox_weekday_2, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 2, 1);


        retranslateUi(MonthRepeatWidget);

        QMetaObject::connectSlotsByName(MonthRepeatWidget);
    } // setupUi

    void retranslateUi(QWidget *MonthRepeatWidget)
    {
        radioButton_day->setText(QApplication::translate("MonthRepeatWidget", "&On", nullptr));
        radioButton_weekday->setText(QApplication::translate("MonthRepeatWidget", "&At the", nullptr));
        comboBox_day->setItemText(0, QApplication::translate("MonthRepeatWidget", "1st", nullptr));
        comboBox_day->setItemText(1, QApplication::translate("MonthRepeatWidget", "2nd", nullptr));
        comboBox_day->setItemText(2, QApplication::translate("MonthRepeatWidget", "3rd", nullptr));
        comboBox_day->setItemText(3, QApplication::translate("MonthRepeatWidget", "4th", nullptr));
        comboBox_day->setItemText(4, QApplication::translate("MonthRepeatWidget", "5th", nullptr));
        comboBox_day->setItemText(5, QApplication::translate("MonthRepeatWidget", "6th", nullptr));
        comboBox_day->setItemText(6, QApplication::translate("MonthRepeatWidget", "7th", nullptr));
        comboBox_day->setItemText(7, QApplication::translate("MonthRepeatWidget", "8th", nullptr));
        comboBox_day->setItemText(8, QApplication::translate("MonthRepeatWidget", "9th", nullptr));
        comboBox_day->setItemText(9, QApplication::translate("MonthRepeatWidget", "10th", nullptr));
        comboBox_day->setItemText(10, QApplication::translate("MonthRepeatWidget", "11th", nullptr));
        comboBox_day->setItemText(11, QApplication::translate("MonthRepeatWidget", "12th", nullptr));
        comboBox_day->setItemText(12, QApplication::translate("MonthRepeatWidget", "13th", nullptr));
        comboBox_day->setItemText(13, QApplication::translate("MonthRepeatWidget", "14th", nullptr));
        comboBox_day->setItemText(14, QApplication::translate("MonthRepeatWidget", "15th", nullptr));
        comboBox_day->setItemText(15, QApplication::translate("MonthRepeatWidget", "16th", nullptr));
        comboBox_day->setItemText(16, QApplication::translate("MonthRepeatWidget", "17th", nullptr));
        comboBox_day->setItemText(17, QApplication::translate("MonthRepeatWidget", "18th", nullptr));
        comboBox_day->setItemText(18, QApplication::translate("MonthRepeatWidget", "19th", nullptr));
        comboBox_day->setItemText(19, QApplication::translate("MonthRepeatWidget", "20th", nullptr));
        comboBox_day->setItemText(20, QApplication::translate("MonthRepeatWidget", "21st", nullptr));
        comboBox_day->setItemText(21, QApplication::translate("MonthRepeatWidget", "22nd", nullptr));
        comboBox_day->setItemText(22, QApplication::translate("MonthRepeatWidget", "23rd", nullptr));
        comboBox_day->setItemText(23, QApplication::translate("MonthRepeatWidget", "24th", nullptr));
        comboBox_day->setItemText(24, QApplication::translate("MonthRepeatWidget", "25th", nullptr));
        comboBox_day->setItemText(25, QApplication::translate("MonthRepeatWidget", "26th", nullptr));
        comboBox_day->setItemText(26, QApplication::translate("MonthRepeatWidget", "27th", nullptr));
        comboBox_day->setItemText(27, QApplication::translate("MonthRepeatWidget", "28th", nullptr));
        comboBox_day->setItemText(28, QApplication::translate("MonthRepeatWidget", "29th", nullptr));
        comboBox_day->setItemText(29, QApplication::translate("MonthRepeatWidget", "20th", nullptr));
        comboBox_day->setItemText(30, QApplication::translate("MonthRepeatWidget", "31st", nullptr));
        comboBox_day->setItemText(31, QApplication::translate("MonthRepeatWidget", "the last day", nullptr));

        comboBox_weekday_1->setItemText(0, QApplication::translate("MonthRepeatWidget", "first", nullptr));
        comboBox_weekday_1->setItemText(1, QApplication::translate("MonthRepeatWidget", "second", nullptr));
        comboBox_weekday_1->setItemText(2, QApplication::translate("MonthRepeatWidget", "third", nullptr));
        comboBox_weekday_1->setItemText(3, QApplication::translate("MonthRepeatWidget", "fourth", nullptr));
        comboBox_weekday_1->setItemText(4, QApplication::translate("MonthRepeatWidget", "fifth", nullptr));
        comboBox_weekday_1->setItemText(5, QApplication::translate("MonthRepeatWidget", "last", nullptr));

        Q_UNUSED(MonthRepeatWidget);
    } // retranslateUi

};

namespace Ui {
    class MonthRepeatWidget: public Ui_MonthRepeatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTHREPEATWIDGET_H
