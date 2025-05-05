#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include <QMainWindow>
#include "mainwindow.h"
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
class MainWindow;
class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(MainWindow *mainWindow, QWidget *parent = nullptr);
    QString getPhone() const;
    QString getPassword() const;

private slots:
    void onLoginClicked();
    void onRegisterClicked();

private:
    QLineEdit *phoneEdit;
    QLineEdit *passwordEdit;
    QLabel *errorLabel;
    MainWindow *m_mainWindow;
};

#endif // LOGINDIALOG_H
