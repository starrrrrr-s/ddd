#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setupConnections();
    void setWeekView(QDate date);
    void setDayView(QDate date);


private:
    Ui::MainWindow *ui;
    QDate currentDay;   // 记录当前日视图的日期
    QDate currentWeek;  // 记录当前周视图的周一日期
};
#endif // MAINWINDOW_H
