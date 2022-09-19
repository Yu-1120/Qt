/********************************************************************************
** Form generated from reading UI file 'relay.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RELAY_H
#define UI_RELAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Relay
{
public:
    QLabel *realay_before;
    QLabel *relay_later;
    QPushButton *ensure;
    QPushButton *canel;
    QTextEdit *realay_before_edit;
    QTextEdit *relay_later_edit;

    void setupUi(QDialog *Relay)
    {
        if (Relay->objectName().isEmpty())
            Relay->setObjectName(QString::fromUtf8("Relay"));
        Relay->resize(400, 300);
        realay_before = new QLabel(Relay);
        realay_before->setObjectName(QString::fromUtf8("realay_before"));
        realay_before->setGeometry(QRect(30, 40, 54, 16));
        relay_later = new QLabel(Relay);
        relay_later->setObjectName(QString::fromUtf8("relay_later"));
        relay_later->setGeometry(QRect(30, 120, 54, 12));
        ensure = new QPushButton(Relay);
        ensure->setObjectName(QString::fromUtf8("ensure"));
        ensure->setGeometry(QRect(50, 200, 81, 31));
        canel = new QPushButton(Relay);
        canel->setObjectName(QString::fromUtf8("canel"));
        canel->setGeometry(QRect(230, 200, 101, 31));
        realay_before_edit = new QTextEdit(Relay);
        realay_before_edit->setObjectName(QString::fromUtf8("realay_before_edit"));
        realay_before_edit->setGeometry(QRect(110, 30, 191, 41));
        relay_later_edit = new QTextEdit(Relay);
        relay_later_edit->setObjectName(QString::fromUtf8("relay_later_edit"));
        relay_later_edit->setGeometry(QRect(110, 110, 191, 41));

        retranslateUi(Relay);

        QMetaObject::connectSlotsByName(Relay);
    } // setupUi

    void retranslateUi(QDialog *Relay)
    {
        Relay->setWindowTitle(QCoreApplication::translate("Relay", "Dialog", nullptr));
        realay_before->setText(QCoreApplication::translate("Relay", "\346\233\277\346\215\242\345\211\215", nullptr));
        relay_later->setText(QCoreApplication::translate("Relay", "\346\233\277\346\215\242\345\220\216", nullptr));
        ensure->setText(QCoreApplication::translate("Relay", "\347\241\256\345\256\232", nullptr));
        canel->setText(QCoreApplication::translate("Relay", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Relay: public Ui_Relay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RELAY_H
