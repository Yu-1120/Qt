/********************************************************************************
** Form generated from reading UI file 'sqllogin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQLLOGIN_H
#define UI_SQLLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SQLLogin
{
public:
    QLabel *label_username;
    QLabel *label_password;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_reg;
    QPushButton *pushButton_login;
    QPushButton *pushButton_exit;

    void setupUi(QWidget *SQLLogin)
    {
        if (SQLLogin->objectName().isEmpty())
            SQLLogin->setObjectName(QString::fromUtf8("SQLLogin"));
        SQLLogin->resize(374, 170);
        label_username = new QLabel(SQLLogin);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        label_username->setGeometry(QRect(30, 20, 61, 31));
        label_password = new QLabel(SQLLogin);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(40, 70, 41, 31));
        lineEdit_username = new QLineEdit(SQLLogin);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(100, 20, 261, 31));
        lineEdit_password = new QLineEdit(SQLLogin);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(100, 70, 261, 31));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        pushButton_reg = new QPushButton(SQLLogin);
        pushButton_reg->setObjectName(QString::fromUtf8("pushButton_reg"));
        pushButton_reg->setGeometry(QRect(20, 120, 75, 31));
        pushButton_login = new QPushButton(SQLLogin);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(150, 120, 75, 31));
        pushButton_exit = new QPushButton(SQLLogin);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(280, 120, 75, 31));

        retranslateUi(SQLLogin);

        QMetaObject::connectSlotsByName(SQLLogin);
    } // setupUi

    void retranslateUi(QWidget *SQLLogin)
    {
        SQLLogin->setWindowTitle(QCoreApplication::translate("SQLLogin", "SQLLogin", nullptr));
        label_username->setText(QCoreApplication::translate("SQLLogin", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_password->setText(QCoreApplication::translate("SQLLogin", "\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton_reg->setText(QCoreApplication::translate("SQLLogin", "\346\263\250\345\206\214", nullptr));
        pushButton_login->setText(QCoreApplication::translate("SQLLogin", "\347\231\273\345\275\225", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("SQLLogin", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SQLLogin: public Ui_SQLLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQLLOGIN_H
