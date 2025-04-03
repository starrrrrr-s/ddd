#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentDay(QDate::currentDate())
    , currentWeek(currentDay.addDays(-currentDay.dayOfWeek() + 1))
    , contextMenu(new QMenu(this))
    , editAction(new QAction(tr("编辑"), this))
    , deleteAction(new QAction(tr("删除"), this))
{
    ui->setupUi(this);

    // 初始化时间槽
    setupTimeSlots();

    // 初始化UI视图
    setDayView(currentDay);
    setWeekView(currentWeek);

    // 设置上下文菜单
    contextMenu->addAction(editAction);
    contextMenu->addAction(deleteAction);

    // 设置表格的上下文菜单策略
    ui->dayView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->weekView->setContextMenuPolicy(Qt::CustomContextMenu);

    // 确保表格可编辑
    ui->weekView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
    ui->weekView->setSelectionMode(QAbstractItemView::SingleSelection);

    // 初始化月视图悬停计时器
    monthHoverTimer = new QTimer(this);
    monthHoverTimer->setSingleShot(true);
    monthHoverTimer->setInterval(3000); // 3秒

    // 初始化事件提示框
    eventTooltip = new QLabel(this);
    eventTooltip->setWindowFlags(Qt::ToolTip | Qt::FramelessWindowHint);
    eventTooltip->setStyleSheet("QLabel { background-color: white; border: 1px solid gray; padding: 5px; }");
    eventTooltip->hide();

    // 连接月视图信号
    connect(ui->monthView, &QCalendarWidget::activated, [this](const QDate &date) {
        setDayView(date);
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->monthView, &QCalendarWidget::clicked, [this](const QDate &date) {
        monthHoverTimer->stop();
        eventTooltip->hide();
    });

    // 自定义月视图单元格悬停检测
    ui->monthView->setMouseTracking(true);
    ui->monthView->installEventFilter(this);  // 直接为 monthView 安装事件过滤器

    connect(monthHoverTimer, &QTimer::timeout, this, &MainWindow::onMonthHoverTimeout);

    // 周视图单元格点击事件
    connect(ui->weekView, &QTableWidget::cellClicked, this, &MainWindow::onWeekCellClicked);

    // 连接信号和槽
    setupConnections();

    // 连接上下文菜单信号
    connect(ui->dayView, &QTableWidget::customContextMenuRequested,
            this, &MainWindow::showContextMenu);
    connect(ui->weekView, &QTableWidget::customContextMenuRequested,
            this, &MainWindow::showContextMenu);

    // 使用lambda表达式连接编辑动作
    connect(editAction, &QAction::triggered, this, [this]() {
        if (contextMenuIndex.isValid()) {
            onEditEvent(contextMenuIndex);
        }
    });

    // 连接删除动作（修正后的连接语句）
    connect(deleteAction, &QAction::triggered, this, &MainWindow::onDeleteEvent);

    // 连接添加事件按钮
    connect(ui->newEventBtn, &QPushButton::clicked, this, &MainWindow::onAddEventClicked);
}


void MainWindow::showEventEditDialog(const CalendarEvent &event, bool isNew)
{
    EventDialog dialog(this);
    dialog.setEventName(event.name);
    dialog.setEventCategory(event.category);
    dialog.setStartDateTime(event.start);
    dialog.setEndDateTime(event.end);
    dialog.setNotes(event.notes);

    if (dialog.exec() == QDialog::Accepted) {
        CalendarEvent updatedEvent;
        updatedEvent.name = dialog.eventName();
        updatedEvent.category = dialog.eventCategory();
        updatedEvent.start = dialog.startDateTime();
        updatedEvent.end = dialog.endDateTime();
        updatedEvent.notes = dialog.notes();

        if (!isNew) {
            removeEvent(event.start);
        }

        events.append(updatedEvent);
        updateEventViews();
    }
}
// 更新所有视图
void MainWindow::updateEventViews()
{
    setDayView(currentDay);
    setWeekView(currentWeek);
}

// 删除事件
void MainWindow::removeEvent(const QDateTime &startTime)
{
    for (int i = 0; i < events.size(); ++i) {
        if (events[i].start == startTime) {
            events.removeAt(i);
            break;
        }
    }
}

// 上下文菜单显示
void MainWindow::showContextMenu(const QPoint &pos)
{
    QTableWidget *table = qobject_cast<QTableWidget*>(sender());
    if (!table) return;

    QModelIndex index = table->indexAt(pos);
    if (!index.isValid()) return;

    contextMenuIndex = index;
    contextMenu->exec(table->viewport()->mapToGlobal(pos));
    // 在 MainWindow 构造函数中修改连接方式
    connect(editAction, &QAction::triggered, this, [this]() {
        if (contextMenuIndex.isValid()) {
            onEditEvent(contextMenuIndex);
        }
    });
}

// 编辑事件
void MainWindow::onEditEvent(const QModelIndex &index)
{
    QTableWidget *table = qobject_cast<QTableWidget*>(sender());
    if (!table || !index.isValid()) return;

    int row = index.row();
    int col = index.column();

    if (table == ui->dayView && col == 1) {
        // 日视图编辑
        QTime slotTime = QTime::fromString(timeSlots[row], "HH:mm");
        QDateTime start(currentDay, slotTime);

        for (const auto &event : events) {
            if (event.start >= start && event.start < start.addSecs(1800)) {
                showEventEditDialog(event);
                return;
            }
        }
    }
    else if (table == ui->weekView && col > 0) {
        // 周视图编辑
        QTime slotTime = QTime::fromString(timeSlots[row], "HH:mm");
        QDate eventDate = currentWeek.addDays(col - 1);
        QDateTime start(eventDate, slotTime);

        for (const auto &event : events) {
            if (event.start >= start && event.start < start.addSecs(1800)) {
                showEventEditDialog(event);
                return;
            }
        }
    }
}

// 删除事件
void MainWindow::onDeleteEvent()
{
    QTableWidget *table = qobject_cast<QTableWidget*>(sender()->parent()->parent());
    if (!table || !contextMenuIndex.isValid()) return;

    int row = contextMenuIndex.row();
    int col = contextMenuIndex.column();

    if (table == ui->dayView && col == 1) {
        // 日视图删除
        QTime slotTime = QTime::fromString(timeSlots[row], "HH:mm");
        QDateTime start(currentDay, slotTime);
        removeEvent(start);
    } else if (table == ui->weekView && col > 0) {
        // 周视图删除
        QTime slotTime = QTime::fromString(timeSlots[row], "HH:mm");
        QDate eventDate = currentWeek.addDays(col - 1);
        QDateTime start(eventDate, slotTime);
        removeEvent(start);
    }

    updateEventViews();
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
    CalendarEvent newEvent;
    newEvent.start = QDateTime::currentDateTime();
    newEvent.end = newEvent.start.addSecs(3600); // 默认1小时

    showEventEditDialog(newEvent, true);
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

        // 清除原有内容
        if (ui->dayView->item(row, 1)) {
            delete ui->dayView->item(row, 1);
        }

        // 显示该时间段的事件
        QTime slotTime = QTime::fromString(timeSlots[row], "HH:mm");
        QDateTime startDateTime(date, slotTime);
        QDateTime endDateTime = startDateTime.addSecs(1800); // 半小时后

        for (const auto &event : events) {
            if (event.start.date() == date &&
                ((event.start >= startDateTime && event.start < endDateTime) ||
                 (event.end > startDateTime && event.end <= endDateTime) ||
                 (event.start <= startDateTime && event.end >= endDateTime))) {

                QTableWidgetItem *eventItem = new QTableWidgetItem(event.name);
                eventItem->setData(Qt::UserRole, QVariant::fromValue(event.start));
                ui->dayView->setItem(row, 1, eventItem);

                // 根据事件类别设置背景色
                if (event.category == "生日") {
                    eventItem->setBackground(QColor(255, 230, 230));
                } else if (event.category == "纪念日") {
                    eventItem->setBackground(QColor(230, 255, 230));
                } else {
                    eventItem->setBackground(QColor(230, 230, 255));
                }
                break;
            }
        }
    }
}

void MainWindow::setWeekView(QDate date)
{
    currentWeek = date.addDays(-date.dayOfWeek() + 1);
    QDate sunday = currentWeek.addDays(6);
    ui->weekLabel->setText(currentWeek.toString("yyyy-MM-dd") + " ~ " + sunday.toString("yyyy-MM-dd"));


    // 确保表格可编辑
    ui->weekView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
    ui->weekView->setSelectionMode(QAbstractItemView::SingleSelection);
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
    ui->weekView->setEditTriggers(QAbstractItemView::NoEditTriggers);

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

            // 清除原有内容
            if (ui->weekView->item(row, day + 1)) {
                delete ui->weekView->item(row, day + 1);
            }

            // 查找这个时间段的所有事件
            for (const auto &event : events) {
                if (event.start.date() == currentDate &&
                    event.start.time() >= slotTime &&
                    event.start.time() < slotTime.addSecs(1800)) {

                    QTableWidgetItem *eventItem = new QTableWidgetItem(event.name);
                    eventItem->setFlags(eventItem->flags() | Qt::ItemIsEditable);

                    // 根据事件类别设置背景色
                    if (event.category == "生日") {
                        eventItem->setBackground(QColor(255, 230, 230));
                    } else if (event.category == "纪念日") {
                        eventItem->setBackground(QColor(230, 255, 230));
                    } else {
                        eventItem->setBackground(QColor(230, 230, 255));
                    }

                    ui->weekView->setItem(row, day + 1, eventItem);
                    break;
                }
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
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->monthView) {
        if (event->type() == QEvent::MouseMove) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            QDate date = monthViewDateAt(mouseEvent->pos());
            if (date.isValid()) {
                onMonthCellEntered(date);
            }
        } else if (event->type() == QEvent::Leave) {
            monthHoverTimer->stop();
            eventTooltip->hide();
        }
    }
    return QMainWindow::eventFilter(watched, event);
}
QDate MainWindow::monthViewDateAt(const QPoint &pos) const
{
    // 获取月视图的几何信息
    QRect rect = ui->monthView->geometry();
    if (!rect.contains(pos)) return QDate();

    // 计算每个单元格的大小
    QSize cellSize = ui->monthView->size() / 6; // 大约6行

    // 获取当前显示的月份
    QDate currentDate = ui->monthView->selectedDate();
    QDate firstOfMonth(currentDate.year(), currentDate.month(), 1);
    int firstDayOfWeek = firstOfMonth.dayOfWeek();

    // 计算点击的单元格
    int row = pos.y() / cellSize.height();
    int col = pos.x() / cellSize.width();
    int day = (row * 7) + col - firstDayOfWeek + 2;

    // 检查日期是否在当前月份
    if (day < 1 || day > firstOfMonth.daysInMonth()) {
        return QDate();
    }

    return QDate(currentDate.year(), currentDate.month(), day);
}
void MainWindow::onMonthCellEntered(const QDate &date)
{
    hoveredDate = date;
    monthHoverTimer->start();
}

void MainWindow::onMonthHoverTimeout()
{
    QList<CalendarEvent> dayEvents;
    for (const auto &event : events) {
        if (event.start.date() == hoveredDate) {
            dayEvents.append(event);
        }
    }

    if (!dayEvents.isEmpty()) {
        QString tooltipText = "<b>" + hoveredDate.toString("yyyy-MM-dd") + "</b><br>";
        for (const auto &event : dayEvents) {
            tooltipText += QString("%1 - %2: %3<br>")
                .arg(event.start.time().toString("HH:mm"))
                .arg(event.end.time().toString("HH:mm"))
                .arg(event.name);
        }
        eventTooltip->setText(tooltipText);

        // 获取鼠标位置并显示提示框
        QPoint pos = QCursor::pos();
        eventTooltip->move(pos.x() + 15, pos.y() + 15);
        eventTooltip->adjustSize();
        eventTooltip->show();
    } else {
        eventTooltip->hide();
    }
}
void MainWindow::showWeekCellContextMenu(const QPoint &pos)
{
    // 获取点击的单元格
    QModelIndex index = ui->weekView->indexAt(pos);
    if (!index.isValid()) return;

    int row = index.row();
    int col = index.column();

    if (col == 0) return; // 忽略时间列

    QTime slotTime = QTime::fromString(timeSlots[row], "HH:mm");
    QDate eventDate = currentWeek.addDays(col - 1);
    QDateTime start(eventDate, slotTime);

    // 创建上下文菜单
    QMenu menu(this);
    QAction *newAction = menu.addAction("新建");
    QAction *editAction = menu.addAction("编辑");
    QAction *deleteAction = menu.addAction("删除");

    // 检查当前时间段是否有事件
    bool hasEvent = false;
    CalendarEvent currentEvent;
    for (const auto &event : events) {
        if (event.start >= start && event.start < start.addSecs(1800)) {
            hasEvent = true;
            currentEvent = event;
            break;
        }
    }

    // 如果没有事件，禁用编辑和删除
    editAction->setEnabled(hasEvent);
    deleteAction->setEnabled(hasEvent);

    // 执行菜单
    QAction *selectedAction = menu.exec(ui->weekView->viewport()->mapToGlobal(pos));

    if (selectedAction == newAction) {
        CalendarEvent newEvent;
        newEvent.start = start;
        newEvent.end = start.addSecs(1800);
        showEventEditDialog(newEvent, true);
    } else if (selectedAction == editAction && hasEvent) {
        showEventEditDialog(currentEvent, false);
    } else if (selectedAction == deleteAction && hasEvent) {
        removeEvent(currentEvent.start);
        updateEventViews();
    }
}
void MainWindow::onWeekCellClicked(int row, int column)
{
    if (column == 0) return; // 忽略时间列

    QTime slotTime = QTime::fromString(timeSlots[row], "HH:mm");
    QDate eventDate = currentWeek.addDays(column - 1);
    QDateTime start(eventDate, slotTime);

    // 创建上下文菜单
    QMenu menu(this);
    QAction *newAction = menu.addAction("新建");
    QAction *editAction = menu.addAction("编辑");
    QAction *deleteAction = menu.addAction("删除");

    // 检查当前时间段是否有事件
    bool hasEvent = false;
    CalendarEvent currentEvent;
    for (const auto &event : events) {
        if (event.start >= start && event.start < start.addSecs(1800)) {
            hasEvent = true;
            currentEvent = event;
            break;
        }
    }

    // 如果没有事件，禁用编辑和删除
    editAction->setEnabled(hasEvent);
    deleteAction->setEnabled(hasEvent);

    // 执行菜单
    QPoint pos = ui->weekView->viewport()->mapToGlobal(
        ui->weekView->visualItemRect(ui->weekView->item(row, column)).bottomLeft());
    QAction *selectedAction = menu.exec(pos);

    if (selectedAction == newAction) {
        CalendarEvent newEvent;
        newEvent.start = start;
        newEvent.end = start.addSecs(1800); // 默认半小时
        showEventEditDialog(newEvent, true);
    } else if (selectedAction == editAction && hasEvent) {
        showEventEditDialog(currentEvent, false);
    } else if (selectedAction == deleteAction && hasEvent) {
        removeEvent(currentEvent.start);
        updateEventViews();
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
