#include "logindialog.h"
#include "registerdialog.h"
#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QMainWindow>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
LoginDialog::LoginDialog(MainWindow *mainWindow, QWidget *parent)
    : QDialog(parent), m_mainWindow(mainWindow)
{
    setWindowTitle("用户登录");
    setFixedSize(400, 250);

    // 移除问号按钮
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(15);

    // 表单布局
    QFormLayout *formLayout = new QFormLayout();
    formLayout->setSpacing(15);
    formLayout->setContentsMargins(10, 10, 10, 10);

    phoneEdit = new QLineEdit(this);
    phoneEdit->setPlaceholderText("请输入11位手机号");
    phoneEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("\\d{11}"), this));

    passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("8-16位大小写字母+数字");
    passwordEdit->setEchoMode(QLineEdit::Password);

    formLayout->addRow("手机号：", phoneEdit);
    formLayout->addRow("密码：", passwordEdit);
    mainLayout->addLayout(formLayout);

    // 错误提示
    errorLabel = new QLabel(this);
    errorLabel->setStyleSheet("color: red; font-size: 12px;");
    errorLabel->setWordWrap(true);
    mainLayout->addWidget(errorLabel);

    // 按钮
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->setSpacing(15);

    QPushButton *loginButton = new QPushButton("登录", this);
    loginButton->setFixedHeight(40);
    loginButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #2196F3;"
        "   color: white;"
        "   border: none;"
        "   border-radius: 4px;"
        "   font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #0b7dda;"
        "}"
    );

    QPushButton *registerButton = new QPushButton("注册", this);
    registerButton->setFixedHeight(40);
    registerButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #f44336;"
        "   color: white;"
        "   border: none;"
        "   border-radius: 4px;"
        "   font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #da190b;"
        "}"
    );

    buttonLayout->addWidget(loginButton);
    buttonLayout->addWidget(registerButton);
    mainLayout->addLayout(buttonLayout);

    // 连接信号槽
    connect(loginButton, &QPushButton::clicked, this, &LoginDialog::onLoginClicked);
    connect(registerButton, &QPushButton::clicked, this, &LoginDialog::onRegisterClicked);
}

QString LoginDialog::getPhone() const { return phoneEdit->text(); }
QString LoginDialog::getPassword() const { return passwordEdit->text(); }

void LoginDialog::onLoginClicked()
{
    QString phone = phoneEdit->text();
    QString password = passwordEdit->text();

    if(phone.length() != 11) {
        errorLabel->setText("手机号必须为11位数字");
        return;
    }

    QRegularExpression passwordRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[a-zA-Z\\d]{8,16}$");
    if(!passwordRegex.match(password).hasMatch()) {
        errorLabel->setText("密码必须包含大小写字母和数字，8-16位");
        return;
    }

    // 初始化数据库查询
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        errorLabel->setText("数据库连接失败");
        return;
    }

    QSqlQuery query(db);
    query.prepare("SELECT * FROM users WHERE phone = ? AND password = ?");
    query.addBindValue(phone);
    query.addBindValue(password);

    if(query.exec() && query.next())
    {
        // 登录成功后设置当前用户
        if (m_mainWindow) {
            m_mainWindow->setCurrentUserPhone(phone);
            m_mainWindow->loadEventsFromDatabase(); // 加载用户事件
        }
        accept(); // 登录成功
    }
    else
    {
            errorLabel->setText("账号或密码错误");
        }
}

void LoginDialog::onRegisterClicked()
{
    RegisterDialog registerDialog(this);
    connect(&registerDialog, &RegisterDialog::registered, this, [this, &registerDialog]() {
        phoneEdit->setText(registerDialog.getPhone());
        passwordEdit->clear();
    });

    registerDialog.exec();
}
