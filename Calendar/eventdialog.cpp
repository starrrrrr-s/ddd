#include "eventdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

EventDialog::EventDialog(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(tr("编辑日程"));
    resize(400, 550);

    setupUI();
    setupConnections();

    // 设置默认值
    QDateTime now = QDateTime::currentDateTime();
    setStartDateTime(now);
    setEndDateTime(now.addSecs(3600)); // 默认1小时后
}

EventDialog::~EventDialog() {}

void EventDialog::setupUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(10);

    // 1. 日历分类
    QGroupBox *categoryGroup = new QGroupBox(tr("日历分类"), this);
    m_categoryCombo = new QComboBox(categoryGroup);
    m_categoryCombo->addItems({tr("默认日程"), tr("生日"), tr("纪念日")});

    QVBoxLayout *categoryLayout = new QVBoxLayout(categoryGroup);
    categoryLayout->addWidget(m_categoryCombo);
    mainLayout->addWidget(categoryGroup);

    // 2. 事件名称
    m_eventNameEdit = new QLineEdit(this);
    m_eventNameEdit->setPlaceholderText(tr("日程名称"));
    mainLayout->addWidget(m_eventNameEdit);

    // 3. 全天选项
    m_allDayCheck = new QCheckBox(tr("全天"), this);
    mainLayout->addWidget(m_allDayCheck);

    // 4. 时间设置
    QGroupBox *timeGroup = new QGroupBox(tr("时间"), this);
    QFormLayout *timeLayout = new QFormLayout(timeGroup);

    m_startDateEdit = new QDateEdit(QDate::currentDate(), timeGroup);
    m_startDateEdit->setCalendarPopup(true);
    m_startTimeEdit = new QTimeEdit(QTime::currentTime(), timeGroup);

    m_endDateEdit = new QDateEdit(QDate::currentDate(), timeGroup);
    m_endDateEdit->setCalendarPopup(true);
    m_endTimeEdit = new QTimeEdit(QTime::currentTime().addSecs(3600), timeGroup);

    m_timezoneCombo = new QComboBox(timeGroup);
    m_timezoneCombo->addItems({tr("GMT+08:00 北京"), tr("GMT+00:00 伦敦"), tr("GMT-05:00 纽约")});

    timeLayout->addRow(tr("开始:"), createHBox(m_startDateEdit, m_startTimeEdit));
    timeLayout->addRow(tr("结束:"), createHBox(m_endDateEdit, m_endTimeEdit));
    timeLayout->addRow(tr("时区:"), m_timezoneCombo);
    mainLayout->addWidget(timeGroup);

    // 5. 重复设置
    QGroupBox *repeatGroup = new QGroupBox(tr("重复"), this);
    m_repeatCombo = new QComboBox(repeatGroup);
    m_repeatCombo->addItems({tr("仅一次"), tr("每天"), tr("每周"), tr("每月"), tr("每年"), tr("自定义...")});

    QVBoxLayout *repeatLayout = new QVBoxLayout(repeatGroup);
    repeatLayout->addWidget(m_repeatCombo);
    mainLayout->addWidget(repeatGroup);

    // 6. 提醒设置
    QGroupBox *reminderGroup = new QGroupBox(tr("提醒"), this);
    m_reminderCombo = new QComboBox(reminderGroup);
    m_reminderCombo->addItems({tr("无"), tr("15分钟前"), tr("30分钟前"), tr("1小时前"), tr("1天前"), tr("自定义...")});

    m_soundCheck = new QCheckBox(tr("响铃提醒"), reminderGroup);
    m_soundCheck->setChecked(true);

    QVBoxLayout *reminderLayout = new QVBoxLayout(reminderGroup);
    reminderLayout->addWidget(m_reminderCombo);
    reminderLayout->addWidget(m_soundCheck);
    mainLayout->addWidget(reminderGroup);

    // 7. 备注
    m_noteEdit = new QPlainTextEdit(this);
    m_noteEdit->setPlaceholderText(tr("备注"));
    m_noteEdit->setMaximumHeight(100);
    mainLayout->addWidget(m_noteEdit);

    // 8. 按钮区域
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();

    QPushButton *cancelButton = new QPushButton(tr("取消"), this);
    QPushButton *saveButton = new QPushButton(tr("新建日程"), this);
    QPushButton *okButton = new QPushButton(tr("完成"), this);

    saveButton->setStyleSheet("background-color: #1a73e8; color: white;");
    okButton->setStyleSheet("background-color: #1a73e8; color: white;");

    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(okButton);
    mainLayout->addLayout(buttonLayout);

    // 连接按钮信号
    connect(cancelButton, &QPushButton::clicked, this, &EventDialog::reject);
    connect(okButton, &QPushButton::clicked, this, &EventDialog::accept);
    connect(saveButton, &QPushButton::clicked, this, &EventDialog::accept);
}

QHBoxLayout* EventDialog::createHBox(QWidget *first, QWidget *second)
{
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(first);
    layout->addWidget(second);
    layout->setSpacing(5);
    return layout;
}

void EventDialog::setupConnections()
{
    connect(m_allDayCheck, &QCheckBox::toggled, this, &EventDialog::updateTimeEditors);
}

void EventDialog::updateTimeEditors()
{
    bool isAllDay = m_allDayCheck->isChecked();
    m_startTimeEdit->setDisabled(isAllDay);
    m_endTimeEdit->setDisabled(isAllDay);

    if(isAllDay) {
        m_startTimeEdit->setTime(QTime(0, 0));
        m_endTimeEdit->setTime(QTime(23, 59));
    }
}

// Getter方法实现
QString EventDialog::eventName() const { return m_eventNameEdit->text().trimmed(); }
QString EventDialog::eventCategory() const { return m_categoryCombo->currentText(); }
bool EventDialog::isAllDay() const { return m_allDayCheck->isChecked(); }

QDateTime EventDialog::startDateTime() const {
    return QDateTime(m_startDateEdit->date(),
                    isAllDay() ? QTime(0, 0) : m_startTimeEdit->time());
}

QDateTime EventDialog::endDateTime() const {
    return QDateTime(m_endDateEdit->date(),
                    isAllDay() ? QTime(23, 59) : m_endTimeEdit->time());
}

QString EventDialog::timezone() const { return m_timezoneCombo->currentText(); }
QString EventDialog::repeatMode() const { return m_repeatCombo->currentText(); }
QString EventDialog::reminder() const { return m_reminderCombo->currentText(); }
bool EventDialog::isSoundEnabled() const { return m_soundCheck->isChecked(); }
QString EventDialog::notes() const { return m_noteEdit->toPlainText().trimmed(); }

// Setter方法实现
void EventDialog::setEventName(const QString &name) { m_eventNameEdit->setText(name); }

void EventDialog::setEventCategory(const QString &category) {
    int index = m_categoryCombo->findText(category);
    if(index >= 0) m_categoryCombo->setCurrentIndex(index);
}

void EventDialog::setAllDay(bool allDay) {
    m_allDayCheck->setChecked(allDay);
    updateTimeEditors();
}

void EventDialog::setStartDateTime(const QDateTime &datetime) {
    m_startDateEdit->setDate(datetime.date());
    m_startTimeEdit->setTime(datetime.time());
}

void EventDialog::setEndDateTime(const QDateTime &datetime) {
    m_endDateEdit->setDate(datetime.date());
    m_endTimeEdit->setTime(datetime.time());
}

void EventDialog::setTimezone(const QString &timezone) {
    int index = m_timezoneCombo->findText(timezone);
    if(index >= 0) m_timezoneCombo->setCurrentIndex(index);
}

void EventDialog::setRepeatMode(const QString &mode) {
    int index = m_repeatCombo->findText(mode);
    if(index >= 0) m_repeatCombo->setCurrentIndex(index);
}

void EventDialog::setReminder(const QString &reminder) {
    int index = m_reminderCombo->findText(reminder);
    if(index >= 0) m_reminderCombo->setCurrentIndex(index);
}

void EventDialog::setSoundEnabled(bool enabled) {
    m_soundCheck->setChecked(enabled);
}

void EventDialog::setNotes(const QString &notes) {
    m_noteEdit->setPlainText(notes);
}
