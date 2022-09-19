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
    QPushButton *proessesstart;
    QPushButton *proessstop;

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
        proessesstart = new QPushButton(MyProcess);
        proessesstart->setObjectName(QString::fromUtf8("proessesstart"));
        proessesstart->setGeometry(QRect(100, 350, 171, 81));
        proessstop = new QPushButton(MyProcess);
        proessstop->setObjectName(QString::fromUtf8("proessstop"));
        proessstop->setGeometry(QRect(430, 350, 181, 81));

        retranslateUi(MyProcess);

        QMetaObject::connectSlotsByName(MyProcess);
    } // setupUi

    void retranslateUi(QWidget *MyProcess)
    {
        MyProcess->setWindowTitle(QCoreApplication::translate("MyProcess", "MyProcess", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MyProcess", "\345\220\257\345\212\250", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MyProcess", "\347\273\223\346\235\237", nullptr));
        proessesstart->setText(QCoreApplication::translate("MyProcess", "\350\277\233\347\250\213\345\220\257\345\212\250", nullptr));
        proessstop->setText(QCoreApplication::translate("MyProcess", "\350\277\233\347\250\213stopp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyProcess: public Ui_MyProcess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPROCESS_H
