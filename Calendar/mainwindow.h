// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include "eventdialog.h"  // 包含事件对话框头文件
#include <QMenu>
#include <QAction>
#include<QLabel>
#include<QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
struct CalendarEvent {
    int id;  // 添加事件ID
    QString name;
    QString category;
    QDateTime start;
    QDateTime end;
    QString notes;

    // 添加构造函数
    CalendarEvent() : id(-1) {}
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setupConnections();
    void setWeekView(QDate date);
    void setDayView(QDate date);
    void setupTimeSlots();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void onAddEventClicked();  // 添加事件按钮点击槽函数
    void onEditEvent(const QModelIndex &index);
    void onDeleteEvent();
    void showContextMenu(const QPoint &pos);
    void onMonthCellEntered(const QDate &date);
    void onMonthHoverTimeout();
    void onWeekCellClicked(int row, int column);
    void showWeekCellContextMenu(const QPoint &pos);

private:
    Ui::MainWindow *ui;
    QDate currentDay;
    QDate currentWeek;
    QStringList timeSlots;
    QMenu *contextMenu;
    QAction *editAction;
    QAction *deleteAction;
    QModelIndex contextMenuIndex;
    void updateEventViews();
    void showEventEditDialog(const CalendarEvent &event, bool isNew = false);
    void removeEvent(const QDateTime &startTime);
    QDate monthViewDateAt(const QPoint &pos) const;
    QString currentUserPhone; // 当前登录用户

    // 添加以下成员变量
    QTimer *monthHoverTimer;
    QDate hoveredDate;
    QLabel *eventTooltip;

    QList<CalendarEvent> events;
};
#endif // MAINWINDOW_H
