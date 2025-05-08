/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_menu;
    QAction *action_date;
    QAction *action_left;
    QAction *action_right;
    QAction *action_add;
    QAction *action_movable;
    QAction *action_import;
    QAction *action_export;
    QAction *action_dragDrop;
    QAction *action_preference;
    QAction *action_about;
    QAction *action_exit;
    QAction *action_today;
    QAction *action_select_date;
    QAction *action_logout;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *layout_table;
    QLabel *label_date;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/calendar.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_menu = new QAction(MainWindow);
        action_menu->setObjectName(QStringLiteral("action_menu"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/menu.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_menu->setIcon(icon1);
        action_date = new QAction(MainWindow);
        action_date->setObjectName(QStringLiteral("action_date"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/icons/date.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_date->setIcon(icon2);
        action_left = new QAction(MainWindow);
        action_left->setObjectName(QStringLiteral("action_left"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/icons/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_left->setIcon(icon3);
        action_right = new QAction(MainWindow);
        action_right->setObjectName(QStringLiteral("action_right"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/icons/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_right->setIcon(icon4);
        action_add = new QAction(MainWindow);
        action_add->setObjectName(QStringLiteral("action_add"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_add->setIcon(icon5);
        action_movable = new QAction(MainWindow);
        action_movable->setObjectName(QStringLiteral("action_movable"));
        action_movable->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/icons/move.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_movable->setIcon(icon6);
        action_import = new QAction(MainWindow);
        action_import->setObjectName(QStringLiteral("action_import"));
        action_export = new QAction(MainWindow);
        action_export->setObjectName(QStringLiteral("action_export"));
        action_dragDrop = new QAction(MainWindow);
        action_dragDrop->setObjectName(QStringLiteral("action_dragDrop"));
        action_dragDrop->setCheckable(true);
        action_dragDrop->setChecked(true);
        action_preference = new QAction(MainWindow);
        action_preference->setObjectName(QStringLiteral("action_preference"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/icons/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_preference->setIcon(icon7);
        action_about = new QAction(MainWindow);
        action_about->setObjectName(QStringLiteral("action_about"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/icons/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_about->setIcon(icon8);
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icons/icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon9);
        action_today = new QAction(MainWindow);
        action_today->setObjectName(QStringLiteral("action_today"));
        action_select_date = new QAction(MainWindow);
        action_select_date->setObjectName(QStringLiteral("action_select_date"));
        action_logout = new QAction(MainWindow);
        action_logout->setObjectName(QStringLiteral("action_logout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        layout_table = new QGridLayout();
        layout_table->setSpacing(2);
        layout_table->setObjectName(QStringLiteral("layout_table"));

        gridLayout->addLayout(layout_table, 1, 0, 1, 3);

        label_date = new QLabel(centralWidget);
        label_date->setObjectName(QStringLiteral("label_date"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_date->sizePolicy().hasHeightForWidth());
        label_date->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        label_date->setFont(font);
        label_date->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_date->setIndent(10);

        gridLayout->addWidget(label_date, 0, 0, 1, 3);

        MainWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        toolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);
        QObject::connect(action_exit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calendar", nullptr));
#ifndef QT_NO_TOOLTIP
        action_menu->setToolTip(QApplication::translate("MainWindow", "Main Menu", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        action_date->setToolTip(QApplication::translate("MainWindow", "Goto", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        action_left->setToolTip(QApplication::translate("MainWindow", "Last Month", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        action_right->setToolTip(QApplication::translate("MainWindow", "Next Month", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        action_add->setToolTip(QApplication::translate("MainWindow", "Add Event", nullptr));
#endif // QT_NO_TOOLTIP
        action_import->setText(QApplication::translate("MainWindow", "&Import...", nullptr));
        action_export->setText(QApplication::translate("MainWindow", "&Export...", nullptr));
        action_dragDrop->setText(QApplication::translate("MainWindow", "Enable &Drag and Drop Files", nullptr));
        action_preference->setText(QApplication::translate("MainWindow", "&Preference...", nullptr));
        action_about->setText(QApplication::translate("MainWindow", "&About...", nullptr));
        action_exit->setText(QApplication::translate("MainWindow", "E&xit", nullptr));
        action_today->setText(QApplication::translate("MainWindow", "Goto &Today", nullptr));
        action_select_date->setText(QApplication::translate("MainWindow", "Goto &Date...", nullptr));
        action_logout->setText(QApplication::translate("MainWindow", "&Logout", nullptr));
        label_date->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
