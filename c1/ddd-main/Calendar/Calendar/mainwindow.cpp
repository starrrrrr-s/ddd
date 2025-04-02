#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 初始化周视图，默认显示当前周
    QDate currentDate = QDate::currentDate();
    // 初始化当前日期和周一日期
    currentDay = QDate::currentDate();
    currentWeek = currentDay.addDays(-currentDay.dayOfWeek() + 1);  // 获取本周周一

    // 初始化日/周视图，默认跳转到今天
    setDayView(currentDate);
    setWeekView(currentDate);

    setupConnections();  // 连接信号与槽
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupConnections()
{
    connect(ui->dayButton, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);  // 切换到日视图
        setDayView(QDate::currentDate());  // 切换到日视图时，自动跳转到今天
    });

    connect(ui->weekButton, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);  // 切换到周视图
        setWeekView(QDate::currentDate());
    });

    connect(ui->monthButton, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(2);  // 切换到月视图
    });

    connect(ui->prevDayBtn, &QPushButton::clicked, this, [=]() {
        setDayView(currentDay.addDays(-1));  // 前一天
    });

    connect(ui->nextDayBtn, &QPushButton::clicked, this, [=]() {
        setDayView(currentDay.addDays(1));  // 后一天
    });

    // 存储当前周的日期
    QDate currentWeek = QDate::currentDate();

    connect(ui->prevWeekBtn, &QPushButton::clicked, this, [this]() {
        this->currentWeek = this->currentWeek.addDays(-7);  // 正确使用成员变量
        setWeekView(this->currentWeek);  // 记得更新 UI
    });


    connect(ui->nextWeekBtn, &QPushButton::clicked, this, [=]() {
        this->currentWeek = this->currentWeek.addDays(7);   // 下一周
        setWeekView(currentWeek);
    });

}

void MainWindow::setWeekView(QDate date)
{
    currentWeek = date.addDays(-date.dayOfWeek() + 1);  // 更新当前周的周一

    QDate sunday = currentWeek.addDays(6);
    ui->weekLabel->setText(currentWeek.toString("yyyy-MM-dd") + " ~ " + sunday.toString("yyyy-MM-dd"));

    // 更新表头
    QStringList headers;
    for (int i = 0; i < 7; i++) {
        headers << currentWeek.addDays(i).toString("MM-dd ddd");  // 如 "03-25 周一"
    }
    ui->weekView->setHorizontalHeaderLabels(headers);
}

void MainWindow::setDayView(QDate date)
{
    currentDay = date;  // 记录当前天
    ui->dayLabel->setText(date.toString("yyyy-MM-dd ddd"));  // 更新顶部日期
}
