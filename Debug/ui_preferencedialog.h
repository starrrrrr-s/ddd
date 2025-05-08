/********************************************************************************
** Form generated from reading UI file 'preferencedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCEDIALOG_H
#define UI_PREFERENCEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PreferenceDialog
{
public:
    QGridLayout *gridLayout_9;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QGridLayout *gridLayout_7;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_8;
    QCheckBox *checkBox_dragDrop;
    QGroupBox *groupBox_1;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_5;
    QLabel *label_8;
    QPushButton *pushButton_interfaceFont;
    QComboBox *comboBox_opacity;
    QGroupBox *groupBox_0;
    QGridLayout *gridLayout_5;
    QLabel *label;
    QComboBox *comboBox_weekFirstDay;
    QLabel *label_7;
    QComboBox *comboBox_language;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *checkBox_showWeek;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox_cellSpace;
    QLabel *label_6;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_cellColor;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_eventColor_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_9;
    QPushButton *pushButton_eventColor_1;
    QPushButton *pushButton_eventFont;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton_import;
    QPushButton *pushButton_export;

    void setupUi(QDialog *PreferenceDialog)
    {
        if (PreferenceDialog->objectName().isEmpty())
            PreferenceDialog->setObjectName(QStringLiteral("PreferenceDialog"));
        PreferenceDialog->resize(500, 338);
        gridLayout_9 = new QGridLayout(PreferenceDialog);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        tabWidget = new QTabWidget(PreferenceDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        gridLayout_7 = new QGridLayout(tab_1);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_3, 3, 0, 1, 1);

        groupBox_2 = new QGroupBox(tab_1);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_8 = new QGridLayout(groupBox_2);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        checkBox_dragDrop = new QCheckBox(groupBox_2);
        checkBox_dragDrop->setObjectName(QStringLiteral("checkBox_dragDrop"));

        gridLayout_8->addWidget(checkBox_dragDrop, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_2, 2, 0, 1, 1);

        groupBox_1 = new QGroupBox(tab_1);
        groupBox_1->setObjectName(QStringLiteral("groupBox_1"));
        gridLayout_6 = new QGridLayout(groupBox_1);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_7, 0, 2, 2, 1);

        label_5 = new QLabel(groupBox_1);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_6->addWidget(label_5, 1, 0, 1, 1);

        label_8 = new QLabel(groupBox_1);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_6->addWidget(label_8, 0, 0, 1, 1);

        pushButton_interfaceFont = new QPushButton(groupBox_1);
        pushButton_interfaceFont->setObjectName(QStringLiteral("pushButton_interfaceFont"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_interfaceFont->sizePolicy().hasHeightForWidth());
        pushButton_interfaceFont->setSizePolicy(sizePolicy);
        pushButton_interfaceFont->setIconSize(QSize(56, 16));

        gridLayout_6->addWidget(pushButton_interfaceFont, 0, 1, 1, 1);

        comboBox_opacity = new QComboBox(groupBox_1);
        comboBox_opacity->addItem(QString());
        comboBox_opacity->addItem(QString());
        comboBox_opacity->addItem(QString());
        comboBox_opacity->addItem(QString());
        comboBox_opacity->addItem(QString());
        comboBox_opacity->addItem(QString());
        comboBox_opacity->addItem(QString());
        comboBox_opacity->addItem(QString());
        comboBox_opacity->addItem(QString());
        comboBox_opacity->addItem(QString());
        comboBox_opacity->addItem(QString());
        comboBox_opacity->setObjectName(QStringLiteral("comboBox_opacity"));
        sizePolicy.setHeightForWidth(comboBox_opacity->sizePolicy().hasHeightForWidth());
        comboBox_opacity->setSizePolicy(sizePolicy);
        comboBox_opacity->setMaxVisibleItems(11);
        comboBox_opacity->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_6->addWidget(comboBox_opacity, 1, 1, 1, 1);


        gridLayout_7->addWidget(groupBox_1, 1, 0, 1, 1);

        groupBox_0 = new QGroupBox(tab_1);
        groupBox_0->setObjectName(QStringLiteral("groupBox_0"));
        gridLayout_5 = new QGridLayout(groupBox_0);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label = new QLabel(groupBox_0);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_5->addWidget(label, 1, 0, 1, 1);

        comboBox_weekFirstDay = new QComboBox(groupBox_0);
        comboBox_weekFirstDay->setObjectName(QStringLiteral("comboBox_weekFirstDay"));

        gridLayout_5->addWidget(comboBox_weekFirstDay, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox_0);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_5->addWidget(label_7, 2, 0, 1, 1);

        comboBox_language = new QComboBox(groupBox_0);
        comboBox_language->addItem(QString());
        comboBox_language->addItem(QString());
        comboBox_language->addItem(QString());
        comboBox_language->setObjectName(QStringLiteral("comboBox_language"));

        gridLayout_5->addWidget(comboBox_language, 2, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_5, 0, 2, 3, 1);

        checkBox_showWeek = new QCheckBox(groupBox_0);
        checkBox_showWeek->setObjectName(QStringLiteral("checkBox_showWeek"));

        gridLayout_5->addWidget(checkBox_showWeek, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_0, 0, 0, 1, 1);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        comboBox_cellSpace = new QComboBox(groupBox_3);
        comboBox_cellSpace->addItem(QString());
        comboBox_cellSpace->addItem(QString());
        comboBox_cellSpace->addItem(QString());
        comboBox_cellSpace->addItem(QString());
        comboBox_cellSpace->addItem(QString());
        comboBox_cellSpace->addItem(QString());
        comboBox_cellSpace->addItem(QString());
        comboBox_cellSpace->addItem(QString());
        comboBox_cellSpace->addItem(QString());
        comboBox_cellSpace->addItem(QString());
        comboBox_cellSpace->setObjectName(QStringLiteral("comboBox_cellSpace"));
        sizePolicy.setHeightForWidth(comboBox_cellSpace->sizePolicy().hasHeightForWidth());
        comboBox_cellSpace->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(comboBox_cellSpace, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 2, 1);

        pushButton_cellColor = new QPushButton(groupBox_3);
        pushButton_cellColor->setObjectName(QStringLiteral("pushButton_cellColor"));
        sizePolicy.setHeightForWidth(pushButton_cellColor->sizePolicy().hasHeightForWidth());
        pushButton_cellColor->setSizePolicy(sizePolicy);
        pushButton_cellColor->setIconSize(QSize(56, 16));

        gridLayout_3->addWidget(pushButton_cellColor, 1, 1, 1, 1);


        gridLayout->addWidget(groupBox_3, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalSpacer_2 = new QSpacerItem(20, 143, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 3, 3, 1);

        pushButton_eventColor_2 = new QPushButton(groupBox_4);
        pushButton_eventColor_2->setObjectName(QStringLiteral("pushButton_eventColor_2"));
        sizePolicy.setHeightForWidth(pushButton_eventColor_2->sizePolicy().hasHeightForWidth());
        pushButton_eventColor_2->setSizePolicy(sizePolicy);
        pushButton_eventColor_2->setIconSize(QSize(56, 16));

        gridLayout_2->addWidget(pushButton_eventColor_2, 2, 1, 1, 1);

        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 0, 0, 1, 1);

        pushButton_eventColor_1 = new QPushButton(groupBox_4);
        pushButton_eventColor_1->setObjectName(QStringLiteral("pushButton_eventColor_1"));
        sizePolicy.setHeightForWidth(pushButton_eventColor_1->sizePolicy().hasHeightForWidth());
        pushButton_eventColor_1->setSizePolicy(sizePolicy);
        pushButton_eventColor_1->setIconSize(QSize(56, 16));

        gridLayout_2->addWidget(pushButton_eventColor_1, 1, 1, 1, 1);

        pushButton_eventFont = new QPushButton(groupBox_4);
        pushButton_eventFont->setObjectName(QStringLiteral("pushButton_eventFont"));
        sizePolicy.setHeightForWidth(pushButton_eventFont->sizePolicy().hasHeightForWidth());
        pushButton_eventFont->setSizePolicy(sizePolicy);
        pushButton_eventFont->setIconSize(QSize(56, 16));

        gridLayout_2->addWidget(pushButton_eventFont, 0, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_4, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());

        gridLayout_9->addWidget(tabWidget, 0, 0, 1, 3);

        buttonBox = new QDialogButtonBox(PreferenceDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::Reset);

        gridLayout_9->addWidget(buttonBox, 2, 2, 1, 1);

        pushButton_import = new QPushButton(PreferenceDialog);
        pushButton_import->setObjectName(QStringLiteral("pushButton_import"));

        gridLayout_9->addWidget(pushButton_import, 2, 0, 1, 1);

        pushButton_export = new QPushButton(PreferenceDialog);
        pushButton_export->setObjectName(QStringLiteral("pushButton_export"));

        gridLayout_9->addWidget(pushButton_export, 2, 1, 1, 1);


        retranslateUi(PreferenceDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PreferenceDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PreferenceDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PreferenceDialog);
    } // setupUi

    void retranslateUi(QDialog *PreferenceDialog)
    {
        PreferenceDialog->setWindowTitle(QApplication::translate("PreferenceDialog", "Preference", nullptr));
        groupBox_2->setTitle(QApplication::translate("PreferenceDialog", "&Behavior", nullptr));
        checkBox_dragDrop->setText(QApplication::translate("PreferenceDialog", "Enable &drag and drop files", nullptr));
        groupBox_1->setTitle(QApplication::translate("PreferenceDialog", "&Appearance", nullptr));
        label_5->setText(QApplication::translate("PreferenceDialog", "Opacity:", nullptr));
        label_8->setText(QApplication::translate("PreferenceDialog", "Font:", nullptr));
        comboBox_opacity->setItemText(0, QApplication::translate("PreferenceDialog", "100% (Opaque)", nullptr));
        comboBox_opacity->setItemText(1, QApplication::translate("PreferenceDialog", "90%", nullptr));
        comboBox_opacity->setItemText(2, QApplication::translate("PreferenceDialog", "80%", nullptr));
        comboBox_opacity->setItemText(3, QApplication::translate("PreferenceDialog", "70%", nullptr));
        comboBox_opacity->setItemText(4, QApplication::translate("PreferenceDialog", "60%", nullptr));
        comboBox_opacity->setItemText(5, QApplication::translate("PreferenceDialog", "50%", nullptr));
        comboBox_opacity->setItemText(6, QApplication::translate("PreferenceDialog", "40%", nullptr));
        comboBox_opacity->setItemText(7, QApplication::translate("PreferenceDialog", "30%", nullptr));
        comboBox_opacity->setItemText(8, QApplication::translate("PreferenceDialog", "20%", nullptr));
        comboBox_opacity->setItemText(9, QApplication::translate("PreferenceDialog", "10%", nullptr));
        comboBox_opacity->setItemText(10, QApplication::translate("PreferenceDialog", "0% (Transparent)", nullptr));

        groupBox_0->setTitle(QApplication::translate("PreferenceDialog", "&Display", nullptr));
        label->setText(QApplication::translate("PreferenceDialog", "The first day of a week:", nullptr));
        label_7->setText(QApplication::translate("PreferenceDialog", "Language:", nullptr));
        comboBox_language->setItemText(0, QApplication::translate("PreferenceDialog", "\347\256\200\344\275\223\344\270\255\346\226\207", nullptr));
        comboBox_language->setItemText(1, QApplication::translate("PreferenceDialog", "\347\271\201\351\253\224\344\270\255\346\226\207", nullptr));
        comboBox_language->setItemText(2, QApplication::translate("PreferenceDialog", "English", nullptr));

        checkBox_showWeek->setText(QApplication::translate("PreferenceDialog", "Display the &week number", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("PreferenceDialog", "&Interface", nullptr));
        groupBox_3->setTitle(QApplication::translate("PreferenceDialog", "&Cell", nullptr));
        comboBox_cellSpace->setItemText(0, QApplication::translate("PreferenceDialog", "0", nullptr));
        comboBox_cellSpace->setItemText(1, QApplication::translate("PreferenceDialog", "1", nullptr));
        comboBox_cellSpace->setItemText(2, QApplication::translate("PreferenceDialog", "2", nullptr));
        comboBox_cellSpace->setItemText(3, QApplication::translate("PreferenceDialog", "3", nullptr));
        comboBox_cellSpace->setItemText(4, QApplication::translate("PreferenceDialog", "4", nullptr));
        comboBox_cellSpace->setItemText(5, QApplication::translate("PreferenceDialog", "5", nullptr));
        comboBox_cellSpace->setItemText(6, QApplication::translate("PreferenceDialog", "6", nullptr));
        comboBox_cellSpace->setItemText(7, QApplication::translate("PreferenceDialog", "7", nullptr));
        comboBox_cellSpace->setItemText(8, QApplication::translate("PreferenceDialog", "8", nullptr));
        comboBox_cellSpace->setItemText(9, QApplication::translate("PreferenceDialog", "9", nullptr));

        label_6->setText(QApplication::translate("PreferenceDialog", "Space:", nullptr));
        label_2->setText(QApplication::translate("PreferenceDialog", "Color:", nullptr));
        pushButton_cellColor->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("PreferenceDialog", "&Cell", nullptr));
        groupBox_4->setTitle(QApplication::translate("PreferenceDialog", "&Events", nullptr));
        pushButton_eventColor_2->setText(QString());
        label_3->setText(QApplication::translate("PreferenceDialog", "Normal events color:", nullptr));
        label_4->setText(QApplication::translate("PreferenceDialog", "Recurrent events color:", nullptr));
        label_9->setText(QApplication::translate("PreferenceDialog", "Font:", nullptr));
        pushButton_eventColor_1->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("PreferenceDialog", "&Events", nullptr));
        pushButton_import->setText(QApplication::translate("PreferenceDialog", "&Import...", nullptr));
        pushButton_export->setText(QApplication::translate("PreferenceDialog", "&Export...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PreferenceDialog: public Ui_PreferenceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCEDIALOG_H
