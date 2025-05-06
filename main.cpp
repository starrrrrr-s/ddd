#include "mainwindow.h"
#include "translator.h"
#include "logindialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //获取当前时间
    qsrand(QTime::currentTime().msecsSinceStartOfDay());

    QApplication a(argc, argv);
    //将英文转为中文
    Translator::InstallToApplication(Translator::SimplifiedChinese);
    LoginDialog dialog;
    //判断是否登录成功
    if (dialog.exec() != QDialog::Accepted) return 0;
    //成功登录显示主窗体
    MainWindow w(dialog.Username());
    w.show();

    return a.exec();
}
