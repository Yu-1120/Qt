/********************************************************************************
** Form generated from reading UI file 'mytext.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTEXT_H
#define UI_MYTEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyText
{
public:
    QAction *action_new;
    QAction *action_open;
    QAction *action_undo;
    QAction *action_save;
    QAction *action_saveas;
    QAction *action_exit;
    QAction *action_cut;
    QAction *action_copy;
    QAction *action_paste;
    QAction *action_del;
    QAction *action_find;
    QAction *action_replay;
    QAction *action_all;
    QAction *action_font;
    QAction *action_redo;
    QAction *actionabout_mu;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MyText)
    {
        if (MyText->objectName().isEmpty())
            MyText->setObjectName(QString::fromUtf8("MyText"));
        MyText->setEnabled(true);
        MyText->resize(800, 480);
        MyText->setTabletTracking(false);
        MyText->setAcceptDrops(false);
        MyText->setAutoFillBackground(false);
        action_new = new QAction(MyText);
        action_new->setObjectName(QString::fromUtf8("action_new"));
        action_new->setCheckable(false);
        action_new->setEnabled(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/actions/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_new->setIcon(icon);
        action_new->setIconVisibleInMenu(true);
        action_open = new QAction(MyText);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        action_open->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/actions/document-open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_open->setIcon(icon1);
        action_undo = new QAction(MyText);
        action_undo->setObjectName(QString::fromUtf8("action_undo"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/actions/edit-undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_undo->setIcon(icon2);
        action_save = new QAction(MyText);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        action_save->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/actions/filesaveas.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_save->setIcon(icon3);
        action_saveas = new QAction(MyText);
        action_saveas->setObjectName(QString::fromUtf8("action_saveas"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/actions/gtk-save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_saveas->setIcon(icon4);
        action_exit = new QAction(MyText);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/actions/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon5);
        action_cut = new QAction(MyText);
        action_cut->setObjectName(QString::fromUtf8("action_cut"));
        action_copy = new QAction(MyText);
        action_copy->setObjectName(QString::fromUtf8("action_copy"));
        action_paste = new QAction(MyText);
        action_paste->setObjectName(QString::fromUtf8("action_paste"));
        action_del = new QAction(MyText);
        action_del->setObjectName(QString::fromUtf8("action_del"));
        action_find = new QAction(MyText);
        action_find->setObjectName(QString::fromUtf8("action_find"));
        action_replay = new QAction(MyText);
        action_replay->setObjectName(QString::fromUtf8("action_replay"));
        action_all = new QAction(MyText);
        action_all->setObjectName(QString::fromUtf8("action_all"));
        action_font = new QAction(MyText);
        action_font->setObjectName(QString::fromUtf8("action_font"));
        action_redo = new QAction(MyText);
        action_redo->setObjectName(QString::fromUtf8("action_redo"));
        action_redo->setMenuRole(QAction::AboutQtRole);
        actionabout_mu = new QAction(MyText);
        actionabout_mu->setObjectName(QString::fromUtf8("actionabout_mu"));
        centralwidget = new QWidget(MyText);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMouseTracking(true);
        centralwidget->setTabletTracking(true);
        centralwidget->setAutoFillBackground(false);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 791, 421));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        textEdit->setFont(font);
        textEdit->setTabletTracking(false);
        MyText->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MyText);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MyText->setMenuBar(menubar);
        statusbar = new QStatusBar(MyText);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MyText->setStatusBar(statusbar);
        toolBar = new QToolBar(MyText);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        toolBar->setMouseTracking(true);
        toolBar->setTabletTracking(false);
        toolBar->setAcceptDrops(false);
        toolBar->setAutoFillBackground(false);
        toolBar->setMovable(false);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextOnly);
        toolBar->setFloatable(true);
        MyText->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(action_new);
        menu->addAction(action_open);
        menu->addAction(action_save);
        menu->addAction(action_saveas);
        menu->addSeparator();
        menu->addAction(action_exit);
        menu->addAction(actionabout_mu);
        menu_2->addAction(action_undo);
        menu_2->addAction(action_redo);
        menu_2->addSeparator();
        menu_2->addAction(action_cut);
        menu_2->addAction(action_copy);
        menu_2->addAction(action_paste);
        menu_2->addAction(action_del);
        menu_2->addSeparator();
        menu_2->addAction(action_find);
        menu_2->addAction(action_replay);
        menu_2->addSeparator();
        menu_2->addAction(action_all);
        menu_3->addAction(action_font);
        toolBar->addAction(action_open);
        toolBar->addAction(action_save);
        toolBar->addAction(action_new);
        toolBar->addAction(action_saveas);
        toolBar->addSeparator();
        toolBar->addAction(action_undo);
        toolBar->addAction(action_redo);
        toolBar->addSeparator();
        toolBar->addAction(action_cut);
        toolBar->addAction(action_copy);
        toolBar->addAction(action_paste);
        toolBar->addSeparator();
        toolBar->addAction(action_find);
        toolBar->addAction(action_replay);

        retranslateUi(MyText);

        QMetaObject::connectSlotsByName(MyText);
    } // setupUi

    void retranslateUi(QMainWindow *MyText)
    {
        MyText->setWindowTitle(QCoreApplication::translate("MyText", "MyText", nullptr));
        action_new->setText(QCoreApplication::translate("MyText", "\346\226\260\345\273\272", nullptr));
#if QT_CONFIG(shortcut)
        action_new->setShortcut(QCoreApplication::translate("MyText", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        action_open->setText(QCoreApplication::translate("MyText", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(shortcut)
        action_open->setShortcut(QCoreApplication::translate("MyText", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_undo->setText(QCoreApplication::translate("MyText", "\346\222\244\351\224\200", nullptr));
#if QT_CONFIG(shortcut)
        action_undo->setShortcut(QCoreApplication::translate("MyText", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        action_save->setText(QCoreApplication::translate("MyText", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(shortcut)
        action_save->setShortcut(QCoreApplication::translate("MyText", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_saveas->setText(QCoreApplication::translate("MyText", "\345\217\246\345\255\230\344\270\272", nullptr));
#if QT_CONFIG(shortcut)
        action_saveas->setShortcut(QCoreApplication::translate("MyText", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_exit->setText(QCoreApplication::translate("MyText", "\351\200\200\345\207\272", nullptr));
        action_cut->setText(QCoreApplication::translate("MyText", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(shortcut)
        action_cut->setShortcut(QCoreApplication::translate("MyText", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        action_copy->setText(QCoreApplication::translate("MyText", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(shortcut)
        action_copy->setShortcut(QCoreApplication::translate("MyText", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        action_paste->setText(QCoreApplication::translate("MyText", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(shortcut)
        action_paste->setShortcut(QCoreApplication::translate("MyText", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        action_del->setText(QCoreApplication::translate("MyText", "\345\210\240\351\231\244", nullptr));
#if QT_CONFIG(shortcut)
        action_del->setShortcut(QCoreApplication::translate("MyText", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        action_find->setText(QCoreApplication::translate("MyText", "\346\237\245\346\211\276", nullptr));
#if QT_CONFIG(shortcut)
        action_find->setShortcut(QCoreApplication::translate("MyText", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        action_replay->setText(QCoreApplication::translate("MyText", "\346\233\277\346\215\242", nullptr));
#if QT_CONFIG(shortcut)
        action_replay->setShortcut(QCoreApplication::translate("MyText", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        action_all->setText(QCoreApplication::translate("MyText", "\345\205\250\351\200\211", nullptr));
#if QT_CONFIG(shortcut)
        action_all->setShortcut(QCoreApplication::translate("MyText", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        action_font->setText(QCoreApplication::translate("MyText", "\345\255\227\344\275\223", nullptr));
        action_redo->setText(QCoreApplication::translate("MyText", "\345\217\226\346\266\210\346\222\244\351\224\200", nullptr));
        actionabout_mu->setText(QCoreApplication::translate("MyText", "about mu", nullptr));
        menu->setTitle(QCoreApplication::translate("MyText", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MyText", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MyText", "\346\240\274\345\274\217", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MyText", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyText: public Ui_MyText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTEXT_H
