/********************************************************************************
** Form generated from reading UI file 'myevent.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYEVENT_H
#define UI_MYEVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyEvent
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *MyEvent)
    {
        if (MyEvent->objectName().isEmpty())
            MyEvent->setObjectName(QString::fromUtf8("MyEvent"));
        MyEvent->resize(800, 600);
        pushButton = new QPushButton(MyEvent);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 250, 121, 51));

        retranslateUi(MyEvent);

        QMetaObject::connectSlotsByName(MyEvent);
    } // setupUi

    void retranslateUi(QWidget *MyEvent)
    {
        MyEvent->setWindowTitle(QCoreApplication::translate("MyEvent", "MyEvent", nullptr));
        pushButton->setText(QCoreApplication::translate("MyEvent", "\346\214\211\351\222\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyEvent: public Ui_MyEvent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYEVENT_H
