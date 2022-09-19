/********************************************************************************
** Form generated from reading UI file 'replace.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACE_H
#define UI_REPLACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Replace
{
public:
    QPushButton *pushButton_find;
    QLabel *label_find;
    QLineEdit *lineEdit_find;
    QCheckBox *checkBox;
    QRadioButton *radioButton_up;
    QRadioButton *radioButton_down;
    QPushButton *pushButton_cancel;
    QLabel *label_replace;
    QLineEdit *lineEdit_replace;

    void setupUi(QDialog *Replace)
    {
        if (Replace->objectName().isEmpty())
            Replace->setObjectName(QString::fromUtf8("Replace"));
        Replace->resize(400, 220);
        pushButton_find = new QPushButton(Replace);
        pushButton_find->setObjectName(QString::fromUtf8("pushButton_find"));
        pushButton_find->setGeometry(QRect(40, 180, 81, 31));
        label_find = new QLabel(Replace);
        label_find->setObjectName(QString::fromUtf8("label_find"));
        label_find->setGeometry(QRect(20, 10, 61, 31));
        lineEdit_find = new QLineEdit(Replace);
        lineEdit_find->setObjectName(QString::fromUtf8("lineEdit_find"));
        lineEdit_find->setGeometry(QRect(100, 10, 271, 31));
        checkBox = new QCheckBox(Replace);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 120, 91, 31));
        radioButton_up = new QRadioButton(Replace);
        radioButton_up->setObjectName(QString::fromUtf8("radioButton_up"));
        radioButton_up->setGeometry(QRect(190, 120, 61, 31));
        radioButton_down = new QRadioButton(Replace);
        radioButton_down->setObjectName(QString::fromUtf8("radioButton_down"));
        radioButton_down->setGeometry(QRect(280, 120, 61, 31));
        radioButton_down->setChecked(true);
        pushButton_cancel = new QPushButton(Replace);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(240, 180, 81, 31));
        label_replace = new QLabel(Replace);
        label_replace->setObjectName(QString::fromUtf8("label_replace"));
        label_replace->setGeometry(QRect(20, 60, 61, 31));
        lineEdit_replace = new QLineEdit(Replace);
        lineEdit_replace->setObjectName(QString::fromUtf8("lineEdit_replace"));
        lineEdit_replace->setGeometry(QRect(100, 60, 271, 31));

        retranslateUi(Replace);

        QMetaObject::connectSlotsByName(Replace);
    } // setupUi

    void retranslateUi(QDialog *Replace)
    {
        Replace->setWindowTitle(QCoreApplication::translate("Replace", "Dialog", nullptr));
        pushButton_find->setText(QCoreApplication::translate("Replace", "\346\233\277\346\215\242", nullptr));
        label_find->setText(QCoreApplication::translate("Replace", "\346\237\245\346\211\276\345\206\205\345\256\271\357\274\232", nullptr));
        checkBox->setText(QCoreApplication::translate("Replace", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", nullptr));
        radioButton_up->setText(QCoreApplication::translate("Replace", "\345\220\221\344\270\212", nullptr));
        radioButton_down->setText(QCoreApplication::translate("Replace", "\345\220\221\344\270\213", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("Replace", "\345\217\226\346\266\210", nullptr));
        label_replace->setText(QCoreApplication::translate("Replace", "\346\233\277\346\215\242\344\270\272\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Replace: public Ui_Replace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACE_H
