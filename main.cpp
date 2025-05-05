#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QMainWindow>


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

// main.cpp
// main.cpp
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // 使用指针动态分配
    MainWindow *mainWindow = new MainWindow();
    LoginDialog login(mainWindow);

    if (login.exec() == QDialog::Accepted) {
        mainWindow->show();
        return a.exec();
    }

    // 登录失败时删除 mainWindow
    delete mainWindow;
    return 0;
}
