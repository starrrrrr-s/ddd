// eventdialog.h
#ifndef EVENTDIALOG_H
#define EVENTDIALOG_H

#include <QDialog>
#include <QDateTime>
#include <QFormLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QDateTimeEdit>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QGroupBox>
#include<QTime>

class EventDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EventDialog(QWidget *parent = nullptr);
    ~EventDialog();

    // 获取事件属性
    QString eventName() const;
    QString eventCategory() const;
    bool isAllDay() const;
    QDateTime startDateTime() const;
    QDateTime endDateTime() const;
    QString timezone() const;
    QString repeatMode() const;
    QString reminder() const;
    bool isSoundEnabled() const;
    QString notes() const;

    // 设置事件属性
    void setEventName(const QString &name);
    void setEventCategory(const QString &category);
    void setAllDay(bool allDay);
    void setStartDateTime(const QDateTime &datetime);
    void setEndDateTime(const QDateTime &datetime);
    void setTimezone(const QString &timezone);
    void setRepeatMode(const QString &mode);
    void setReminder(const QString &reminder);
    void setSoundEnabled(bool enabled);
    void setNotes(const QString &notes);
    void setEventId(int id);
      int eventId() const;

private slots:
    void updateTimeEditors();

private:
    // UI组件
    QComboBox *m_categoryCombo;
    QLineEdit *m_eventNameEdit;
    QCheckBox *m_allDayCheck;
    QDateEdit *m_startDateEdit;
    QTimeEdit *m_startTimeEdit;
    QDateEdit *m_endDateEdit;
    QTimeEdit *m_endTimeEdit;
    QComboBox *m_timezoneCombo;
    QComboBox *m_repeatCombo;
    QComboBox *m_reminderCombo;
    QCheckBox *m_soundCheck;
    QPlainTextEdit *m_noteEdit;
    int m_eventId;

    void setupUI();
    void setupConnections();
    QHBoxLayout* createHBox(QWidget *first, QWidget *second); // 添加这行声明
};

#endif // EVENTDIALOG_H
