#include "registerdialog.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

RegisterDialog::RegisterDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("用户注册");
    setFixedSize(450, 350); // 进一步增大对话框尺寸

    // 移除问号按钮
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(20, 20, 20, 20); // 设置边距
    mainLayout->setSpacing(15);

    // 表单布局
    QFormLayout *formLayout = new QFormLayout();
    formLayout->setSpacing(15);
    formLayout->setContentsMargins(10, 10, 10, 10);

    phoneEdit = new QLineEdit(this);
    phoneEdit->setPlaceholderText("11位手机号");
    phoneEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("\\d{11}"), this));

    passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("8-16位大小写字母+数字");
    passwordEdit->setEchoMode(QLineEdit::Password);

    confirmPasswordEdit = new QLineEdit(this);
    confirmPasswordEdit->setPlaceholderText("再次输入密码");
    confirmPasswordEdit->setEchoMode(QLineEdit::Password);

    formLayout->addRow("手机号：", phoneEdit);
    formLayout->addRow("密码：", passwordEdit);
    formLayout->addRow("确认密码：", confirmPasswordEdit);
    mainLayout->addLayout(formLayout);

    // 提示标签
    hintLabel = new QLabel("密码要求：8-16位，必须包含大小写字母和数字", this);
    hintLabel->setWordWrap(true); // 允许自动换行
    hintLabel->setStyleSheet("color: #666; font-size: 12px;");
    mainLayout->addWidget(hintLabel);

    // 错误标签
    errorLabel = new QLabel(this);
    errorLabel->setStyleSheet("color: red; font-size: 12px;");
    errorLabel->setWordWrap(true);
    mainLayout->addWidget(errorLabel);

    // 注册按钮
    QPushButton *registerButton = new QPushButton("注册", this);
    registerButton->setFixedHeight(40);
    registerButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #4CAF50;"
        "   color: white;"
        "   border: none;"
        "   border-radius: 4px;"
        "   font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #45a049;"
        "}"
    );
    mainLayout->addWidget(registerButton);

    // 连接信号槽
    connect(registerButton, &QPushButton::clicked, this, &RegisterDialog::onRegisterClicked);
}
QString RegisterDialog::getPhone() const { return phoneEdit->text(); }
QString RegisterDialog::getPassword() const { return passwordEdit->text(); }

void RegisterDialog::onRegisterClicked()
{
    QString phone = phoneEdit->text();
    QString password = passwordEdit->text();
    QString confirmPassword = confirmPasswordEdit->text();

    // 验证手机号
    if(phone.length() != 11) {
        errorLabel->setText("手机号必须为11位数字");
        return;
    }

    // 验证密码
    QRegularExpression passwordRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[a-zA-Z\\d]{8,16}$");
    if(!passwordRegex.match(password).hasMatch()) {
        errorLabel->setText("密码必须包含大小写字母和数字，8-16位");
        return;
    }

    // 验证两次密码是否一致
    if(password != confirmPassword) {
        errorLabel->setText("两次输入的密码不一致");
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        errorLabel->setText("数据库连接失败");
        return;
    }

    // 检查手机号是否已注册
    QSqlQuery checkQuery(db);
    checkQuery.prepare("SELECT * FROM users WHERE phone = ?");
    checkQuery.addBindValue(phone);

    if(checkQuery.exec() && checkQuery.next()) {
        errorLabel->setText("该手机号已注册");
        return;
    }

    // 插入新用户
    QSqlQuery insertQuery(db);
    insertQuery.prepare("INSERT INTO users (phone, password) VALUES (?, ?)");
    insertQuery.addBindValue(phone);
    insertQuery.addBindValue(password);

    if(insertQuery.exec()) {
        QMessageBox::information(this, "注册成功", "账号注册成功，请登录");
        emit registered(); // 发射注册成功信号
        accept();
    } else {
        errorLabel->setText("注册失败，请重试: " + insertQuery.lastError().text());
    }
}
