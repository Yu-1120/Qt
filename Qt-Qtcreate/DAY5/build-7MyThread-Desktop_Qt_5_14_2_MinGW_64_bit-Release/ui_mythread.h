/********************************************************************************
** Form generated from reading UI file 'mythread.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTHREAD_H
#define UI_MYTHREAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyThread
{
public:
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;

    void setupUi(QWidget *MyThread)
    {
        if (MyThread->objectName().isEmpty())
            MyThread->setObjectName(QString::fromUtf8("MyThread"));
        MyThread->resize(800, 600);
        pushButton_start = new QPushButton(MyThread);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(130, 260, 181, 71));
        pushButton_stop = new QPushButton(MyThread);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(460, 260, 181, 71));

        retranslateUi(MyThread);

        QMetaObject::connectSlotsByName(MyThread);
    } // setupUi

    void retranslateUi(QWidget *MyThread)
    {
        MyThread->setWindowTitle(QCoreApplication::translate("MyThread", "MyThread", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MyThread", "\345\220\257\345\212\250", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MyThread", "\347\273\223\346\235\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyThread: public Ui_MyThread {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTHREAD_H
