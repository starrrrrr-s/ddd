#include "calendarview.h"

CalendarView::CalendarView(QWidget *parent)
    : QMainWindow(parent)
{
    // 初始化UI组件
    stackedWidget = new QStackedWidget(this);
    dayView = new QTableWidget(this);
    weekView = new QTableWidget(this);
    monthView = new QCalendarWidget(this);

    // 设置中央部件
    setCentralWidget(stackedWidget);
}
