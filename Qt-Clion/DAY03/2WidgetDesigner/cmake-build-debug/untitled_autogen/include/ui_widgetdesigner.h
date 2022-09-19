/********************************************************************************
** Form generated from reading UI file 'widgetdesigner.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETDESIGNER_H
#define UI_WIDGETDESIGNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetDesigner
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton;
    QSlider *horizontalSlider;

    void setupUi(QWidget *WidgetDesigner)
    {
        if (WidgetDesigner->objectName().isEmpty())
            WidgetDesigner->setObjectName(QString::fromUtf8("WidgetDesigner"));
        WidgetDesigner->resize(502, 352);
        WidgetDesigner->setCursor(QCursor(Qt::PointingHandCursor));
        gridLayoutWidget = new QWidget(WidgetDesigner);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 481, 311));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(14);
        pushButton_2->setFont(font);

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(200, 50));
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        horizontalSlider = new QSlider(gridLayoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setValue(50);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 1, 1, 1, 1);


        retranslateUi(WidgetDesigner);

        QMetaObject::connectSlotsByName(WidgetDesigner);
    } // setupUi

    void retranslateUi(QWidget *WidgetDesigner)
    {
        WidgetDesigner->setWindowTitle(QCoreApplication::translate("WidgetDesigner", "WidgetDesigner", nullptr));
        pushButton_2->setText(QCoreApplication::translate("WidgetDesigner", "\346\265\213\350\257\225\346\214\211\351\222\256", nullptr));
        label->setText(QCoreApplication::translate("WidgetDesigner", "\345\207\206\345\244\207\344\270\212\350\257\276", nullptr));
        pushButton->setText(QCoreApplication::translate("WidgetDesigner", "\346\265\213\350\257\225\346\214\211\351\222\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetDesigner: public Ui_WidgetDesigner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETDESIGNER_H
