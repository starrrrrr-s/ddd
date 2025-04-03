#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupTimeSlots();

    QDate currentDate = QDate::currentDate();
    currentDay = QDate::currentDate();
    currentWeek = currentDay.addDays(-currentDay.dayOfWeek() + 1);

    setDayView(currentDate);
    setWeekView(currentDate);

    setupConnections();

    // 连接添加事件按钮
    connect(ui->newEventBtn, &QPushButton::clicked, this, &MainWindow::onAddEventClicked);
}

void MainWindow::setupTimeSlots()
{
    for (int hour = 8; hour < 22; hour++) {
        timeSlots << QString("%1:00").arg(hour, 2, 10, QLatin1Char('0'));
        timeSlots << QString("%1:30").arg(hour, 2, 10, QLatin1Char('0'));
    }
    timeSlots << "22:00";
}
void MainWindow::onAddEventClicked()
{
    EventDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        CalendarEvent event;
        event.name = dialog.eventName();
        event.category = dialog.eventCategory();
        event.start = dialog.startDateTime();
        event.end = dialog.endDateTime();
        event.notes = dialog.notes();

        events.append(event);

        // 更新视图显示新事件
        setDayView(currentDay);
        setWeekView(currentWeek);
    }
}
void MainWindow::setWeekView(QDate date)
{
    currentWeek = date.addDays(-date.dayOfWeek() + 1);
    QDate sunday = currentWeek.addDays(6);
    ui->weekLabel->setText(currentWeek.toString("yyyy-MM-dd") + " ~ " + sunday.toString("yyyy-MM-dd"));

    ui->weekView->setRowCount(timeSlots.size());
    ui->weekView->setColumnCount(8);

    for (int row = 0; row < timeSlots.size(); ++row) {
        QTableWidgetItem *timeItem = new QTableWidgetItem(timeSlots[row]);
        ui->weekView->setVerticalHeaderItem(row, timeItem);
    }

    QStringList headers;
    headers << "时间";
    for (int i = 0; i < 7; i++) {
        headers << currentWeek.addDays(i).toString("MM-dd ddd");
    }
    ui->weekView->setHorizontalHeaderLabels(headers);

    ui->weekView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->weekView->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->weekView->verticalHeader()->setDefaultSectionSize(40);
    ui->weekView->setEditTriggers(QAbstractItemView::DoubleClicked);

    // 设置第一列（时间列）不可编辑
    for (int row = 0; row < timeSlots.size(); ++row) {
        QTableWidgetItem *item = new QTableWidgetItem(timeSlots[row]);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        ui->weekView->setItem(row, 0, item);
    }

    // 填充周视图中的事件
    for (int day = 0; day < 7; day++) {
        QDate currentDate = currentWeek.addDays(day);

        for (int row = 0; row < timeSlots.size(); row++) {
            QTime slotTime = QTime::fromString(timeSlots[row], "HH:mm");
            QDateTime startDateTime(currentDate, slotTime);
            QDateTime endDateTime = startDateTime.addSecs(1800); // 半小时后

            // 查找这个时间段的事件
            for (const auto &event : events) {
                if (event.start.date() == currentDate &&
                    event.start.time() >= slotTime &&
                    event.start.time() < slotTime.addSecs(1800)) {

                    QTableWidgetItem *eventItem = new QTableWidgetItem(event.name);
                    ui->weekView->setItem(row, day + 1, eventItem); // 第一列是时间
                    break;
                }
            }
        }
    }
}

void MainWindow::setDayView(QDate date)
{
    currentDay = date;
    ui->dayLabel->setText(date.toString("yyyy-MM-dd dddd"));

    ui->dayView->setRowCount(timeSlots.size());
    ui->dayView->setColumnCount(2);

    QStringList headers;
    headers << "时间" << "事件";
    ui->dayView->setHorizontalHeaderLabels(headers);

    for (int row = 0; row < timeSlots.size(); ++row) {
        QTableWidgetItem *timeItem = new QTableWidgetItem(timeSlots[row]);
        timeItem->setFlags(timeItem->flags() & ~Qt::ItemIsEditable);
        ui->dayView->setItem(row, 0, timeItem);

        // 显示该时间段的事件
        QTime slotTime = QTime::fromString(timeSlots[row], "HH:mm");
        QDateTime startDateTime(date, slotTime);
        QDateTime endDateTime = startDateTime.addSecs(1800); // 半小时后

        for (const auto &event : events) {
            if (event.start >= startDateTime && event.start < endDateTime) {
                QTableWidgetItem *eventItem = new QTableWidgetItem(event.name);
                ui->dayView->setItem(row, 1, eventItem);
                break;
            }
        }
    }
}

void MainWindow::setupConnections()
{
    // 连接视图切换按钮
    connect(ui->dayButton, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->weekButton, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->monthButton, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(2);
    });

    // 连接日期导航按钮
    connect(ui->prevDayBtn, &QPushButton::clicked, [this]() {
        setDayView(currentDay.addDays(-1));
    });
    connect(ui->nextDayBtn, &QPushButton::clicked, [this]() {
        setDayView(currentDay.addDays(1));
    });
    connect(ui->prevWeekBtn, &QPushButton::clicked, [this]() {
        setWeekView(currentWeek.addDays(-7));
    });
    connect(ui->nextWeekBtn, &QPushButton::clicked, [this]() {
        setWeekView(currentWeek.addDays(7));
    });
    connect(ui->newEventBtn, &QPushButton::clicked, [this]() {

    });
    connect(ui->dayView, &QTableWidget::cellDoubleClicked, [this](int row, int col) {
        if (col == 1) { // 只有事件列可编辑
            QTime slotTime = QTime::fromString(timeSlots[row], "HH:mm");
            QDateTime start(currentDay, slotTime);
            QDateTime end = start.addSecs(1800);

            // 查找并编辑现有事件
            for (auto &event : events) {
                if (event.start >= start && event.start < end) {
                    EventDialog dialog(this);
                    dialog.setEventName(event.name);
                    dialog.setEventCategory(event.category);
                    dialog.setStartDateTime(event.start);
                    dialog.setEndDateTime(event.end);
                    dialog.setNotes(event.notes);

                    if (dialog.exec() == QDialog::Accepted) {
                        event.name = dialog.eventName();
                        event.category = dialog.eventCategory();
                        event.start = dialog.startDateTime();
                        event.end = dialog.endDateTime();
                        event.notes = dialog.notes();

                        setDayView(currentDay);
                        setWeekView(currentWeek);
                    }
                    return;
                }
            }
        }
    });

    connect(ui->weekView, &QTableWidget::cellDoubleClicked, [this](int row, int col) {
        if (col > 0) { // 忽略时间列
            QTime slotTime = QTime::fromString(timeSlots[row], "HH:mm");
            QDate eventDate = currentWeek.addDays(col - 1);
            QDateTime start(eventDate, slotTime);
            QDateTime end = start.addSecs(1800);

            // 查找并编辑现有事件
            for (auto &event : events) {
                if (event.start >= start && event.start < end) {
                    EventDialog dialog(this);
                    dialog.setEventName(event.name);
                    dialog.setEventCategory(event.category);
                    dialog.setStartDateTime(event.start);
                    dialog.setEndDateTime(event.end);
                    dialog.setNotes(event.notes);

                    if (dialog.exec() == QDialog::Accepted) {
                        event.name = dialog.eventName();
                        event.category = dialog.eventCategory();
                        event.start = dialog.startDateTime();
                        event.end = dialog.endDateTime();
                        event.notes = dialog.notes();

                        setDayView(currentDay);
                        setWeekView(currentWeek);
                    }
                    return;
                }
            }
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
