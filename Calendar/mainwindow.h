// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include "eventdialog.h"  // 包含事件对话框头文件

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

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

private slots:
    void onAddEventClicked();  // 添加事件按钮点击槽函数

private:
    Ui::MainWindow *ui;
    QDate currentDay;
    QDate currentWeek;
    QStringList timeSlots;

    // 事件数据结构
    struct CalendarEvent {
        QString name;
        QString category;
        QDateTime start;
        QDateTime end;
        QString notes;
    };
    QList<CalendarEvent> events;
};
#endif // MAINWINDOW_H
