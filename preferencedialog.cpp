#include "const.h"
#include "setting.h"
#include "preferencedialog.h"
#include "ui_preferencedialog.h"

#include <QDate>
#include <QPainter>
#include <QPushButton>
#include <QFileDialog>
#include <QFontDialog>

// 静态变量，用于记录触发颜色操作的按钮
static QPushButton* buttonByAction;

// 偏好设置对话框的构造函数
PreferenceDialog::PreferenceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferenceDialog),
    color_menu(new ColorMenu("", this))  // 初始化颜色菜单
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);  // 设置对话框标志

    // 为周首日下拉框添加星期选项
    for (int i = 1; i <= 7; i++)
        ui->comboBox_weekFirstDay->addItem(Translator::Locale(Setting::Language).dayName(i, QLocale::LongFormat));

    loadSetting();  // 加载当前设置
}

// 析构函数
PreferenceDialog::~PreferenceDialog()
{
    delete ui;
}

// 设置按钮字体并更新按钮显示
void PreferenceDialog::setButtonFont(QPushButton* button, const QFont& font)
{
    button_font[button] = font;  // 保存字体到映射表

    // 计算合适的按钮尺寸
    QFontMetrics fm(font);
    QSize size = fm.size(Qt::TextSingleLine, font.family());
    if (size.height() < 24) size.setHeight(24);
    if (size.width() < 64) size.setWidth(64);
    int offset = size.height() / 4;

    // 设置按钮属性
    button->setFixedSize(size + QSize(offset, offset));
    button->setIconSize(size);

    // 创建字体预览图标
    QPixmap pixmap(button->iconSize());
    pixmap.fill(Qt::white);
    QPainter painter(&pixmap);
    painter.setFont(font);
    painter.drawText(QRectF(QPoint(0, 0), pixmap.size()), Qt::AlignCenter, font.family());
    button->setIcon(pixmap);
}

// 设置按钮颜色并更新按钮显示
void PreferenceDialog::setButtonColor(QPushButton* button, const QColor& color)
{
    button_color[button] = color;  // 保存颜色到映射表

    // 计算合适的按钮尺寸
    QFontMetrics fm(Setting::InterfaceFont);
    QSize size = fm.size(Qt::TextSingleLine, Setting::InterfaceFont.family());
    if (size.height() < 24) size.setHeight(24);
    if (size.width() < 64) size.setWidth(64);
    int offset = size.height() / 4;

    // 设置按钮属性
    button->setFixedSize(size);
    button->setIconSize(size - QSize(offset, offset));

    // 创建颜色预览图标
    QPixmap pixmap(button->iconSize());
    pixmap.fill(color);
    button->setIcon(pixmap);
}

// 加载当前设置到UI
void PreferenceDialog::loadSetting()
{
    ui->checkBox_dragDrop->setChecked(Setting::EnableDragsAndDrops);  // 拖放功能
    ui->checkBox_showWeek->setChecked(Setting::ShowWeekNumber);       // 显示周数
    ui->comboBox_weekFirstDay->setCurrentIndex(Setting::WeekFirstDay - 1);  // 周首日
    setButtonFont(ui->pushButton_interfaceFont, Setting::InterfaceFont);  // 界面字体
    ui->comboBox_language->setCurrentIndex(Setting::Language);         // 语言设置
    ui->comboBox_opacity->setCurrentIndex(10 - Setting::Opacity);     // 透明度

    ui->comboBox_cellSpace->setCurrentIndex(Setting::CellSpace);      // 单元格间距
    setButtonColor(ui->pushButton_cellColor, Setting::CellColor);     // 单元格颜色

    setButtonFont(ui->pushButton_eventFont, Setting::EventFont);      // 事件字体
    setButtonColor(ui->pushButton_eventColor_1, Setting::ContinuousEventColor);  // 连续事件颜色
    setButtonColor(ui->pushButton_eventColor_2, Setting::RecurrentEventColor);   // 重复事件颜色
}

// 确认设置并保存
void PreferenceDialog::accept()
{
    // 从UI获取设置值
    Setting::EnableDragsAndDrops = ui->checkBox_dragDrop->isChecked();
    Setting::ShowWeekNumber = ui->checkBox_showWeek->isChecked();
    Setting::WeekFirstDay = ui->comboBox_weekFirstDay->currentIndex() + 1;
    Setting::Language = (Translator::Language)ui->comboBox_language->currentIndex();
    Setting::Opacity = 10 - ui->comboBox_opacity->currentIndex();
    Setting::CellSpace = ui->comboBox_cellSpace->currentIndex();

    // 获取字体和颜色设置
    Setting::InterfaceFont = button_font[ui->pushButton_interfaceFont];
    Setting::EventFont = button_font[ui->pushButton_eventFont];
    Setting::CellColor = button_color[ui->pushButton_cellColor];
    Setting::ContinuousEventColor = button_color[ui->pushButton_eventColor_1];
    Setting::RecurrentEventColor = button_color[ui->pushButton_eventColor_2];

    Translator::InstallToApplication(Setting::Language);  // 应用语言设置

    QDialog::accept();  // 关闭对话框
}

// 导入设置文件
void PreferenceDialog::on_pushButton_import_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("导入配置文件"),
                                                          QDir::currentPath() + "/" + Setting::UserDirectory + Const::SETTING_FILE,
                                                          tr("配置文件 (*.xml)"));
    if (!fileName.isEmpty()) Setting::LoadSetting(fileName);
    loadSetting();  // 重新加载设置
}

// 导出设置文件
void PreferenceDialog::on_pushButton_export_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("导出配置文件"),
                                                          QDir::homePath() + "/" + Const::SETTING_FILE,
                                                          tr("配置文件 (*.xml)"));
    if (!fileName.isEmpty()) Setting::SaveSetting(fileName);
}

// 界面字体按钮点击事件
void PreferenceDialog::on_pushButton_interfaceFont_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, button_font[ui->pushButton_interfaceFont], this);
    if (ok) setButtonFont(ui->pushButton_interfaceFont, font);
}

// 事件字体按钮点击事件
void PreferenceDialog::on_pushButton_eventFont_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, button_font[ui->pushButton_eventFont], this);
    if (ok) setButtonFont(ui->pushButton_eventFont, font);
}

// 单元格颜色按钮点击事件
void PreferenceDialog::on_pushButton_cellColor_clicked()
{
    color_menu->SetDefaultColor(button_color[buttonByAction = ui->pushButton_cellColor]);
    QPoint pos = ui->groupBox_3->mapToGlobal(ui->pushButton_cellColor->geometry().bottomLeft());
    color_menu->exec(pos);  // 显示颜色菜单
    if (color_menu->ColorSelected())
        setButtonColor(ui->pushButton_cellColor, color_menu->SelectedColor());
}

// 连续事件颜色按钮点击事件
void PreferenceDialog::on_pushButton_eventColor_1_clicked()
{
    color_menu->SetDefaultColor(button_color[buttonByAction = ui->pushButton_eventColor_1]);
    QPoint pos = ui->groupBox_4->mapToGlobal(ui->pushButton_eventColor_1->geometry().bottomLeft());
    color_menu->exec(pos);
    if (color_menu->ColorSelected())
        setButtonColor(ui->pushButton_eventColor_1, color_menu->SelectedColor());
}

// 重复事件颜色按钮点击事件
void PreferenceDialog::on_pushButton_eventColor_2_clicked()
{
    color_menu->SetDefaultColor(button_color[buttonByAction = ui->pushButton_eventColor_2]);
    QPoint pos = ui->groupBox_4->mapToGlobal(ui->pushButton_eventColor_2->geometry().bottomLeft());
    color_menu->exec(pos);
    if (color_menu->ColorSelected())
        setButtonColor(ui->pushButton_eventColor_2, color_menu->SelectedColor());
}

// 对话框按钮点击事件
void PreferenceDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    // 如果是最后一个按钮(恢复默认设置)
    if (button == ui->buttonBox->buttons().last())
    {
        // 重置所有设置为默认值
        ui->checkBox_dragDrop->setChecked(true);
        ui->checkBox_showWeek->setChecked(true);
        ui->comboBox_weekFirstDay->setCurrentIndex(0);
        ui->comboBox_language->setCurrentIndex(0);
        ui->comboBox_opacity->setCurrentIndex(0);
        setButtonFont(ui->pushButton_interfaceFont, QFont("微软雅黑", 9));

        ui->comboBox_cellSpace->setCurrentIndex(2);
        setButtonColor(ui->pushButton_cellColor, Const::COLOR_LIST[14]);

        setButtonColor(ui->pushButton_eventColor_1, Const::COLOR_LIST[11]);
        setButtonColor(ui->pushButton_eventColor_2, Const::COLOR_LIST[10]);
        setButtonFont(ui->pushButton_eventFont, QFont("微软雅黑", 9));
    }
}
