/********************************************************************************
** Form generated from reading UI file 'myprocess.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYPROCESS_H
#define UI_MYPROCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyProcess
{
public:
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;

    void setupUi(QWidget *MyProcess)
    {
        if (MyProcess->objectName().isEmpty())
            MyProcess->setObjectName(QString::fromUtf8("MyProcess"));
        MyProcess->resize(800, 600);
        pushButton_start = new QPushButton(MyProcess);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(100, 240, 181, 71));
        pushButton_stop = new QPushButton(MyProcess);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(430, 240, 181, 71));

        retranslateUi(MyProcess);

        QMetaObject::connectSlotsByName(MyProcess);
    } // setupUi

    void retranslateUi(QWidget *MyProcess)
    {
        MyProcess->setWindowTitle(QCoreApplication::translate("MyProcess", "MyProcess", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MyProcess", "\345\220\257\345\212\250", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MyProcess", "\347\273\223\346\235\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyProcess: public Ui_MyProcess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPROCESS_H
