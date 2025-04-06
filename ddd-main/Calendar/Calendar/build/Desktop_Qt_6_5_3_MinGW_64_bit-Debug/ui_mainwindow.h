/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *dayWidget;
    QTableWidget *dayView;
    QLabel *dayLabel;
    QPushButton *prevDayBtn;
    QPushButton *nextDayBtn;
    QWidget *weekWidget;
    QTableWidget *weekView;
    QLabel *weekLabel;
    QPushButton *prevWeekBtn;
    QPushButton *nextWeekBtn;
    QWidget *monthWidget;
    QCalendarWidget *monthView;
    QPushButton *dayButton;
    QPushButton *weekButton;
    QPushButton *monthButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 50, 801, 411));
        dayWidget = new QWidget();
        dayWidget->setObjectName("dayWidget");
        dayView = new QTableWidget(dayWidget);
        if (dayView->columnCount() < 2)
            dayView->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        dayView->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        dayView->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (dayView->rowCount() < 1)
            dayView->setRowCount(1);
        dayView->setObjectName("dayView");
        dayView->setGeometry(QRect(0, 30, 801, 371));
        dayLabel = new QLabel(dayWidget);
        dayLabel->setObjectName("dayLabel");
        dayLabel->setGeometry(QRect(10, 10, 111, 16));
        prevDayBtn = new QPushButton(dayWidget);
        prevDayBtn->setObjectName("prevDayBtn");
        prevDayBtn->setGeometry(QRect(300, 0, 80, 24));
        nextDayBtn = new QPushButton(dayWidget);
        nextDayBtn->setObjectName("nextDayBtn");
        nextDayBtn->setGeometry(QRect(390, 0, 80, 24));
        stackedWidget->addWidget(dayWidget);
        weekWidget = new QWidget();
        weekWidget->setObjectName("weekWidget");
        weekView = new QTableWidget(weekWidget);
        if (weekView->columnCount() < 7)
            weekView->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        weekView->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        weekView->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        weekView->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        weekView->setHorizontalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        weekView->setHorizontalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        weekView->setHorizontalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        weekView->setHorizontalHeaderItem(6, __qtablewidgetitem8);
        if (weekView->rowCount() < 2)
            weekView->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        weekView->setVerticalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        weekView->setVerticalHeaderItem(1, __qtablewidgetitem10);
        weekView->setObjectName("weekView");
        weekView->setGeometry(QRect(10, 80, 791, 321));
        weekLabel = new QLabel(weekWidget);
        weekLabel->setObjectName("weekLabel");
        weekLabel->setGeometry(QRect(10, 60, 291, 16));
        prevWeekBtn = new QPushButton(weekWidget);
        prevWeekBtn->setObjectName("prevWeekBtn");
        prevWeekBtn->setGeometry(QRect(340, 50, 80, 24));
        nextWeekBtn = new QPushButton(weekWidget);
        nextWeekBtn->setObjectName("nextWeekBtn");
        nextWeekBtn->setGeometry(QRect(430, 50, 80, 24));
        stackedWidget->addWidget(weekWidget);
        monthWidget = new QWidget();
        monthWidget->setObjectName("monthWidget");
        monthView = new QCalendarWidget(monthWidget);
        monthView->setObjectName("monthView");
        monthView->setGeometry(QRect(0, 0, 801, 451));
        stackedWidget->addWidget(monthWidget);
        dayButton = new QPushButton(centralwidget);
        dayButton->setObjectName("dayButton");
        dayButton->setGeometry(QRect(730, 10, 51, 24));
        weekButton = new QPushButton(centralwidget);
        weekButton->setObjectName("weekButton");
        weekButton->setGeometry(QRect(659, 10, 51, 24));
        monthButton = new QPushButton(centralwidget);
        monthButton->setObjectName("monthButton");
        monthButton->setGeometry(QRect(589, 10, 51, 24));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = dayView->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = dayView->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\344\272\213\344\273\266", nullptr));
        dayLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        prevDayBtn->setText(QCoreApplication::translate("MainWindow", "\345\211\215\344\270\200\345\244\251", nullptr));
        nextDayBtn->setText(QCoreApplication::translate("MainWindow", "\345\220\216\344\270\200\345\244\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = weekView->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Sun", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = weekView->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Mon", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = weekView->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Tue", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = weekView->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Wed", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = weekView->horizontalHeaderItem(4);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Thu", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = weekView->horizontalHeaderItem(5);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Fri", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = weekView->horizontalHeaderItem(6);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Sat", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = weekView->verticalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "\344\272\213\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = weekView->verticalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "\350\257\276\347\250\213", nullptr));
        weekLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        prevWeekBtn->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\345\221\250", nullptr));
        nextWeekBtn->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\345\221\250", nullptr));
        dayButton->setText(QCoreApplication::translate("MainWindow", "\346\227\245\350\247\206\345\233\276", nullptr));
        weekButton->setText(QCoreApplication::translate("MainWindow", "\345\221\250\350\247\206\345\233\276", nullptr));
        monthButton->setText(QCoreApplication::translate("MainWindow", "\346\234\210\350\247\206\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
