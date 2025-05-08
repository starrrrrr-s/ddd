/********************************************************************************
** Form generated from reading UI file 'addeventdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEVENTDIALOG_H
#define UI_ADDEVENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddEventDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_1;
    QLabel *label_3;
    QSpinBox *spinBox_interval;
    QComboBox *comboBox_repeatType;
    QSpacerItem *horizontalSpacer_1;
    QWidget *widget_empty;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QComboBox *comboBox_endType;
    QSpinBox *spinBox_repeatTimes;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_place;
    QDateEdit *dateEdit_begin;
    QDateEdit *dateEdit_end;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_title;
    QLabel *label_2;
    QLabel *label_1;
    QPlainTextEdit *plainTextEdit_deail;
    QGridLayout *gridLayout_file;
    QPushButton *pushButton_addFile;
    QLabel *label_file;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *AddEventDialog)
    {
        if (AddEventDialog->objectName().isEmpty())
            AddEventDialog->setObjectName(QStringLiteral("AddEventDialog"));
        AddEventDialog->resize(350, 488);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(AddEventDialog->sizePolicy().hasHeightForWidth());
        AddEventDialog->setSizePolicy(sizePolicy);
        AddEventDialog->setMinimumSize(QSize(350, 0));
        gridLayout = new QGridLayout(AddEventDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(15);
        groupBox = new QGroupBox(AddEventDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setCheckable(true);
        groupBox->setChecked(false);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setObjectName(QStringLiteral("horizontalLayout_1"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        horizontalLayout_1->addWidget(label_3);

        spinBox_interval = new QSpinBox(groupBox);
        spinBox_interval->setObjectName(QStringLiteral("spinBox_interval"));
        spinBox_interval->setMinimum(1);
        spinBox_interval->setMaximum(999);

        horizontalLayout_1->addWidget(spinBox_interval);

        comboBox_repeatType = new QComboBox(groupBox);
        comboBox_repeatType->addItem(QString());
        comboBox_repeatType->addItem(QString());
        comboBox_repeatType->addItem(QString());
        comboBox_repeatType->addItem(QString());
        comboBox_repeatType->setObjectName(QStringLiteral("comboBox_repeatType"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox_repeatType->sizePolicy().hasHeightForWidth());
        comboBox_repeatType->setSizePolicy(sizePolicy2);
        comboBox_repeatType->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout_1->addWidget(comboBox_repeatType);

        horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_1->addItem(horizontalSpacer_1);


        verticalLayout->addLayout(horizontalLayout_1);

        widget_empty = new QWidget(groupBox);
        widget_empty->setObjectName(QStringLiteral("widget_empty"));

        verticalLayout->addWidget(widget_empty);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        comboBox_endType = new QComboBox(groupBox);
        comboBox_endType->addItem(QString());
        comboBox_endType->addItem(QString());
        comboBox_endType->setObjectName(QStringLiteral("comboBox_endType"));
        comboBox_endType->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout_2->addWidget(comboBox_endType);

        spinBox_repeatTimes = new QSpinBox(groupBox);
        spinBox_repeatTimes->setObjectName(QStringLiteral("spinBox_repeatTimes"));
        spinBox_repeatTimes->setMinimum(1);
        spinBox_repeatTimes->setMaximum(999);

        horizontalLayout_2->addWidget(spinBox_repeatTimes);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addWidget(groupBox, 6, 0, 1, 2);

        lineEdit_place = new QLineEdit(AddEventDialog);
        lineEdit_place->setObjectName(QStringLiteral("lineEdit_place"));

        gridLayout->addWidget(lineEdit_place, 1, 0, 1, 2);

        dateEdit_begin = new QDateEdit(AddEventDialog);
        dateEdit_begin->setObjectName(QStringLiteral("dateEdit_begin"));
        dateEdit_begin->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit_begin, 2, 1, 1, 1);

        dateEdit_end = new QDateEdit(AddEventDialog);
        dateEdit_end->setObjectName(QStringLiteral("dateEdit_end"));
        dateEdit_end->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit_end, 5, 1, 1, 1);

        buttonBox = new QDialogButtonBox(AddEventDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 14, 0, 1, 2);

        lineEdit_title = new QLineEdit(AddEventDialog);
        lineEdit_title->setObjectName(QStringLiteral("lineEdit_title"));

        gridLayout->addWidget(lineEdit_title, 0, 0, 1, 2);

        label_2 = new QLabel(AddEventDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_2, 5, 0, 1, 1);

        label_1 = new QLabel(AddEventDialog);
        label_1->setObjectName(QStringLiteral("label_1"));
        sizePolicy1.setHeightForWidth(label_1->sizePolicy().hasHeightForWidth());
        label_1->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_1, 2, 0, 1, 1);

        plainTextEdit_deail = new QPlainTextEdit(AddEventDialog);
        plainTextEdit_deail->setObjectName(QStringLiteral("plainTextEdit_deail"));
        plainTextEdit_deail->setAcceptDrops(false);

        gridLayout->addWidget(plainTextEdit_deail, 13, 0, 1, 2);

        gridLayout_file = new QGridLayout();
        gridLayout_file->setSpacing(6);
        gridLayout_file->setObjectName(QStringLiteral("gridLayout_file"));
        pushButton_addFile = new QPushButton(AddEventDialog);
        pushButton_addFile->setObjectName(QStringLiteral("pushButton_addFile"));
        sizePolicy2.setHeightForWidth(pushButton_addFile->sizePolicy().hasHeightForWidth());
        pushButton_addFile->setSizePolicy(sizePolicy2);

        gridLayout_file->addWidget(pushButton_addFile, 0, 1, 1, 1);

        label_file = new QLabel(AddEventDialog);
        label_file->setObjectName(QStringLiteral("label_file"));
        sizePolicy1.setHeightForWidth(label_file->sizePolicy().hasHeightForWidth());
        label_file->setSizePolicy(sizePolicy1);

        gridLayout_file->addWidget(label_file, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_file->addItem(horizontalSpacer, 0, 2, 1, 1);


        gridLayout->addLayout(gridLayout_file, 10, 0, 3, 2);


        retranslateUi(AddEventDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddEventDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddEventDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddEventDialog);
    } // setupUi

    void retranslateUi(QDialog *AddEventDialog)
    {
        groupBox->setTitle(QApplication::translate("AddEventDialog", "&Repeat", nullptr));
        label_3->setText(QApplication::translate("AddEventDialog", "Every", nullptr));
        comboBox_repeatType->setItemText(0, QApplication::translate("AddEventDialog", "day", nullptr));
        comboBox_repeatType->setItemText(1, QApplication::translate("AddEventDialog", "week", nullptr));
        comboBox_repeatType->setItemText(2, QApplication::translate("AddEventDialog", "month", nullptr));
        comboBox_repeatType->setItemText(3, QApplication::translate("AddEventDialog", "year", nullptr));

        label_4->setText(QApplication::translate("AddEventDialog", "End:", nullptr));
        comboBox_endType->setItemText(0, QApplication::translate("AddEventDialog", "Never", nullptr));
        comboBox_endType->setItemText(1, QApplication::translate("AddEventDialog", "After the times", nullptr));

        label_5->setText(QApplication::translate("AddEventDialog", "times", nullptr));
        lineEdit_place->setPlaceholderText(QApplication::translate("AddEventDialog", "Place", nullptr));
        lineEdit_title->setPlaceholderText(QApplication::translate("AddEventDialog", "Title", nullptr));
        label_2->setText(QApplication::translate("AddEventDialog", "To:", nullptr));
        label_1->setText(QApplication::translate("AddEventDialog", "From:", nullptr));
        plainTextEdit_deail->setPlaceholderText(QApplication::translate("AddEventDialog", "Detail", nullptr));
        pushButton_addFile->setText(QApplication::translate("AddEventDialog", "&Add...", nullptr));
        label_file->setText(QApplication::translate("AddEventDialog", "Attachments:", nullptr));
        Q_UNUSED(AddEventDialog);
    } // retranslateUi

};

namespace Ui {
    class AddEventDialog: public Ui_AddEventDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEVENTDIALOG_H
