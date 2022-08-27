/********************************************************************************
** Form generated from reading UI file 'find.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIND_H
#define UI_FIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Find
{
public:
    QPushButton *pushButton_find;
    QPushButton *pushButton_cancel;
    QLineEdit *lineEdit;
    QLabel *label;
    QRadioButton *radioButton_up;
    QCheckBox *checkBox;
    QRadioButton *radioButton_down;

    void setupUi(QDialog *Find)
    {
        if (Find->objectName().isEmpty())
            Find->setObjectName(QString::fromUtf8("Find"));
        Find->resize(453, 206);
        pushButton_find = new QPushButton(Find);
        pushButton_find->setObjectName(QString::fromUtf8("pushButton_find"));
        pushButton_find->setGeometry(QRect(50, 140, 81, 31));
        pushButton_cancel = new QPushButton(Find);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(230, 140, 81, 31));
        lineEdit = new QLineEdit(Find);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 20, 271, 31));
        label = new QLabel(Find);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 61, 31));
        radioButton_up = new QRadioButton(Find);
        radioButton_up->setObjectName(QString::fromUtf8("radioButton_up"));
        radioButton_up->setGeometry(QRect(190, 80, 61, 31));
        checkBox = new QCheckBox(Find);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(40, 80, 91, 31));
        radioButton_down = new QRadioButton(Find);
        radioButton_down->setObjectName(QString::fromUtf8("radioButton_down"));
        radioButton_down->setGeometry(QRect(280, 80, 61, 31));
        radioButton_down->setChecked(true);

        retranslateUi(Find);

        QMetaObject::connectSlotsByName(Find);
    } // setupUi

    void retranslateUi(QDialog *Find)
    {
        Find->setWindowTitle(QCoreApplication::translate("Find", "Dialog", nullptr));
        pushButton_find->setText(QCoreApplication::translate("Find", "\346\237\245\346\211\276", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("Find", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("Find", "\346\237\245\346\211\276\345\206\205\345\256\271\357\274\232", nullptr));
        radioButton_up->setText(QCoreApplication::translate("Find", "\345\220\221\344\270\212", nullptr));
        checkBox->setText(QCoreApplication::translate("Find", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", nullptr));
        radioButton_down->setText(QCoreApplication::translate("Find", "\345\220\221\344\270\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Find: public Ui_Find {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIND_H
