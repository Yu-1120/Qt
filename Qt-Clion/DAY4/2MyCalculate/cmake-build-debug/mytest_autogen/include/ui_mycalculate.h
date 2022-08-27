/********************************************************************************
** Form generated from reading UI file 'mycalculate.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCALCULATE_H
#define UI_MYCALCULATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyCalculate
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_username;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QLabel *label_username;
    QPushButton *pushButton_login;
    QPushButton *pushButton_exit;

    void setupUi(QDialog *MyCalculate)
    {
        if (MyCalculate->objectName().isEmpty())
            MyCalculate->setObjectName(QString::fromUtf8("MyCalculate"));
        MyCalculate->resize(356, 196);
        gridLayoutWidget = new QWidget(MyCalculate);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 10, 351, 181));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_username = new QLineEdit(gridLayoutWidget);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(lineEdit_username, 0, 1, 1, 1);

        label_password = new QLabel(gridLayoutWidget);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(14);
        label_password->setFont(font);

        gridLayout->addWidget(label_password, 1, 0, 1, 1);

        lineEdit_password = new QLineEdit(gridLayoutWidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setMinimumSize(QSize(0, 40));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_password, 1, 1, 1, 1);

        label_username = new QLabel(gridLayoutWidget);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        label_username->setFont(font);

        gridLayout->addWidget(label_username, 0, 0, 1, 1);

        pushButton_login = new QPushButton(gridLayoutWidget);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pushButton_login, 2, 0, 1, 1);

        pushButton_exit = new QPushButton(gridLayoutWidget);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setMinimumSize(QSize(0, 40));
        pushButton_exit->setMaximumSize(QSize(89, 16777215));

        gridLayout->addWidget(pushButton_exit, 2, 1, 1, 1);


        retranslateUi(MyCalculate);

        QMetaObject::connectSlotsByName(MyCalculate);
    } // setupUi

    void retranslateUi(QDialog *MyCalculate)
    {
        MyCalculate->setWindowTitle(QCoreApplication::translate("MyCalculate", "\350\256\241\347\256\227\345\231\250\347\231\273\345\275\225", nullptr));
        label_password->setText(QCoreApplication::translate("MyCalculate", "password:", nullptr));
        label_username->setText(QCoreApplication::translate("MyCalculate", "username:", nullptr));
        pushButton_login->setText(QCoreApplication::translate("MyCalculate", "\347\231\273\345\275\225", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("MyCalculate", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyCalculate: public Ui_MyCalculate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCALCULATE_H
