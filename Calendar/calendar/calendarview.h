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
public:
    explicit CalendarView(QWidget *parent = nullptr);
    QDate dateAt(const QPoint &pos) const;
private:
    QStackedWidget *stackedWidget;
    QTableWidget *dayView;
    QTableWidget *weekView;
    QCalendarWidget *monthView;
};

#endif // CALENDARVIEW_H
