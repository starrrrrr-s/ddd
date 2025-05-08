/********************************************************************************
** Form generated from reading UI file 'weekrepeatwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEEKREPEATWIDGET_H
#define UI_WEEKREPEATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeekRepeatWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *WeekRepeatWidget)
    {
        if (WeekRepeatWidget->objectName().isEmpty())
            WeekRepeatWidget->setObjectName(QStringLiteral("WeekRepeatWidget"));
        horizontalLayout = new QHBoxLayout(WeekRepeatWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        horizontalLayout->addLayout(gridLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(WeekRepeatWidget);

        QMetaObject::connectSlotsByName(WeekRepeatWidget);
    } // setupUi

    void retranslateUi(QWidget *WeekRepeatWidget)
    {
        Q_UNUSED(WeekRepeatWidget);
    } // retranslateUi

};

namespace Ui {
    class WeekRepeatWidget: public Ui_WeekRepeatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEEKREPEATWIDGET_H
