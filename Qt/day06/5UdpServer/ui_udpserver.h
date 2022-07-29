/********************************************************************************
** Form generated from reading UI file 'udpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDPSERVER_H
#define UI_UDPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UdpServer
{
public:
    QPushButton *pushButton_send;
    QTextBrowser *textBrowser;
    QSpinBox *spinBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton_start;

    void setupUi(QWidget *UdpServer)
    {
        if (UdpServer->objectName().isEmpty())
            UdpServer->setObjectName(QStringLiteral("UdpServer"));
        UdpServer->resize(800, 480);
        pushButton_send = new QPushButton(UdpServer);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setEnabled(false);
        pushButton_send->setGeometry(QRect(700, 435, 75, 31));
        textBrowser = new QTextBrowser(UdpServer);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 55, 781, 361));
        spinBox = new QSpinBox(UdpServer);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(600, 10, 71, 31));
        spinBox->setMaximum(65535);
        spinBox->setValue(9999);
        lineEdit = new QLineEdit(UdpServer);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(10, 435, 661, 31));
        label = new QLabel(UdpServer);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(530, 10, 51, 31));
        pushButton_start = new QPushButton(UdpServer);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setGeometry(QRect(700, 10, 75, 31));

        retranslateUi(UdpServer);

        QMetaObject::connectSlotsByName(UdpServer);
    } // setupUi

    void retranslateUi(QWidget *UdpServer)
    {
        UdpServer->setWindowTitle(QApplication::translate("UdpServer", "UdpServer", 0));
        pushButton_send->setText(QApplication::translate("UdpServer", "\345\217\221\351\200\201", 0));
        label->setText(QApplication::translate("UdpServer", "\347\253\257\345\217\243\345\217\267\357\274\232", 0));
        pushButton_start->setText(QApplication::translate("UdpServer", "\345\220\257\345\212\250", 0));
    } // retranslateUi

};

namespace Ui {
    class UdpServer: public Ui_UdpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPSERVER_H
