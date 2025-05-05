#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    QString getPhone() const;
    QString getPassword() const;

signals:
    void registered(); // 添加注册成功信号

private slots:
    void onRegisterClicked();

private:
    QLineEdit *phoneEdit;
    QLineEdit *passwordEdit;
    QLineEdit *confirmPasswordEdit; // 添加确认密码输入框
    QLabel *hintLabel;
    QLabel *errorLabel;
};

#endif // REGISTERDIALOG_H
