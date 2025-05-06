#include "const.h" // 包含常量定义的头文件
#include "setting.h" // 包含当前文件的头文件

#include <QFile> // 包含文件操作相关的头文件
#include <QTextStream> // 包含文本流操作相关的头文件
#include <QDomDocument> // 包含XML文档操作相关的头文件

// 个人设置类
QString Setting::UserDirectory = ""; // 用户目录路径，默认为空
bool Setting::Movable = false; // 是否可移动，默认为不可移动

bool Setting::EnableDragsAndDrops = true; // 是否启用拖放功能，默认启用
bool Setting::ShowWeekNumber = true; // 是否显示周数，默认显示
int Setting::WeekFirstDay = 1; // 每周的第一天，默认为1（周一）
Translator::Language Setting::Language = Translator::SimplifiedChinese; // 当前语言，默认为简体中文
int Setting::Opacity = 10; // 窗口透明度，默认值为10
int Setting::CellSpace = 2; // 单元格间距，默认值为2
QFont Setting::InterfaceFont = QFont("微软雅黑", 9); // 界面字体，默认为微软雅黑，字号9
QFont Setting::EventFont = QFont("微软雅黑", 9); // 事件字体，默认为微软雅黑，字号9
QColor Setting::CellColor = Const::COLOR_LIST[14]; // 单元格颜色，默认为COLOR_LIST中的第14个颜色
QColor Setting::ContinuousEventColor = Const::COLOR_LIST[11]; // 连续事件颜色，默认为COLOR_LIST中的第11个颜色
QColor Setting::RecurrentEventColor = Const::COLOR_LIST[10]; // 重复事件颜色，默认为COLOR_LIST中的第10个颜色

// 加载设置的函数
void Setting::LoadSetting(const QString &fileName)
{
    QFile file(fileName); // 打开指定的设置文件
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return; // 如果文件无法打开，直接返回

    QDomDocument doc; // 创建一个XML文档对象
    if (!doc.setContent(&file)) { file.close(); return; } // 如果无法解析文件内容，关闭文件并返回

    QDomElement root = doc.documentElement(); // 获取XML文档的根节点
    if (root.isNull() || root.tagName() != "Setting") { file.close(); return; } // 如果根节点为空或不是"Setting"，关闭文件并返回

    QDomNodeList list = root.childNodes(); // 获取根节点的所有子节点

    // 遍历所有子节点
    for (int i = 0; i < list.count(); i++)
    {
        QDomElement node = list.item(i).toElement(); // 获取当前节点
        // 根据节点的名称和属性，更新设置变量
        if (node.tagName() == "EnableDragsAndDrops" && node.hasAttribute("value"))
            EnableDragsAndDrops = node.attribute("value").toInt(); // 更新拖放功能设置

        if (node.tagName() == "ShowWeekNumber" && node.hasAttribute("value"))
            ShowWeekNumber = node.attribute("value").toInt(); // 更新周数显示设置

        if (node.tagName() == "WeekFirstDay" && node.hasAttribute("value"))
            WeekFirstDay = node.attribute("value").toInt(); // 更新每周第一天设置

        if (node.tagName() == "Language" && node.hasAttribute("value"))
            Language = (Translator::Language)node.attribute("value").toInt(); // 更新语言设置

        if (node.tagName() == "Opacity" && node.hasAttribute("value"))
            Opacity = node.attribute("value").toInt(); // 更新透明度设置

        if (node.tagName() == "CellSpace" && node.hasAttribute("value"))
            CellSpace = node.attribute("value").toInt(); // 更新单元格间距设置

        if (node.tagName() == "InterfaceFont" && node.hasAttribute("value"))
            InterfaceFont.fromString(node.attribute("value")); // 更新界面字体设置

        if (node.tagName() == "EventFont" && node.hasAttribute("value"))
            EventFont.fromString(node.attribute("value")); // 更新事件字体设置

        if (node.tagName() == "CellColor" && node.hasAttribute("value"))
            CellColor = QColor(node.attribute("value")); // 更新单元格颜色设置

        if (node.tagName() == "ContinuousEventColor" && node.hasAttribute("value"))
            ContinuousEventColor = QColor(node.attribute("value")); // 更新连续事件颜色设置

        if (node.tagName() == "RecurrentEventColor" && node.hasAttribute("value"))
            RecurrentEventColor = QColor(node.attribute("value")); // 更新重复事件颜色设置
    }
    file.close(); // 关闭文件
}

// 保存设置的函数
void Setting::SaveSetting(const QString &fileName)
{
    QDomDocument doc; // 创建一个XML文档对象
    QDomProcessingInstruction xml = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\""); // 创建XML声明
    doc.appendChild(xml); // 将XML声明添加到文档中

    QDomElement root = doc.createElement("Setting"); // 创建根节点
    doc.appendChild(root); // 将根节点添加到文档中

    // 创建并添加各个设置节点
    QDomElement node = doc.createElement("EnableDragsAndDrops");
    node.setAttribute("value", QString::number(EnableDragsAndDrops)); // 设置拖放功能的值
    root.appendChild(node);

    node = doc.createElement("ShowWeekNumber");
    node.setAttribute("value", QString::number(ShowWeekNumber)); // 设置周数显示的值
    root.appendChild(node);

    node = doc.createElement("WeekFirstDay");
    node.setAttribute("value", QString::number(WeekFirstDay)); // 设置每周第一天的值
    root.appendChild(node);

    node = doc.createElement("Language");
    node.setAttribute("value", QString::number(Language)); // 设置语言的值
    root.appendChild(node);

    node = doc.createElement("Opacity");
    node.setAttribute("value", QString::number(Opacity)); // 设置透明度的值
    root.appendChild(node);

    node = doc.createElement("CellSpace");
    node.setAttribute("value", QString::number(CellSpace)); // 设置单元格间距的值
    root.appendChild(node);

    node = doc.createElement("InterfaceFont");
    node.setAttribute("value", InterfaceFont.toString()); // 设置界面字体的值
    root.appendChild(node);

    node = doc.createElement("EventFont");
    node.setAttribute("value", EventFont.toString()); // 设置事件字体的值
    root.appendChild(node);

    node = doc.createElement("CellColor");
    node.setAttribute("value", CellColor.name()); // 设置单元格颜色的值
    root.appendChild(node);

    node = doc.createElement("ContinuousEventColor");
    node.setAttribute("value", ContinuousEventColor.name()); // 设置连续事件颜色的值
    root.appendChild(node);

    node = doc.createElement("RecurrentEventColor");
    node.setAttribute("value", RecurrentEventColor.name()); // 设置重复事件颜色的值
    root.appendChild(node);

    QFile file(fileName); // 打开指定的设置文件
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return; // 如果文件无法打开，直接返回
    QTextStream out(&file); // 创建文本流
    doc.save(out, 2); // 将XML文档保存到文件中，缩进为2
    file.close(); // 关闭文件
}
