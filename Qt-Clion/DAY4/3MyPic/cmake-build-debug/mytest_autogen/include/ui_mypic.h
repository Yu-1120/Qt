/********************************************************************************
** Form generated from reading UI file 'mypic.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYPIC_H
#define UI_MYPIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyPic
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *MyPic)
    {
        if (MyPic->objectName().isEmpty())
            MyPic->setObjectName(QString::fromUtf8("MyPic"));
        MyPic->resize(800, 600);
        pushButton = new QPushButton(MyPic);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 460, 121, 51));
        label = new QLabel(MyPic);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 50, 481, 361));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 255);"));

        retranslateUi(MyPic);

        QMetaObject::connectSlotsByName(MyPic);
    } // setupUi

    void retranslateUi(QWidget *MyPic)
    {
        MyPic->setWindowTitle(QCoreApplication::translate("MyPic", "MyPic", nullptr));
        pushButton->setText(QCoreApplication::translate("MyPic", "\346\230\276\347\244\272\345\233\276\347\211\207", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyPic: public Ui_MyPic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPIC_H
