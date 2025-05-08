/********************************************************************************
** Form generated from reading UI file 'yearrepeatwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YEARREPEATWIDGET_H
#define UI_YEARREPEATWIDGET_H

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

class Ui_YearRepeatWidget
{
public:
    QGridLayout *gridLayout;
    QRadioButton *radioButton_day;
    QRadioButton *radioButton_weekday;
    QComboBox *comboBox_day;
    QComboBox *comboBox_weekday_2;
    QComboBox *comboBox_weekday_1;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox_month;

    void setupUi(QWidget *YearRepeatWidget)
    {
        if (YearRepeatWidget->objectName().isEmpty())
            YearRepeatWidget->setObjectName(QStringLiteral("YearRepeatWidget"));
        YearRepeatWidget->resize(311, 90);
        gridLayout = new QGridLayout(YearRepeatWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        radioButton_day = new QRadioButton(YearRepeatWidget);
        radioButton_day->setObjectName(QStringLiteral("radioButton_day"));
        radioButton_day->setChecked(true);

        gridLayout->addWidget(radioButton_day, 1, 1, 1, 1);

        radioButton_weekday = new QRadioButton(YearRepeatWidget);
        radioButton_weekday->setObjectName(QStringLiteral("radioButton_weekday"));

        gridLayout->addWidget(radioButton_weekday, 2, 1, 1, 1);

        comboBox_day = new QComboBox(YearRepeatWidget);
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

        gridLayout->addWidget(comboBox_day, 1, 2, 1, 1);

        comboBox_weekday_2 = new QComboBox(YearRepeatWidget);
        comboBox_weekday_2->setObjectName(QStringLiteral("comboBox_weekday_2"));

        gridLayout->addWidget(comboBox_weekday_2, 2, 3, 1, 1);

        comboBox_weekday_1 = new QComboBox(YearRepeatWidget);
        comboBox_weekday_1->addItem(QString());
        comboBox_weekday_1->addItem(QString());
        comboBox_weekday_1->addItem(QString());
        comboBox_weekday_1->addItem(QString());
        comboBox_weekday_1->addItem(QString());
        comboBox_weekday_1->addItem(QString());
        comboBox_weekday_1->setObjectName(QStringLiteral("comboBox_weekday_1"));

        gridLayout->addWidget(comboBox_weekday_1, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 4, 3, 1);

        comboBox_month = new QComboBox(YearRepeatWidget);
        comboBox_month->setObjectName(QStringLiteral("comboBox_month"));
        comboBox_month->setMaxVisibleItems(12);

        gridLayout->addWidget(comboBox_month, 0, 0, 1, 2);


        retranslateUi(YearRepeatWidget);

        QMetaObject::connectSlotsByName(YearRepeatWidget);
    } // setupUi

    void retranslateUi(QWidget *YearRepeatWidget)
    {
        radioButton_day->setText(QApplication::translate("YearRepeatWidget", "&On", nullptr));
        radioButton_weekday->setText(QApplication::translate("YearRepeatWidget", "&At the", nullptr));
        comboBox_day->setItemText(0, QApplication::translate("YearRepeatWidget", "1st", nullptr));
        comboBox_day->setItemText(1, QApplication::translate("YearRepeatWidget", "2nd", nullptr));
        comboBox_day->setItemText(2, QApplication::translate("YearRepeatWidget", "3rd", nullptr));
        comboBox_day->setItemText(3, QApplication::translate("YearRepeatWidget", "4th", nullptr));
        comboBox_day->setItemText(4, QApplication::translate("YearRepeatWidget", "5th", nullptr));
        comboBox_day->setItemText(5, QApplication::translate("YearRepeatWidget", "6th", nullptr));
        comboBox_day->setItemText(6, QApplication::translate("YearRepeatWidget", "7th", nullptr));
        comboBox_day->setItemText(7, QApplication::translate("YearRepeatWidget", "8th", nullptr));
        comboBox_day->setItemText(8, QApplication::translate("YearRepeatWidget", "9th", nullptr));
        comboBox_day->setItemText(9, QApplication::translate("YearRepeatWidget", "10th", nullptr));
        comboBox_day->setItemText(10, QApplication::translate("YearRepeatWidget", "11th", nullptr));
        comboBox_day->setItemText(11, QApplication::translate("YearRepeatWidget", "12th", nullptr));
        comboBox_day->setItemText(12, QApplication::translate("YearRepeatWidget", "13th", nullptr));
        comboBox_day->setItemText(13, QApplication::translate("YearRepeatWidget", "14th", nullptr));
        comboBox_day->setItemText(14, QApplication::translate("YearRepeatWidget", "15th", nullptr));
        comboBox_day->setItemText(15, QApplication::translate("YearRepeatWidget", "16th", nullptr));
        comboBox_day->setItemText(16, QApplication::translate("YearRepeatWidget", "17th", nullptr));
        comboBox_day->setItemText(17, QApplication::translate("YearRepeatWidget", "18th", nullptr));
        comboBox_day->setItemText(18, QApplication::translate("YearRepeatWidget", "19th", nullptr));
        comboBox_day->setItemText(19, QApplication::translate("YearRepeatWidget", "20th", nullptr));
        comboBox_day->setItemText(20, QApplication::translate("YearRepeatWidget", "21st", nullptr));
        comboBox_day->setItemText(21, QApplication::translate("YearRepeatWidget", "22nd", nullptr));
        comboBox_day->setItemText(22, QApplication::translate("YearRepeatWidget", "23rd", nullptr));
        comboBox_day->setItemText(23, QApplication::translate("YearRepeatWidget", "24th", nullptr));
        comboBox_day->setItemText(24, QApplication::translate("YearRepeatWidget", "25th", nullptr));
        comboBox_day->setItemText(25, QApplication::translate("YearRepeatWidget", "26th", nullptr));
        comboBox_day->setItemText(26, QApplication::translate("YearRepeatWidget", "27th", nullptr));
        comboBox_day->setItemText(27, QApplication::translate("YearRepeatWidget", "28th", nullptr));
        comboBox_day->setItemText(28, QApplication::translate("YearRepeatWidget", "29th", nullptr));
        comboBox_day->setItemText(29, QApplication::translate("YearRepeatWidget", "20th", nullptr));
        comboBox_day->setItemText(30, QApplication::translate("YearRepeatWidget", "31st", nullptr));
        comboBox_day->setItemText(31, QApplication::translate("YearRepeatWidget", "the last day", nullptr));

        comboBox_weekday_1->setItemText(0, QApplication::translate("YearRepeatWidget", "first", nullptr));
        comboBox_weekday_1->setItemText(1, QApplication::translate("YearRepeatWidget", "second", nullptr));
        comboBox_weekday_1->setItemText(2, QApplication::translate("YearRepeatWidget", "third", nullptr));
        comboBox_weekday_1->setItemText(3, QApplication::translate("YearRepeatWidget", "fourth", nullptr));
        comboBox_weekday_1->setItemText(4, QApplication::translate("YearRepeatWidget", "fifth", nullptr));
        comboBox_weekday_1->setItemText(5, QApplication::translate("YearRepeatWidget", "last", nullptr));

        Q_UNUSED(YearRepeatWidget);
    } // retranslateUi

};

namespace Ui {
    class YearRepeatWidget: public Ui_YearRepeatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YEARREPEATWIDGET_H
