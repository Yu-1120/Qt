/********************************************************************************
** Form generated from reading UI file 'calculate.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATE_H
#define UI_CALCULATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculate
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLCDNumber *lcdNumber;
    QGridLayout *gridLayout;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_add;
    QPushButton *pushButton_equ;
    QPushButton *pushButton_6;
    QPushButton *pushButton_mul;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_1;
    QPushButton *pushButton_0;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_sub;
    QPushButton *pushButton_4;
    QPushButton *pushButton_div;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;

    void setupUi(QWidget *Calculate)
    {
        if (Calculate->objectName().isEmpty())
            Calculate->setObjectName(QString::fromUtf8("Calculate"));
        Calculate->resize(526, 319);
        verticalLayoutWidget = new QWidget(Calculate);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 521, 311));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lcdNumber = new QLCDNumber(verticalLayoutWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setMaximumSize(QSize(16777215, 50));
        lcdNumber->setDigitCount(9);

        verticalLayout->addWidget(lcdNumber);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_clear = new QPushButton(verticalLayoutWidget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setMinimumSize(QSize(0, 50));
        pushButton_clear->setMaximumSize(QSize(110, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        pushButton_clear->setFont(font);

        gridLayout->addWidget(pushButton_clear, 3, 1, 1, 1);

        pushButton_add = new QPushButton(verticalLayoutWidget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setMinimumSize(QSize(0, 50));
        pushButton_add->setMaximumSize(QSize(110, 16777215));
        pushButton_add->setFont(font);

        gridLayout->addWidget(pushButton_add, 0, 3, 1, 1);

        pushButton_equ = new QPushButton(verticalLayoutWidget);
        pushButton_equ->setObjectName(QString::fromUtf8("pushButton_equ"));
        pushButton_equ->setMinimumSize(QSize(0, 50));
        pushButton_equ->setMaximumSize(QSize(110, 16777215));
        pushButton_equ->setFont(font);

        gridLayout->addWidget(pushButton_equ, 3, 2, 1, 1);

        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(0, 50));
        pushButton_6->setMaximumSize(QSize(110, 16777215));
        pushButton_6->setFont(font);

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_mul = new QPushButton(verticalLayoutWidget);
        pushButton_mul->setObjectName(QString::fromUtf8("pushButton_mul"));
        pushButton_mul->setMinimumSize(QSize(0, 50));
        pushButton_mul->setMaximumSize(QSize(110, 16777215));
        pushButton_mul->setFont(font);

        gridLayout->addWidget(pushButton_mul, 2, 3, 1, 1);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 50));
        pushButton_3->setMaximumSize(QSize(110, 16777215));
        pushButton_3->setFont(font);

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_8 = new QPushButton(verticalLayoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(0, 50));
        pushButton_8->setMaximumSize(QSize(110, 16777215));
        pushButton_8->setFont(font);

        gridLayout->addWidget(pushButton_8, 2, 1, 1, 1);

        pushButton_1 = new QPushButton(verticalLayoutWidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setMinimumSize(QSize(0, 50));
        pushButton_1->setMaximumSize(QSize(110, 16777215));
        pushButton_1->setFont(font);

        gridLayout->addWidget(pushButton_1, 0, 0, 1, 1);

        pushButton_0 = new QPushButton(verticalLayoutWidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setMinimumSize(QSize(0, 50));
        pushButton_0->setMaximumSize(QSize(110, 16777215));
        pushButton_0->setFont(font);

        gridLayout->addWidget(pushButton_0, 3, 0, 1, 1);

        pushButton_7 = new QPushButton(verticalLayoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(0, 50));
        pushButton_7->setMaximumSize(QSize(110, 16777215));
        pushButton_7->setFont(font);

        gridLayout->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_9 = new QPushButton(verticalLayoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(0, 50));
        pushButton_9->setMaximumSize(QSize(110, 16777215));
        pushButton_9->setFont(font);

        gridLayout->addWidget(pushButton_9, 2, 2, 1, 1);

        pushButton_sub = new QPushButton(verticalLayoutWidget);
        pushButton_sub->setObjectName(QString::fromUtf8("pushButton_sub"));
        pushButton_sub->setMinimumSize(QSize(0, 50));
        pushButton_sub->setMaximumSize(QSize(110, 16777215));
        pushButton_sub->setFont(font);

        gridLayout->addWidget(pushButton_sub, 1, 3, 1, 1);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 50));
        pushButton_4->setMaximumSize(QSize(110, 16777215));
        pushButton_4->setFont(font);

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_div = new QPushButton(verticalLayoutWidget);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setMinimumSize(QSize(0, 50));
        pushButton_div->setMaximumSize(QSize(110, 16777215));
        pushButton_div->setFont(font);

        gridLayout->addWidget(pushButton_div, 3, 3, 1, 1);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 50));
        pushButton_2->setMaximumSize(QSize(110, 16777215));
        pushButton_2->setFont(font);

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 50));
        pushButton_5->setMaximumSize(QSize(110, 16777215));
        pushButton_5->setFont(font);

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(Calculate);

        QMetaObject::connectSlotsByName(Calculate);
    } // setupUi

    void retranslateUi(QWidget *Calculate)
    {
        Calculate->setWindowTitle(QCoreApplication::translate("Calculate", "Form", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("Calculate", "C", nullptr));
        pushButton_add->setText(QCoreApplication::translate("Calculate", "+", nullptr));
        pushButton_equ->setText(QCoreApplication::translate("Calculate", "=", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Calculate", "6", nullptr));
        pushButton_mul->setText(QCoreApplication::translate("Calculate", "X", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Calculate", "3", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Calculate", "8", nullptr));
        pushButton_1->setText(QCoreApplication::translate("Calculate", "1", nullptr));
        pushButton_0->setText(QCoreApplication::translate("Calculate", "0", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Calculate", "7", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Calculate", "9", nullptr));
        pushButton_sub->setText(QCoreApplication::translate("Calculate", "-", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Calculate", "4", nullptr));
        pushButton_div->setText(QCoreApplication::translate("Calculate", "\303\267", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Calculate", "2", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Calculate", "5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculate: public Ui_Calculate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATE_H
