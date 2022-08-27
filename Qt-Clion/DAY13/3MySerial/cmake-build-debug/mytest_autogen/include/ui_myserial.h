/********************************************************************************
** Form generated from reading UI file 'myserial.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSERIAL_H
#define UI_MYSERIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MySerial
{
public:
    QLabel *label_port;
    QComboBox *comboBox_port;
    QLabel *label_baudrate;
    QComboBox *comboBox_baudrate;
    QLabel *label_databits;
    QComboBox *comboBox_databits;
    QLabel *label_parity;
    QComboBox *comboBox_parity;
    QLabel *label_stopbits;
    QComboBox *comboBox_stopbits;
    QPushButton *pushButton_open;
    QPushButton *pushButton_send;
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;

    void setupUi(QWidget *MySerial)
    {
        if (MySerial->objectName().isEmpty())
            MySerial->setObjectName(QString::fromUtf8("MySerial"));
        MySerial->resize(800, 480);
        label_port = new QLabel(MySerial);
        label_port->setObjectName(QString::fromUtf8("label_port"));
        label_port->setGeometry(QRect(610, 20, 61, 31));
        comboBox_port = new QComboBox(MySerial);
        comboBox_port->setObjectName(QString::fromUtf8("comboBox_port"));
        comboBox_port->setGeometry(QRect(690, 20, 101, 31));
        label_baudrate = new QLabel(MySerial);
        label_baudrate->setObjectName(QString::fromUtf8("label_baudrate"));
        label_baudrate->setGeometry(QRect(610, 90, 61, 31));
        comboBox_baudrate = new QComboBox(MySerial);
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->setObjectName(QString::fromUtf8("comboBox_baudrate"));
        comboBox_baudrate->setGeometry(QRect(690, 90, 101, 31));
        label_databits = new QLabel(MySerial);
        label_databits->setObjectName(QString::fromUtf8("label_databits"));
        label_databits->setGeometry(QRect(610, 160, 61, 31));
        comboBox_databits = new QComboBox(MySerial);
        comboBox_databits->addItem(QString());
        comboBox_databits->addItem(QString());
        comboBox_databits->addItem(QString());
        comboBox_databits->addItem(QString());
        comboBox_databits->setObjectName(QString::fromUtf8("comboBox_databits"));
        comboBox_databits->setGeometry(QRect(690, 160, 101, 31));
        label_parity = new QLabel(MySerial);
        label_parity->setObjectName(QString::fromUtf8("label_parity"));
        label_parity->setGeometry(QRect(610, 230, 61, 31));
        comboBox_parity = new QComboBox(MySerial);
        comboBox_parity->addItem(QString());
        comboBox_parity->addItem(QString());
        comboBox_parity->addItem(QString());
        comboBox_parity->setObjectName(QString::fromUtf8("comboBox_parity"));
        comboBox_parity->setGeometry(QRect(690, 230, 101, 31));
        label_stopbits = new QLabel(MySerial);
        label_stopbits->setObjectName(QString::fromUtf8("label_stopbits"));
        label_stopbits->setGeometry(QRect(610, 300, 61, 31));
        comboBox_stopbits = new QComboBox(MySerial);
        comboBox_stopbits->addItem(QString());
        comboBox_stopbits->addItem(QString());
        comboBox_stopbits->addItem(QString());
        comboBox_stopbits->setObjectName(QString::fromUtf8("comboBox_stopbits"));
        comboBox_stopbits->setGeometry(QRect(690, 300, 101, 31));
        pushButton_open = new QPushButton(MySerial);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));
        pushButton_open->setGeometry(QRect(650, 360, 111, 41));
        pushButton_send = new QPushButton(MySerial);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        pushButton_send->setEnabled(false);
        pushButton_send->setGeometry(QRect(650, 420, 111, 41));
        textBrowser = new QTextBrowser(MySerial);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 20, 571, 311));
        textEdit = new QTextEdit(MySerial);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 360, 571, 101));

        retranslateUi(MySerial);

        QMetaObject::connectSlotsByName(MySerial);
    } // setupUi

    void retranslateUi(QWidget *MySerial)
    {
        MySerial->setWindowTitle(QCoreApplication::translate("MySerial", "MySerial", nullptr));
        label_port->setText(QCoreApplication::translate("MySerial", "\344\270\262\345\217\243\357\274\232", nullptr));
        label_baudrate->setText(QCoreApplication::translate("MySerial", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        comboBox_baudrate->setItemText(0, QCoreApplication::translate("MySerial", "115200", nullptr));
        comboBox_baudrate->setItemText(1, QCoreApplication::translate("MySerial", "2400", nullptr));
        comboBox_baudrate->setItemText(2, QCoreApplication::translate("MySerial", "4800", nullptr));
        comboBox_baudrate->setItemText(3, QCoreApplication::translate("MySerial", "9600", nullptr));
        comboBox_baudrate->setItemText(4, QCoreApplication::translate("MySerial", "38400", nullptr));

        label_databits->setText(QCoreApplication::translate("MySerial", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        comboBox_databits->setItemText(0, QCoreApplication::translate("MySerial", "8", nullptr));
        comboBox_databits->setItemText(1, QCoreApplication::translate("MySerial", "5", nullptr));
        comboBox_databits->setItemText(2, QCoreApplication::translate("MySerial", "6", nullptr));
        comboBox_databits->setItemText(3, QCoreApplication::translate("MySerial", "7", nullptr));

        label_parity->setText(QCoreApplication::translate("MySerial", "\346\240\241\351\252\214\346\226\271\345\274\217\357\274\232", nullptr));
        comboBox_parity->setItemText(0, QCoreApplication::translate("MySerial", "None", nullptr));
        comboBox_parity->setItemText(1, QCoreApplication::translate("MySerial", "Odd", nullptr));
        comboBox_parity->setItemText(2, QCoreApplication::translate("MySerial", "Even", nullptr));

        label_stopbits->setText(QCoreApplication::translate("MySerial", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        comboBox_stopbits->setItemText(0, QCoreApplication::translate("MySerial", "1", nullptr));
        comboBox_stopbits->setItemText(1, QCoreApplication::translate("MySerial", "1.5", nullptr));
        comboBox_stopbits->setItemText(2, QCoreApplication::translate("MySerial", "2", nullptr));

        pushButton_open->setText(QCoreApplication::translate("MySerial", "\346\211\223 \345\274\200 \344\270\262 \345\217\243", nullptr));
        pushButton_send->setText(QCoreApplication::translate("MySerial", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MySerial: public Ui_MySerial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSERIAL_H
