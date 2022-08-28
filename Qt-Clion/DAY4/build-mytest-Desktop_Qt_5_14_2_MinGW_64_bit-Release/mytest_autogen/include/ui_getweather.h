/********************************************************************************
** Form generated from reading UI file 'getweather.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETWEATHER_H
#define UI_GETWEATHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GetWeather
{
public:
    QLineEdit *lineEdit;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *GetWeather)
    {
        if (GetWeather->objectName().isEmpty())
            GetWeather->setObjectName(QString::fromUtf8("GetWeather"));
        GetWeather->resize(800, 480);
        lineEdit = new QLineEdit(GetWeather);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 420, 641, 41));
        textBrowser = new QTextBrowser(GetWeather);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 781, 321));
        pushButton = new QPushButton(GetWeather);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(680, 420, 101, 41));
        label = new QLabel(GetWeather);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 360, 371, 41));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 255);"));

        retranslateUi(GetWeather);

        QMetaObject::connectSlotsByName(GetWeather);
    } // setupUi

    void retranslateUi(QWidget *GetWeather)
    {
        GetWeather->setWindowTitle(QCoreApplication::translate("GetWeather", "GetWeather", nullptr));
        pushButton->setText(QCoreApplication::translate("GetWeather", "\350\216\267\345\217\226", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GetWeather: public Ui_GetWeather {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETWEATHER_H
