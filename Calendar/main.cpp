#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

bool initializeDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("calendar.db");

    if (!db.open()) {
        QMessageBox::critical(nullptr, "错误", "无法打开数据库");
        return false;
    }

    // 创建用户表
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS users ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "phone TEXT UNIQUE NOT NULL, "
                   "password TEXT NOT NULL)")) {
        qDebug() << "创建表失败:" << query.lastError();
        return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 初始化数据库
    if (!initializeDatabase()) {
        return -1;
    }

    // 显示登录对话框
    LoginDialog loginDialog;
    if (loginDialog.exec() != QDialog::Accepted) {
        return 0; // 用户取消登录
    }

    // 登录成功，显示主窗口
    MainWindow w;
    w.show();
    return a.exec();
}
