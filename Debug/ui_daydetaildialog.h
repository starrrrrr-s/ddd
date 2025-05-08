/********************************************************************************
** Form generated from reading UI file 'daydetaildialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAYDETAILDIALOG_H
#define UI_DAYDETAILDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DayDetailDialog
{
public:
    QVBoxLayout *verticalLayout_0;
    QLabel *label_day;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DayDetailDialog)
    {
        if (DayDetailDialog->objectName().isEmpty())
            DayDetailDialog->setObjectName(QStringLiteral("DayDetailDialog"));
        verticalLayout_0 = new QVBoxLayout(DayDetailDialog);
        verticalLayout_0->setObjectName(QStringLiteral("verticalLayout_0"));
        label_day = new QLabel(DayDetailDialog);
        label_day->setObjectName(QStringLiteral("label_day"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        label_day->setFont(font);
        label_day->setAlignment(Qt::AlignCenter);

        verticalLayout_0->addWidget(label_day);

        scrollArea = new QScrollArea(DayDetailDialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 73, 69));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_0->addWidget(scrollArea);

        buttonBox = new QDialogButtonBox(DayDetailDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout_0->addWidget(buttonBox);


        retranslateUi(DayDetailDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DayDetailDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DayDetailDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DayDetailDialog);
    } // setupUi

    void retranslateUi(QDialog *DayDetailDialog)
    {
        DayDetailDialog->setWindowTitle(QApplication::translate("DayDetailDialog", "Events View", nullptr));
        label_day->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DayDetailDialog: public Ui_DayDetailDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAYDETAILDIALOG_H
