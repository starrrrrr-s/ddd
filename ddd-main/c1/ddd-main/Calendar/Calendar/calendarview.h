#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QCalendarWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>

class CalendarView : public QMainWindow
{
    Q_OBJECT
    CalendarView(QWidget *parent = nullptr);

private:
    QStackedWidget *stackedWidget;
    QTableWidget *dayView;
    QTableWidget *weekView;
    QCalendarWidget *monthView;
signals:
};

#endif // CALENDARVIEW_H
