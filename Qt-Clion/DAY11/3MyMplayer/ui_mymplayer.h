/********************************************************************************
** Form generated from reading UI file 'mymplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMPLAYER_H
#define UI_MYMPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMplayer
{
public:
    QPushButton *pushButton_prev;
    QPushButton *pushButton_deletevideo;
    QPushButton *pushButton_addvideo;
    QPushButton *pushButton_next;
    QPushButton *pushButton_clearvideo;
    QListWidget *listWidget;
    QPushButton *pushButton_play;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_stop_cont;
    QLabel *label;

    void setupUi(QWidget *MyMplayer)
    {
        if (MyMplayer->objectName().isEmpty())
            MyMplayer->setObjectName(QStringLiteral("MyMplayer"));
        MyMplayer->resize(800, 480);
        pushButton_prev = new QPushButton(MyMplayer);
        pushButton_prev->setObjectName(QStringLiteral("pushButton_prev"));
        pushButton_prev->setGeometry(QRect(370, 400, 100, 40));
        pushButton_deletevideo = new QPushButton(MyMplayer);
        pushButton_deletevideo->setObjectName(QStringLiteral("pushButton_deletevideo"));
        pushButton_deletevideo->setGeometry(QRect(655, 370, 100, 40));
        pushButton_addvideo = new QPushButton(MyMplayer);
        pushButton_addvideo->setObjectName(QStringLiteral("pushButton_addvideo"));
        pushButton_addvideo->setGeometry(QRect(655, 310, 100, 40));
        pushButton_next = new QPushButton(MyMplayer);
        pushButton_next->setObjectName(QStringLiteral("pushButton_next"));
        pushButton_next->setGeometry(QRect(490, 400, 100, 40));
        pushButton_clearvideo = new QPushButton(MyMplayer);
        pushButton_clearvideo->setObjectName(QStringLiteral("pushButton_clearvideo"));
        pushButton_clearvideo->setGeometry(QRect(655, 430, 100, 40));
        listWidget = new QListWidget(MyMplayer);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(610, 10, 181, 281));
        pushButton_play = new QPushButton(MyMplayer);
        pushButton_play->setObjectName(QStringLiteral("pushButton_play"));
        pushButton_play->setGeometry(QRect(10, 400, 100, 40));
        pushButton_cancel = new QPushButton(MyMplayer);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(130, 400, 100, 40));
        pushButton_stop_cont = new QPushButton(MyMplayer);
        pushButton_stop_cont->setObjectName(QStringLiteral("pushButton_stop_cont"));
        pushButton_stop_cont->setEnabled(false);
        pushButton_stop_cont->setGeometry(QRect(250, 400, 100, 40));
        label = new QLabel(MyMplayer);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 600, 360));
        label->setStyleSheet(QStringLiteral("background-color: rgb(170, 0, 255);"));

        retranslateUi(MyMplayer);

        QMetaObject::connectSlotsByName(MyMplayer);
    } // setupUi

    void retranslateUi(QWidget *MyMplayer)
    {
        MyMplayer->setWindowTitle(QApplication::translate("MyMplayer", "MyMplayer", 0));
        pushButton_prev->setText(QApplication::translate("MyMplayer", "\344\270\212\344\270\200\344\270\252", 0));
        pushButton_deletevideo->setText(QApplication::translate("MyMplayer", "\345\210\240\351\231\244\350\247\206\351\242\221", 0));
        pushButton_addvideo->setText(QApplication::translate("MyMplayer", "\346\267\273\345\212\240\350\247\206\351\242\221", 0));
        pushButton_next->setText(QApplication::translate("MyMplayer", "\344\270\213\344\270\200\344\270\252", 0));
        pushButton_clearvideo->setText(QApplication::translate("MyMplayer", "\346\270\205\347\251\272\350\247\206\351\242\221", 0));
        pushButton_play->setText(QApplication::translate("MyMplayer", "\346\222\255\346\224\276", 0));
        pushButton_cancel->setText(QApplication::translate("MyMplayer", "\345\201\234\346\255\242", 0));
        pushButton_stop_cont->setText(QApplication::translate("MyMplayer", "\346\232\202\345\201\234", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyMplayer: public Ui_MyMplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMPLAYER_H
