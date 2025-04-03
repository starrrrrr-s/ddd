#include "calendarview.h"
#include <QMouseEvent>

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

QDate CalendarView::dateAt(const QPoint &pos) const
{
    // 获取月视图中点击位置的日期
    QRect rect = monthView->geometry();
    if (!rect.contains(pos)) return QDate();

    // 计算点击的是哪一天
    QPoint localPos = monthView->mapFromParent(pos);
    QSize cellSize = monthView->size() / 6; // 大约6行

    // 获取当前显示的月份
    QDate currentDate = monthView->selectedDate();
    QDate firstOfMonth(currentDate.year(), currentDate.month(), 1);
    int firstDayOfWeek = firstOfMonth.dayOfWeek();

    // 计算点击的单元格
    int row = localPos.y() / cellSize.height();
    int col = localPos.x() / cellSize.width();
    int day = (row * 7) + col - firstDayOfWeek + 2;

    // 检查日期是否在当前月份
    if (day < 1 || day > firstOfMonth.daysInMonth()) {
        return QDate();
    }

    return QDate(currentDate.year(), currentDate.month(), day);
}
