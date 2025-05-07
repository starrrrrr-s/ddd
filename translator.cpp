#include "const.h" // 包含常量定义的头文件
#include "translator.h" // 包含当前文件的头文件

#include <QApplication> // 包含Qt应用程序相关的头文件

// 语言转换类
// 定义支持的语言的QLocale对象数组
const QLocale Translator::LANGUAGE_LOCALE[3] =
{
   QLocale(QLocale::Chinese, QLocale::SimplifiedChineseScript, QLocale::China), // 简体中文
   QLocale(QLocale::Chinese, QLocale::TraditionalChineseScript, QLocale::HongKong), // 繁体中文
   QLocale(QLocale::English) // 英语
};

// 当前语言，默认为无效语言
Translator::Language Translator::language = Translator::Invalid;
// 用于存储已加载的翻译器对象的列表
std::vector<QTranslator*> Translator::trans_list;

// 将指定语言的翻译器安装到应用程序的函数
void Translator::InstallToApplication(Language lang)
{
    // 如果当前语言与目标语言相同，直接返回
    if (lang == language) return;

    // 设置默认的语言环境为目标语言
    QLocale::setDefault(LANGUAGE_LOCALE[language = lang]);

    // 移除并删除已加载的翻译器对象
    for (auto i : trans_list)
    {
        qApp->removeTranslator(i); // 从应用程序中移除翻译器
        i->deleteLater(); // 延迟删除翻译器对象
    }
    trans_list.clear(); // 清空翻译器列表

    QTranslator* trans; // 用于创建翻译器对象的指针

    // 根据目标语言加载对应的翻译文件
    switch (lang)
    {
    case SimplifiedChinese: // 简体中文
        trans = new QTranslator; // 创建翻译器对象
        trans->load(":/trans/trans/zh_CN.qm"); // 加载简体中文翻译文件
        trans_list.push_back(trans); // 将翻译器对象添加到列表
        qApp->installTranslator(trans); // 将翻译器安装到应用程序

        trans = new QTranslator; // 创建翻译器对象
        trans->load(":/trans/trans/qt_zh_CN.qm"); // 加载Qt的简体中文翻译文件
        trans_list.push_back(trans); // 将翻译器对象添加到列表
        qApp->installTranslator(trans); // 将翻译器安装到应用程序
        break;

    case TraditionalChinese: // 繁体中文
        trans = new QTranslator; // 创建翻译器对象
        trans->load(":/trans/trans/zh_TW.qm"); // 加载繁体中文翻译文件
        trans_list.push_back(trans); // 将翻译器对象添加到列表
        qApp->installTranslator(trans); // 将翻译器安装到应用程序

        trans = new QTranslator; // 创建翻译器对象
        trans->load(":/trans/trans/qt_zh_TW.qm"); // 加载Qt的繁体中文翻译文件
        trans_list.push_back(trans); // 将翻译器对象添加到列表
        qApp->installTranslator(trans); // 将翻译器安装到应用程序
        break;
    }
}
