#include "setting.h"
#include "translator.h"
#include "mainwindow.h"
#include "logindialog.h"
#include "ui_mainwindow.h"
#include "addeventdialog.h"
#include "recurrentevent.h"
#include "continuousevent.h"
#include "daydetaildialog.h"
#include "preferencedialog.h"
#include "dateselectdialog.h"

#include <QDir>
#include <QProcess>
#include <QFileInfo>
#include <QDateEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QSystemTrayIcon>

using namespace std;

static AbstractEvent* eventByAction;
static EventLabelButton* eventLabelByAction;
static QDate dateByAction;
static DayWidget* dayWidgetByAction;
//主窗体
MainWindow::MainWindow(const QString& username, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    current_date(QDate::currentDate()),
    username(username)
{
    Setting::UserDirectory = Const::USER_DIR + username + "/";
    if (!QDir(Setting::UserDirectory).exists()) QDir::current().mkpath(Setting::UserDirectory);
    Setting::LoadSetting(Setting::UserDirectory + Const::SETTING_FILE);
    Translator::InstallToApplication(Setting::Language);
    ui->setupUi(this);

    QGuiApplication::setFont(Setting::InterfaceFont);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint | Qt::Tool);
    this->setAttribute(Qt::WA_TranslucentBackground);

    this->setFont(Setting::InterfaceFont);
    this->move((QApplication::desktop()->width()  - this->width())  / 2,
               (QApplication::desktop()->height() - this->height()) / 2);

    corner_label = new QLabel(this);
    corner_label->setFixedWidth(40);
    corner_label->setStyleSheet("QLabel{background:white;}");
    ui->layout_table->addWidget(corner_label, 0, 0, 1, 1);

    for (int i = 0; i < Const::WEEK_DAYS; i++)
    {
        horizontal_header[i] = new LabelButton(this);
        horizontal_header[i]->setAlignment(Qt::AlignCenter);
        horizontal_header[i]->setFixedHeight(30);
    }
    for (int i = 0; i < Const::MONTH_WEEKS; i++)
    {
        vertical_header[i] = new LabelButton(this);
        vertical_header[i]->setFixedWidth(40);
        vertical_header[i]->setAlignment(Qt::AlignCenter);

        for (int j = 0; j < 4; j++)
        {
            QWidget* empty = new QWidget(this);
            if (!j) empty->setFixedHeight(25);
            ui->layout_table->addWidget(empty, i * 4 + j + 1, 0, 1, 1);
        }
    }
    for (int i = 0; i < Const::MONTH_WEEKS; i++)
        for (int j = 0; j < Const::WEEK_DAYS; j++)
        {
            day_table[i][j] = new DayWidget(this);
            connect(day_table[i][j], &DayWidget::clicked, this, &MainWindow::onShowDayDetail);
            connect(day_table[i][j], &DayWidget::dropIn, this, &MainWindow::onAddFile);
            connect(day_table[i][j], &QWidget::customContextMenuRequested, this, &MainWindow::onDayWidgetContextMenu);
        }
    createActions();
    importData(QDir::currentPath() + "/" + Setting::UserDirectory + Const::USER_DATA_FILE);
    loadTable();
}

MainWindow::~MainWindow()
{
    clearAll();
    delete ui;
}

static QPoint dragPosition;
static bool isDrag;
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        isDrag = true;
        dragPosition = event->globalPos() - this->pos();
    }
    QWidget::mousePressEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (!Setting::Movable) { event->ignore(); return; }
    if (isDrag && event->buttons() == Qt::LeftButton && ui->toolBar->geometry().contains(event->pos()))
    {
        QGuiApplication::setOverrideCursor(Qt::SizeAllCursor);
        move(event->globalPos() - dragPosition);
    }
    QWidget::mouseMoveEvent(event);
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    isDrag = false;
    QGuiApplication::setOverrideCursor(Qt::ArrowCursor);
    QWidget::mouseMoveEvent(event);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (!QDir(Setting::UserDirectory).exists()) QDir::current().mkpath(Setting::UserDirectory);

    exportData(QDir::currentPath() + "/" + Setting::UserDirectory + Const::USER_DATA_FILE);
    QApplication::quit();
}
//为工具栏创建动作
void MainWindow::createActions()
{
    action_show_day = new QAction(this);
    action_add_event = new QAction(this);
    action_edit_event = new QAction(this);
    action_delete_event = new QAction(this);
    action_delete_one_event = new QAction(this);

    QMenu* user = new QMenu(username, this);
    user->setIcon(QPixmap(":/icons/icons/user.png"));
    user->addAction(ui->action_preference);
    user->addSeparator();
    user->addAction(ui->action_logout);

    ui->toolBar->addAction(ui->action_menu);
    ui->toolBar->addAction(ui->action_date);
    ui->toolBar->addAction(ui->action_left);
    ui->toolBar->addAction(ui->action_right);
    ui->toolBar->addAction(ui->action_add);
    ui->toolBar->addAction(ui->action_movable);
    ui->toolBar->addWidget(ui->label_date);

    QSystemTrayIcon* tray = new QSystemTrayIcon(this);
    main_menu = new QMenu(this);
    main_menu->addMenu(user);
    main_menu->addSeparator();
    main_menu->addAction(ui->action_import);
    main_menu->addAction(ui->action_export);
    main_menu->addSeparator();
    main_menu->addAction(ui->action_dragDrop);
    main_menu->addSeparator();
    main_menu->addAction(ui->action_about);
    main_menu->addSeparator();
    main_menu->addAction(ui->action_exit);

    tray->setIcon(QPixmap(":/icons/icons/calendar.ico"));
    tray->setContextMenu(main_menu);
    tray->setToolTip(tr("Calendar"));
    tray->show();

    connect(tray, &QSystemTrayIcon::activated, this, [this]()
    {
        this->activateWindow();
        this->show();
    });
    connect(action_show_day, &QAction::triggered, this, &MainWindow::onShowDayDetail);
    connect(action_add_event, &QAction::triggered, this, &MainWindow::onAddEvent);
    connect(action_edit_event, &QAction::triggered, this, &MainWindow::onEditEvent);
    connect(action_delete_event, &QAction::triggered, this, &MainWindow::onDeleteEvent);
    connect(action_delete_one_event, &QAction::triggered, this, &MainWindow::onDeleteOneEvent);
}
//清除所有事件
void MainWindow::clearAll()
{
    for (auto i : event_labels) i->deleteLater();
    for (auto i : event_list) i->deleteLater();
    event_labels.clear();
    event_list.clear();
    day_color.clear();
}
//加载表格
void MainWindow::loadTable()
{
    ui->retranslateUi(this);
    this->setWindowOpacity(Setting::Opacity / 10.0);

    QGuiApplication::setFont(Setting::InterfaceFont);
    QFont font = ui->label_date->font();
    font.setFamily(Setting::InterfaceFont.family());
    font.setPointSize(Setting::InterfaceFont.pointSize() * 2);
    ui->label_date->setFont(font);
    ui->label_date->setText(Translator::Locale(Setting::Language).toString(current_date, "MMMM yyyy"));

    ui->action_movable->setToolTip(Setting::Movable ? tr("Fix") : tr("Move"));
    ui->action_dragDrop->setChecked(Setting::EnableDragsAndDrops);
    ui->layout_table->setSpacing(Setting::CellSpace);
    ui->toolBar->setStyleSheet(QString("QToolBar{background:%1;}").arg(Setting::CellColor.light(140).name()));

    for (int i = 0; i < Const::WEEK_DAYS; i++)
    {
        horizontal_header[i]->setText(Translator::Locale(Setting::Language).dayName(!i ? 7 : i, QLocale::ShortFormat));
        horizontal_header[i]->SetBackgroundColor(Setting::CellColor.darker(135));
        if (Const::IsWeekend(i))
            horizontal_header[i]->SetTextColor(Qt::red);
        else
            horizontal_header[i]->SetTextColor(Qt::black);
    }
    if (Setting::ShowWeekNumber)
    {
        corner_label->setFixedWidth(40);
        corner_label->setStyleSheet(QString("background:%1;").arg(Setting::CellColor.darker(140).name()));
        for (int i = 0; i < Const::MONTH_WEEKS; i++)
        {
            vertical_header[i]->show();
            vertical_header[i]->SetBackgroundColor(Setting::CellColor.darker(140));
            vertical_header[i]->SetTextColor(Qt::black);
        }
    }
    else
    {
        corner_label->setFixedWidth(0);
        for (int i = 0; i < Const::MONTH_WEEKS; i++) vertical_header[i]->hide();
    }

    for (int i = 0; i < Const::WEEK_DAYS; i++)
    {
        int day = dayFromColumn(i);
        ui->layout_table->addWidget(horizontal_header[day], 0, i + 1, 1, 1);
    }

    QDate first = current_date, day;
    first.setDate(current_date.year(), current_date.month(), 1);
    day = first.addDays(-first.dayOfWeek() + Setting::WeekFirstDay);
    for (int i = 0; i < Const::MONTH_WEEKS; i++)
    {
        vertical_header[i]->setText(QString::number(day.addDays(6).weekNumber()));
        ui->layout_table->addWidget(vertical_header[i], i * 4 + 1, 0, 4, 1);

        for (int j = 0; j < Const::WEEK_DAYS; j++)
        {
            day_table[i][j]->ClearEvents();
            day_table[i][j]->SetDate(day);
            day_table[i][j]->setAcceptDrops(Setting::EnableDragsAndDrops);

            bool isTransparent = day.month() != first.month();

            if (day_color.find(day) != day_color.end())
                day_table[i][j]->SetBackgroundThemeColor(day_color[day], isTransparent);
            else
                day_table[i][j]->SetBackgroundThemeColor(Setting::CellColor, isTransparent);

            if (Const::IsWeekend(day.dayOfWeek()))
                day_table[i][j]->SetTitleTextColor(Qt::red);
            else
                day_table[i][j]->SetTitleTextColor(Qt::black);

            ui->layout_table->addWidget(day_table[i][j], i * 4 + 1, j + 1, 4, 1);
            day = day.addDays(1);
        }
    }
    loadEvents();
    emit tableUpdated();
}
//加载事件
void MainWindow::loadEvents()
{
    int eventCount[Const::MONTH_WEEKS][Const::WEEK_DAYS] = {0};
    for (auto i : event_labels) i->deleteLater();
    event_labels.clear();

    for (auto i = event_list.rbegin(); i != event_list.rend(); i++)
    {
        AbstractEvent* event = *i;
        for (int i = 0; i < Const::MONTH_WEEKS; i++)
            for (int j = 0, span; span = 1, j < Const::WEEK_DAYS; j += span) if (event->InList(day_table[i][j]->Date()))
            {
                if (event->Type() == AbstractEvent::ContinuousEvent)
                {
                    for (span = 1; j + span < Const::WEEK_DAYS && event->InList(day_table[i][j + span]->Date()); span++);
                }
                else if (event->Type() == AbstractEvent::RecurrentEvent)
                    span = 1;

                int num = 0;
                for (int k = 0; k < span; k++)
                {
                    num = max(num, eventCount[i][j + k]);
                    day_table[i][j + k]->AddEvent(event);
                }

                if (num < 3)
                {
                    for (int k = 0; k < span; k++) eventCount[i][j + k] = num + 1;

                    EventLabelButton* label = new EventLabelButton(event->Title(), event, this);
                    label->setMaximumHeight(20);
                    event_labels.push_back(label);
                    label->setAcceptDrops(Setting::EnableDragsAndDrops);
                    ui->layout_table->addWidget(label, i * 4 + num + 2, j + 1, 1, span);

                    connect(label, &LabelButton::mouseLeave, this, [this]()
                    {
                        EventLabelButton* sender = static_cast<EventLabelButton*>(QObject::sender());
                        for (auto i : event_labels)
                            if (i->Event() == sender->Event()) i->ShowReleasedStyle();
                    });
                    connect(label, &LabelButton::mouseEnter, this, [this]()
                    {
                        EventLabelButton* sender = static_cast<EventLabelButton*>(QObject::sender());
                        for (auto i : event_labels)
                            if (i->Event() == sender->Event()) i->ShowEnterStyle();
                    });
                    connect(label, &LabelButton::pressed, this, [this]()
                    {
                        EventLabelButton* sender = static_cast<EventLabelButton*>(QObject::sender());
                        for (auto i : event_labels)
                            if (i->Event() == sender->Event()) i->ShowPressedStyle();
                    });
                    connect(label, &LabelButton::released, this, [this]()
                    {
                        EventLabelButton* sender = static_cast<EventLabelButton*>(QObject::sender());
                        for (auto i : event_labels)
                            if (i->Event() == sender->Event()) i->ShowReleasedStyle();
                    });
                }
            }
    }
}
//导入数据
void MainWindow::importData(const QString& fileName, bool showMessageBox)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        if (showMessageBox) QMessageBox::critical(0, tr("Fail to Import Data"), QString(tr("Cannot import data from \"%1\"!")).arg(fileName));
        return;
    }

    QDataStream in(&file);
    int size;
    in >> size;
    for (int i = 0; i < size; i++)
    {
        AbstractEvent* event;
        in >> &event;
        bool ok = true;
        for (auto j : event_list)
            if (j->MagicString() == event->MagicString()) ok = false;
        if (ok) event_list.push_back(event);
    }
    in >> size;
    for (int i = 0; i < size; i++)
    {
        QDate date; QColor color;
        in >> date >> color;
        day_color[date] = color;
    }
    file.close();
}
//导出数据
void MainWindow::exportData(const QString& fileName, bool showMessageBox)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        if (showMessageBox) QMessageBox::critical(0, tr("Fail to Export Data"), QString(tr("Cannot export data to \"%1\"!")).arg(fileName));
        return;
    }

    QDataStream out(&file);
    out << (int)event_list.size();
    for (auto i : event_list) out << i;
    out << (int)day_color.size();
    for (auto i : day_color) out << i.first << i.second;
    file.close();
}


//显示标签文本 菜单
void MainWindow::onDayWidgetContextMenu(const QPoint& pos)
{
    DayWidget* sender = static_cast<DayWidget*>(QObject::sender());
    if (!sender->rect().contains(pos)) return;

    dayWidgetByAction = sender;
    eventByAction = nullptr;
    dateByAction = sender->Date();

    action_add_event->setText(tr("&Add Event..."));
    action_show_day->setText(tr("&Show All Events..."));

    ColorMenu color_menu(tr("Backgruond &Color"), this);
    color_menu.SetDefaultColor(sender->ThemeColor());

    QMenu menu(this);
    menu.addAction(action_add_event);
    menu.addAction(action_show_day);
    menu.addSeparator();
    menu.addMenu(&color_menu);

    menu.exec(QCursor::pos());

    if (color_menu.ColorSelected())
    {
        day_color[dateByAction] = color_menu.SelectedColor();
        loadTable();
    }
    dayWidgetByAction = nullptr;
}
//标签文本 对应的菜单项选中处理
void MainWindow::onEventLabelContextMenu(const QPoint& pos)
{
    EventLabelButton* label = static_cast<EventLabelButton*>(QObject::sender());
    AbstractEvent* event = label->Event();
    QPoint mousePos = label->pos() + pos;
    if (!label->rect().contains(pos)) return;

    eventLabelByAction = label;
    eventByAction = event;

    ColorMenu color_menu(tr("Backgruond &Color"), this);
    color_menu.SetDefaultColor(label->BackgroundColor());

    if (label->parent() == ui->centralWidget)
    {
        for (int i = 0; i < Const::MONTH_WEEKS; i++)
            for (int j = 0; j < Const::WEEK_DAYS; j++)
                if (day_table[i][j]->geometry().contains(mousePos))
                    dateByAction = day_table[i][j]->Date();
    }

    QMenu menu(this);
    action_edit_event->setText(tr("&Edit Event"));
    if (event->Type() == AbstractEvent::ContinuousEvent)
    {
        action_delete_event->setText(tr("&Remove Event"));

        menu.addAction(action_edit_event);
        menu.addSeparator();
        menu.addAction(action_delete_event);
        menu.addSeparator();
        menu.addMenu(&color_menu);
    }
    else if (event->Type() == AbstractEvent::RecurrentEvent)
    {
        action_delete_event->setText(tr("Remove the Whole Event &Sequence"));
        action_delete_one_event->setText(tr("Remove &Single Event"));

        menu.addAction(action_edit_event);
        menu.addSeparator();
        menu.addAction(action_delete_event);
        menu.addAction(action_delete_one_event);
        menu.addSeparator();
        menu.addMenu(&color_menu);
    }

    menu.exec(QCursor::pos());

    if (color_menu.ColorSelected())
    {
        eventByAction->SetLabelColor(color_menu.SelectedColor());
        loadTable();
    }
    eventLabelByAction = nullptr;
}
//添加一个事件的事件
void MainWindow::onAddEvent()
{
    AddEventDialog dialog(dateByAction, this);
    if (dialog.exec() == QDialog::Accepted)
    {
        event_list.push_back(dialog.GetEvent());
        loadTable();
    }
}
//编辑件的事件
void MainWindow::onEditEvent()
{
    EventLabelButton* label = eventLabelByAction;
    if (label == nullptr) label = static_cast<EventLabelButton*>(QObject::sender());
    AbstractEvent* event = label->Event();

    AddEventDialog dialog(event, this);
    if (dialog.exec() == QDialog::Accepted) loadTable();
}
//删除同一类标签的所有事件的事件
void MainWindow::onDeleteEvent()
{
    if (QMessageBox::question(this, tr("Remove Event"), QString(tr("Are you sure you want to remove the event \"%1\" and it's all attachments?")).arg(eventByAction->Title())) != QMessageBox::Yes)
        return;
    for (auto i = event_list.begin(); i != event_list.end(); i++)
        if (*i == eventByAction)
        {
            (*i)->RemoveAllFiles();
            delete *i;
            event_list.erase(i);
            break;
        }
    loadTable();
}
//删除一个事件的事件
void MainWindow::onDeleteOneEvent()
{
    if (eventByAction->Type() == AbstractEvent::RecurrentEvent)
    {
        RecurrentEvent* event = static_cast<RecurrentEvent*>(eventByAction);
        event->AddSkip(dateByAction);
    }
    loadTable();
}
//显示当天所有事件
void MainWindow::onShowDayDetail()
{
    DayWidget* sender = dayWidgetByAction;
    if (sender == nullptr) sender = static_cast<DayWidget*>(QObject::sender());
    DayDetailDialog dialog(sender, this);

    dateByAction = sender->Date();
    connect(this, &MainWindow::tableUpdated, &dialog, &DayDetailDialog::loadLabels);

    dialog.exec();
}
//添加文件
void MainWindow::onAddFile(const QString& filePath)
{
    DayWidget* sender = static_cast<DayWidget*>(QObject::sender());

    ContinuousEvent* event = new ContinuousEvent(sender->Date(), sender->Date());
    event->SetTitle(QString(tr("File \"%2\"")).arg(QFileInfo(filePath).fileName()));
    event->AddFile(filePath, this);
    event_list.push_back(event);
    loadTable();
}
//添加文件事件
void MainWindow::onAddFileToEvent(const QString& filePath)
{
    EventLabelButton* sender = static_cast<EventLabelButton*>(QObject::sender());
    sender->Event()->AddFile(filePath, this);
    loadTable();
}
//菜单
void MainWindow::on_action_menu_triggered()
{
    QRect rect = ui->toolBar->actionGeometry(ui->action_menu);
    main_menu->exec(this->pos() + rect.bottomLeft());
}
//日期
void MainWindow::on_action_date_triggered()
{
    QMenu menu(this);
    menu.addAction(ui->action_today);
    menu.addSeparator();
    menu.addAction(ui->action_select_date);

    QRect rect = ui->toolBar->actionGeometry(ui->action_date);
    menu.exec(this->pos() + rect.bottomLeft());
}
//日期向后
void MainWindow::on_action_left_triggered()
{
    current_date = current_date.addMonths(-1);
    loadTable();
}
//日期向前
void MainWindow::on_action_right_triggered()
{
    current_date = current_date.addMonths(1);
    loadTable();
}
//添加事件
void MainWindow::on_action_add_triggered()
{
    if (current_date < QDate::currentDate())
        dateByAction = QDate::currentDate();
    else
    {
        dateByAction = current_date;
        if (current_date.year() != QDate::currentDate().year() || current_date.month() !=  QDate::currentDate().month())
            dateByAction.setDate(current_date.year(), current_date.month(), 1);
    }
    onAddEvent();
}
//拖动窗体
void MainWindow::on_action_movable_triggered(bool checked)
{
    Setting::Movable = checked;
    ui->action_movable->setToolTip(checked ? tr("Fix") : tr("Move"));
}
//导入
void MainWindow::on_action_import_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Import Data File"),
                                                          QDir::currentPath() + "/" + Setting::UserDirectory + Const::USER_DATA_FILE,
                                                          tr("Calendar Data File (*.cdat)"));
    if (!fileName.isEmpty())
    {
        importData(fileName, true);
        loadTable();
    }
}
//导出
void MainWindow::on_action_export_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export Data File"),
                                                          QDir::homePath(),
                                                          tr("Calendar Data File (*.cdat)"));
    if (!fileName.isEmpty()) exportData(fileName, true);
}
//拖拽
void MainWindow::on_action_dragDrop_triggered(bool checked)
{
    Setting::EnableDragsAndDrops = checked;
    loadTable();
}
//偏好设置
void MainWindow::on_action_preference_triggered()
{
    PreferenceDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        if (!QDir(Setting::UserDirectory).exists()) QDir::current().mkpath(Setting::UserDirectory);
        Setting::SaveSetting(Setting::UserDirectory + Const::SETTING_FILE);
        loadTable();
    }
}

//关于
void MainWindow::on_action_about_triggered()
{
    QMessageBox msgBox(this);
    msgBox.setWindowTitle(tr("About LIFE PLAN"));
    msgBox.setText(QString(tr(
                      "<h2>LIFE PLAN<br/></h2>"
                      "<p>基于 Qt 5.12.0<br/></p>"
                      "<p>版本: %2</p>"
                      "<p>创建时间: %2 - %3<br/></p>"
                      )).arg("1.0.0").arg(__DATE__).arg(__TIME__));
    msgBox.exec();
}
//回到今天
void MainWindow::on_action_today_triggered()
{
    current_date = QDate::currentDate();
    loadTable();
}
//日期选择
void MainWindow::on_action_select_date_triggered()
{
    DateSelectDialog dialog(current_date, this);
    if (dialog.exec() == QDialog::Accepted)
    {
        current_date = dialog.SelectedDate();
        loadTable();
    }
}
//登出账号
void MainWindow::on_action_logout_triggered()
{
    if (!QDir(Setting::UserDirectory).exists()) QDir::current().mkpath(Setting::UserDirectory);
    exportData(QDir::currentPath() + "/" + Setting::UserDirectory + Const::USER_DATA_FILE);

    qApp->quit();
    QProcess::startDetached(qApp->applicationFilePath(), QStringList());
}
