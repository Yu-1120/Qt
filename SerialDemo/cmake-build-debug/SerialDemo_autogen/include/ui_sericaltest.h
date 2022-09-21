/********************************************************************************
** Form generated from reading UI file 'sericaltest.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERICALTEST_H
#define UI_SERICALTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_SericalTest
{
public:
    QGroupBox *GroupBox_ReadSettings;
    QCheckBox *cb_ReadEnterSuffix;
    QCheckBox *cb_ReadSpaceSuffix;
    QCheckBox *cb_ReadSuffix;
    QLineEdit *le_ReadSuffix;
    QComboBox *cbx_ReadEncoding;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_2;
    QPushButton *btn_OpenSerialPort;
    QTextEdit *te_Send;
    QLabel *label_6;
    QPushButton *btn_Send;
    QComboBox *cbx_Parity;
    QGroupBox *GroupBox_SendSettings;
    QCheckBox *cb_SendSpaceSuffix;
    QCheckBox *cb_SendEnterSuffix;
    QLineEdit *le_SendSuffix;
    QCheckBox *cb_SendSuffix;
    QComboBox *cbx_SendEncoding;
    QLabel *label_8;
    QComboBox *cbx_SerialName;
    QComboBox *cbx_DataBit;
    QLabel *label_3;
    QComboBox *cbx_Baud;
    QTextEdit *te_Read;
    QLabel *label;
    QPushButton *btn_Clear;
    QComboBox *cbx_StopBit;

    void setupUi(QDialog *SericalTest)
    {
        if (SericalTest->objectName().isEmpty())
            SericalTest->setObjectName(QString::fromUtf8("SericalTest"));
        SericalTest->resize(833, 468);
        SericalTest->setAutoFillBackground(false);
        SericalTest->setSizeGripEnabled(false);
        GroupBox_ReadSettings = new QGroupBox(SericalTest);
        GroupBox_ReadSettings->setObjectName(QString::fromUtf8("GroupBox_ReadSettings"));
        GroupBox_ReadSettings->setGeometry(QRect(480, 320, 331, 131));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GroupBox_ReadSettings->sizePolicy().hasHeightForWidth());
        GroupBox_ReadSettings->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        GroupBox_ReadSettings->setFont(font);
        cb_ReadEnterSuffix = new QCheckBox(GroupBox_ReadSettings);
        cb_ReadEnterSuffix->setObjectName(QString::fromUtf8("cb_ReadEnterSuffix"));
        cb_ReadEnterSuffix->setGeometry(QRect(20, 20, 121, 21));
        sizePolicy.setHeightForWidth(cb_ReadEnterSuffix->sizePolicy().hasHeightForWidth());
        cb_ReadEnterSuffix->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Narrow"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        cb_ReadEnterSuffix->setFont(font1);
        cb_ReadSpaceSuffix = new QCheckBox(GroupBox_ReadSettings);
        cb_ReadSpaceSuffix->setObjectName(QString::fromUtf8("cb_ReadSpaceSuffix"));
        cb_ReadSpaceSuffix->setGeometry(QRect(160, 20, 121, 21));
        sizePolicy.setHeightForWidth(cb_ReadSpaceSuffix->sizePolicy().hasHeightForWidth());
        cb_ReadSpaceSuffix->setSizePolicy(sizePolicy);
        cb_ReadSpaceSuffix->setFont(font1);
        cb_ReadSuffix = new QCheckBox(GroupBox_ReadSettings);
        cb_ReadSuffix->setObjectName(QString::fromUtf8("cb_ReadSuffix"));
        cb_ReadSuffix->setGeometry(QRect(20, 60, 111, 21));
        sizePolicy.setHeightForWidth(cb_ReadSuffix->sizePolicy().hasHeightForWidth());
        cb_ReadSuffix->setSizePolicy(sizePolicy);
        cb_ReadSuffix->setFont(font1);
        le_ReadSuffix = new QLineEdit(GroupBox_ReadSettings);
        le_ReadSuffix->setObjectName(QString::fromUtf8("le_ReadSuffix"));
        le_ReadSuffix->setGeometry(QRect(130, 60, 181, 21));
        sizePolicy.setHeightForWidth(le_ReadSuffix->sizePolicy().hasHeightForWidth());
        le_ReadSuffix->setSizePolicy(sizePolicy);
        le_ReadSuffix->setFont(font);
        cbx_ReadEncoding = new QComboBox(GroupBox_ReadSettings);
        cbx_ReadEncoding->setObjectName(QString::fromUtf8("cbx_ReadEncoding"));
        cbx_ReadEncoding->setGeometry(QRect(130, 100, 181, 22));
        sizePolicy.setHeightForWidth(cbx_ReadEncoding->sizePolicy().hasHeightForWidth());
        cbx_ReadEncoding->setSizePolicy(sizePolicy);
        cbx_ReadEncoding->setEditable(false);
        cbx_ReadEncoding->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
        label_7 = new QLabel(GroupBox_ReadSettings);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 100, 81, 21));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setFont(font);
        label_4 = new QLabel(SericalTest);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(470, 110, 61, 21));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font);
        label_2 = new QLabel(SericalTest);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(482, 50, 54, 21));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);
        btn_OpenSerialPort = new QPushButton(SericalTest);
        btn_OpenSerialPort->setObjectName(QString::fromUtf8("btn_OpenSerialPort"));
        btn_OpenSerialPort->setGeometry(QRect(730, 20, 81, 141));
        sizePolicy.setHeightForWidth(btn_OpenSerialPort->sizePolicy().hasHeightForWidth());
        btn_OpenSerialPort->setSizePolicy(sizePolicy);
        btn_OpenSerialPort->setFont(font);
        te_Send = new QTextEdit(SericalTest);
        te_Send->setObjectName(QString::fromUtf8("te_Send"));
        te_Send->setGeometry(QRect(20, 340, 441, 51));
        sizePolicy.setHeightForWidth(te_Send->sizePolicy().hasHeightForWidth());
        te_Send->setSizePolicy(sizePolicy);
        te_Send->setFont(font);
        label_6 = new QLabel(SericalTest);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(482, 140, 54, 21));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setFont(font);
        btn_Send = new QPushButton(SericalTest);
        btn_Send->setObjectName(QString::fromUtf8("btn_Send"));
        btn_Send->setGeometry(QRect(130, 410, 331, 41));
        sizePolicy.setHeightForWidth(btn_Send->sizePolicy().hasHeightForWidth());
        btn_Send->setSizePolicy(sizePolicy);
        btn_Send->setFont(font);
        cbx_Parity = new QComboBox(SericalTest);
        cbx_Parity->setObjectName(QString::fromUtf8("cbx_Parity"));
        cbx_Parity->setGeometry(QRect(550, 110, 161, 22));
        sizePolicy.setHeightForWidth(cbx_Parity->sizePolicy().hasHeightForWidth());
        cbx_Parity->setSizePolicy(sizePolicy);
        cbx_Parity->setFont(font);
        GroupBox_SendSettings = new QGroupBox(SericalTest);
        GroupBox_SendSettings->setObjectName(QString::fromUtf8("GroupBox_SendSettings"));
        GroupBox_SendSettings->setGeometry(QRect(480, 170, 331, 141));
        sizePolicy.setHeightForWidth(GroupBox_SendSettings->sizePolicy().hasHeightForWidth());
        GroupBox_SendSettings->setSizePolicy(sizePolicy);
        GroupBox_SendSettings->setFont(font);
        cb_SendSpaceSuffix = new QCheckBox(GroupBox_SendSettings);
        cb_SendSpaceSuffix->setObjectName(QString::fromUtf8("cb_SendSpaceSuffix"));
        cb_SendSpaceSuffix->setGeometry(QRect(160, 30, 121, 21));
        sizePolicy.setHeightForWidth(cb_SendSpaceSuffix->sizePolicy().hasHeightForWidth());
        cb_SendSpaceSuffix->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Narrow"));
        font2.setPointSize(10);
        cb_SendSpaceSuffix->setFont(font2);
        cb_SendEnterSuffix = new QCheckBox(GroupBox_SendSettings);
        cb_SendEnterSuffix->setObjectName(QString::fromUtf8("cb_SendEnterSuffix"));
        cb_SendEnterSuffix->setGeometry(QRect(20, 30, 121, 21));
        sizePolicy.setHeightForWidth(cb_SendEnterSuffix->sizePolicy().hasHeightForWidth());
        cb_SendEnterSuffix->setSizePolicy(sizePolicy);
        cb_SendEnterSuffix->setFont(font1);
        le_SendSuffix = new QLineEdit(GroupBox_SendSettings);
        le_SendSuffix->setObjectName(QString::fromUtf8("le_SendSuffix"));
        le_SendSuffix->setGeometry(QRect(140, 70, 161, 21));
        sizePolicy.setHeightForWidth(le_SendSuffix->sizePolicy().hasHeightForWidth());
        le_SendSuffix->setSizePolicy(sizePolicy);
        le_SendSuffix->setFont(font);
        cb_SendSuffix = new QCheckBox(GroupBox_SendSettings);
        cb_SendSuffix->setObjectName(QString::fromUtf8("cb_SendSuffix"));
        cb_SendSuffix->setGeometry(QRect(20, 70, 121, 21));
        sizePolicy.setHeightForWidth(cb_SendSuffix->sizePolicy().hasHeightForWidth());
        cb_SendSuffix->setSizePolicy(sizePolicy);
        cb_SendSuffix->setFont(font1);
        cbx_SendEncoding = new QComboBox(GroupBox_SendSettings);
        cbx_SendEncoding->setObjectName(QString::fromUtf8("cbx_SendEncoding"));
        cbx_SendEncoding->setGeometry(QRect(140, 100, 161, 22));
        sizePolicy.setHeightForWidth(cbx_SendEncoding->sizePolicy().hasHeightForWidth());
        cbx_SendEncoding->setSizePolicy(sizePolicy);
        cbx_SendEncoding->setEditable(false);
        cbx_SendEncoding->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
        label_8 = new QLabel(GroupBox_SendSettings);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 100, 81, 21));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setFont(font);
        cbx_SerialName = new QComboBox(SericalTest);
        cbx_SerialName->setObjectName(QString::fromUtf8("cbx_SerialName"));
        cbx_SerialName->setGeometry(QRect(550, 20, 161, 22));
        sizePolicy.setHeightForWidth(cbx_SerialName->sizePolicy().hasHeightForWidth());
        cbx_SerialName->setSizePolicy(sizePolicy);
        cbx_SerialName->setFont(font);
        cbx_DataBit = new QComboBox(SericalTest);
        cbx_DataBit->setObjectName(QString::fromUtf8("cbx_DataBit"));
        cbx_DataBit->setGeometry(QRect(550, 80, 161, 22));
        sizePolicy.setHeightForWidth(cbx_DataBit->sizePolicy().hasHeightForWidth());
        cbx_DataBit->setSizePolicy(sizePolicy);
        cbx_DataBit->setFont(font);
        cbx_DataBit->setEditable(false);
        label_3 = new QLabel(SericalTest);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(482, 80, 54, 21));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font);
        cbx_Baud = new QComboBox(SericalTest);
        cbx_Baud->setObjectName(QString::fromUtf8("cbx_Baud"));
        cbx_Baud->setGeometry(QRect(550, 50, 161, 22));
        sizePolicy.setHeightForWidth(cbx_Baud->sizePolicy().hasHeightForWidth());
        cbx_Baud->setSizePolicy(sizePolicy);
        cbx_Baud->setFont(font);
        cbx_Baud->setEditable(true);
        te_Read = new QTextEdit(SericalTest);
        te_Read->setObjectName(QString::fromUtf8("te_Read"));
        te_Read->setEnabled(true);
        te_Read->setGeometry(QRect(22, 20, 441, 301));
        sizePolicy.setHeightForWidth(te_Read->sizePolicy().hasHeightForWidth());
        te_Read->setSizePolicy(sizePolicy);
        te_Read->setFont(font);
        te_Read->setReadOnly(true);
        label = new QLabel(SericalTest);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(482, 20, 54, 21));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font);
        btn_Clear = new QPushButton(SericalTest);
        btn_Clear->setObjectName(QString::fromUtf8("btn_Clear"));
        btn_Clear->setGeometry(QRect(20, 410, 81, 41));
        sizePolicy.setHeightForWidth(btn_Clear->sizePolicy().hasHeightForWidth());
        btn_Clear->setSizePolicy(sizePolicy);
        btn_Clear->setFont(font);
        cbx_StopBit = new QComboBox(SericalTest);
        cbx_StopBit->setObjectName(QString::fromUtf8("cbx_StopBit"));
        cbx_StopBit->setGeometry(QRect(550, 140, 161, 22));
        sizePolicy.setHeightForWidth(cbx_StopBit->sizePolicy().hasHeightForWidth());
        cbx_StopBit->setSizePolicy(sizePolicy);
        cbx_StopBit->setFont(font);

        retranslateUi(SericalTest);

        cbx_DataBit->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(SericalTest);
    } // setupUi

    void retranslateUi(QDialog *SericalTest)
    {
        SericalTest->setWindowTitle(QCoreApplication::translate("SericalTest", "\344\270\262\345\217\243Demo", nullptr));
        GroupBox_ReadSettings->setTitle(QCoreApplication::translate("SericalTest", "\346\216\245\346\224\266\346\240\274\345\274\217\350\256\276\347\275\256", nullptr));
        cb_ReadEnterSuffix->setText(QCoreApplication::translate("SericalTest", "\345\233\236\350\275\246\346\226\255\350\241\214", nullptr));
        cb_ReadSpaceSuffix->setText(QCoreApplication::translate("SericalTest", "\347\251\272\346\240\274\346\226\255\350\241\214", nullptr));
        cb_ReadSuffix->setText(QCoreApplication::translate("SericalTest", "\350\207\252\345\256\232\344\271\211\346\226\255\350\241\214\347\254\246", nullptr));
        cbx_ReadEncoding->setCurrentText(QString());
        label_7->setText(QCoreApplication::translate("SericalTest", "\350\207\252\345\256\232\344\271\211\347\274\226\347\240\201\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("SericalTest", "\345\245\207\345\201\266\346\240\241\351\252\214\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("SericalTest", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        btn_OpenSerialPort->setText(QCoreApplication::translate("SericalTest", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label_6->setText(QCoreApplication::translate("SericalTest", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        btn_Send->setText(QCoreApplication::translate("SericalTest", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        GroupBox_SendSettings->setTitle(QCoreApplication::translate("SericalTest", "\345\217\221\351\200\201\346\240\274\345\274\217\350\256\276\347\275\256", nullptr));
        cb_SendSpaceSuffix->setText(QCoreApplication::translate("SericalTest", "\347\251\272\346\240\274\346\226\255\350\241\214", nullptr));
        cb_SendEnterSuffix->setText(QCoreApplication::translate("SericalTest", "\345\233\236\350\275\246\346\226\255\350\241\214", nullptr));
        cb_SendSuffix->setText(QCoreApplication::translate("SericalTest", "\350\207\252\345\256\232\344\271\211\346\226\255\350\241\214\347\254\246", nullptr));
        cbx_SendEncoding->setCurrentText(QString());
        label_8->setText(QCoreApplication::translate("SericalTest", "\350\207\252\345\256\232\344\271\211\347\274\226\347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("SericalTest", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        cbx_Baud->setCurrentText(QString());
        label->setText(QCoreApplication::translate("SericalTest", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        btn_Clear->setText(QCoreApplication::translate("SericalTest", "\346\270\205\347\251\272\346\216\245\346\224\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SericalTest: public Ui_SericalTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERICALTEST_H
