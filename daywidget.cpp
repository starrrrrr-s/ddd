#include "setting.h"
#include "daywidget.h"

#include <QPainter>

//显示当天的所有事件的对话框
DayWidget::DayWidget(QWidget *parent) :
    QWidget(parent),
    title(new LabelButton(this)), content(new LabelButton(this))
{
    setup();
}

DayWidget::DayWidget(const QDate& date, QWidget *parent) :
    QWidget(parent),
    date(date), title(new LabelButton(QString::number(date.day()), this)), content(new LabelButton(this))
{
    setup();
}
//重绘事件
void DayWidget::paintEvent(QPaintEvent *event)
{
    if (date!=QDate::currentDate()) return;
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setBrush(Qt::red);
    painter.drawRect(QRect(-1, -1, this->width() + 1, this->height() + 1));
}


void DayWidget::mousePressEvent(QMouseEvent *event)
{
    if (!Setting::Movable) { event->ignore(); return;}
    QWidget::mousePressEvent(event);
    if (event->button() == Qt::LeftButton)
    {
        title->ShowPressedStyle();
        content->ShowPressedStyle();
    }
}

void DayWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (!Setting::Movable) { event->ignore(); return;}
    QWidget::mouseReleaseEvent(event);
    if (event->button() == Qt::LeftButton)
    {
        title->ShowReleasedStyle();
        content->ShowReleasedStyle();
        emit clicked();
    }
}
//设置时间
void DayWidget::SetDate(const QDate &date)
{
    this->date = date;
    if (date.day() == 1)
        title->setText(date.toString("M/d"));
    else
        title->setText(QString::number(date.day()));

    if (date == QDate::currentDate())
    {
        layout->setMargin(3);
        title->setFixedHeight(22);
    }
    else
    {
        layout->setMargin(0);
        title->setFixedHeight(25);
    }
    this->update();
}
//将计划内容加载到对话框
void DayWidget::setup()
{
    layout = new QGridLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);
    this->setLayout(layout);
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    title->setAcceptDrops(true);
    content->setAcceptDrops(true);

    layout->addWidget(title);
    layout->addWidget(content);

    title->setFixedHeight(25);
    title->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    title->setAlignment(Qt::AlignCenter);

    SetBackgroundThemeColor(Qt::white);

    connect(title,   &LabelButton::pressed, content, &LabelButton::ShowPressedStyle);
    connect(content, &LabelButton::pressed, title,   &LabelButton::ShowPressedStyle);

    connect(title,   &LabelButton::released, content, &LabelButton::ShowReleasedStyle);
    connect(content, &LabelButton::released, title,   &LabelButton::ShowReleasedStyle);

    connect(title,   &LabelButton::dropIn, this, &DayWidget::dropIn);
    connect(content, &LabelButton::dropIn, this, &DayWidget::dropIn);
}
//设置背景颜色
void DayWidget::SetBackgroundThemeColor(const QColor &color, bool isTransparent)
{
    QColor fuck = color;
    if (isTransparent) fuck.setAlpha(150);
    SetTitleBackgroundColor(fuck.light(135));
    SetContentBackgroundColor(fuck);
}
