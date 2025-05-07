#include "setting.h" // 包含设置相关的头文件
#include "mainwindow.h" // 包含主窗口相关的头文件
#include "addeventdialog.h" // 包含添加事件对话框相关的头文件
#include "recurrentevent.h" // 包含重复事件相关的头文件
#include "continuousevent.h" // 包含连续事件相关的头文件
#include "daydetaildialog.h" // 包含当前文件的头文件
#include "ui_daydetaildialog.h" // 包含UI界面相关的头文件

#include <QSignalMapper> // 包含信号映射器相关的头文件

// 每天计划的详细内容类
DayDetailDialog::DayDetailDialog(DayWidget* date, QWidget *parent) :
    QDialog(parent), // 继承自QDialog
    ui(new Ui::DayDetailDialog), // 初始化UI界面
    date(date), // 初始化日期组件
    parent(static_cast<MainWindow*>(parent)), // 初始化父窗口（强制转换为MainWindow类型）
    spacer(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding)) // 初始化一个可伸展的空白占位符
{
    ui->setupUi(this); // 设置UI界面
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint); // 设置窗口标志，显示为对话框并仅显示关闭按钮

    // 设置日期标签的字体
    QFont font = ui->label_day->font();
    font.setFamily(Setting::InterfaceFont.family()); // 设置字体家族
    font.setPointSize(Setting::InterfaceFont.pointSize() * 2); // 设置字体大小为界面字体大小的两倍
    ui->label_day->setFont(font); // 应用字体设置
    // 设置日期标签的文本，显示当前日期
    ui->label_day->setText(QString("%1").arg(Translator::Locale(Setting::Language).toString(date->Date(), QLocale::LongFormat)));

    // 加载标签
    loadLabels();
}

// 析构函数，释放资源
DayDetailDialog::~DayDetailDialog()
{
    delete ui; // 删除UI界面
}

// 加载标签的函数
void DayDetailDialog::loadLabels()
{
    // 清除旧的标签
    for (auto i : label_list) // 遍历标签列表
    {
        ui->verticalLayout->removeWidget(i); // 从布局中移除标签
        i->deleteLater(); // 延迟删除标签
    }
    ui->verticalLayout->removeItem(spacer); // 从布局中移除空白占位符
    label_list.clear(); // 清空标签列表

    // 如果当天没有事件
    if (!date->EventCount())
    {
        QLabel* label = new QLabel(tr("You Have No Events Today~"), this); // 创建一个提示标签
        label->setFixedHeight(40); // 设置固定高度
        label->setAlignment(Qt::AlignCenter); // 设置居中对齐
        ui->verticalLayout->addWidget(label); // 将标签添加到布局中
        return; // 退出函数
    }

    // 遍历当天的事件
    for (int i = 0; i < date->EventCount(); i++)
    {
        AbstractEvent* event = date->EventAt(i); // 获取当前事件
        EventLabelButton* label = new EventLabelButton(event->Title(), event, this->parent); // 创建一个事件标签按钮
        label->setFixedHeight(40); // 设置固定高度
        label_list.push_back(label); // 将标签添加到列表中
        label->setAcceptDrops(Setting::EnableDragsAndDrops); // 设置是否接受拖放操作
        ui->verticalLayout->addWidget(label); // 将标签添加到布局中
    }
    ui->verticalLayout->addItem(spacer); // 将空白占位符添加到布局中
}
