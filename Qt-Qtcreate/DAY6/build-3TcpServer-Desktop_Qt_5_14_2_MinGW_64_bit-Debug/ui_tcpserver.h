/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpServer
{
public:
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushButton_start;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;
    QPushButton *pushButton_send;

    void setupUi(QWidget *TcpServer)
    {
        if (TcpServer->objectName().isEmpty())
            TcpServer->setObjectName(QString::fromUtf8("TcpServer"));
        TcpServer->resize(800, 480);
        label = new QLabel(TcpServer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(530, 15, 51, 31));
        spinBox = new QSpinBox(TcpServer);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(600, 15, 71, 31));
        spinBox->setMaximum(65535);
        spinBox->setValue(9999);
        pushButton_start = new QPushButton(TcpServer);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(700, 15, 75, 31));
        textBrowser = new QTextBrowser(TcpServer);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 60, 781, 361));
        lineEdit = new QLineEdit(TcpServer);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(10, 440, 661, 31));
        pushButton_send = new QPushButton(TcpServer);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        pushButton_send->setEnabled(false);
        pushButton_send->setGeometry(QRect(700, 440, 75, 31));

        retranslateUi(TcpServer);

        QMetaObject::connectSlotsByName(TcpServer);
    } // setupUi

    void retranslateUi(QWidget *TcpServer)
    {
        TcpServer->setWindowTitle(QCoreApplication::translate("TcpServer", "TcpServer", nullptr));
        label->setText(QCoreApplication::translate("TcpServer", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        pushButton_start->setText(QCoreApplication::translate("TcpServer", "\345\220\257\345\212\250", nullptr));
        pushButton_send->setText(QCoreApplication::translate("TcpServer", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpServer: public Ui_TcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
