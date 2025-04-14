#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    QString getPhone() const;
    QString getPassword() const;

private slots:
    void onLoginClicked();
    void onRegisterClicked();

private:
    QLineEdit *phoneEdit;
    QLineEdit *passwordEdit;
    QLabel *errorLabel;
};

#endif // LOGINDIALOG_H
