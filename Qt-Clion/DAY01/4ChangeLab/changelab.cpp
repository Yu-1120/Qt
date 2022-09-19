#include "changelab.h"
#include <QDebug>

int flag = 0;

ChangeLab::ChangeLab(QWidget *parent)
        : QWidget(parent) {


    lab = new QLabel(QString::fromLocal8Bit("你好"), this);
    red_btn = new QPushButton(QString::fromLocal8Bit("红色"), this);
    green_btn = new QPushButton(QString::fromLocal8Bit("绿色"), this);
    blue_btn = new QPushButton(QString::fromLocal8Bit("蓝色"), this);
//    openswitch = new QPushButton(QString::fromLocal8Bit("打开按钮"), this);

    lab->move(480, 200);
    red_btn->move(400, 600);
    green_btn->move(550, 600);
    blue_btn->move(700, 600);
//    openswitch->move(0, 300);


    QObject::connect(red_btn, &QPushButton::clicked, this, [&]() {
        if (flag1) {
            QColor c(255, 0, 0);
            QPalette p;//调色板
            p.setColor(QPalette::WindowText/*设置文本颜色*/, c);
            lab->setPalette(p);//设置调色板
            flag1 = false;

        } else {
            QColor c(0, 0, 0);
            QPalette p;//调色板
            p.setColor(QPalette::WindowText/*设置文本颜色*/, c);
            lab->setPalette(p);//设置调色板
            flag1 = true;
        }
    });

    QObject::connect(green_btn, &QPushButton::clicked, this, &ChangeLab::btn_clicked);

    QObject::connect(blue_btn, &QPushButton::clicked, this, [&]() {
        if (flag3) {
            QColor c(0, 0, 255);
            QPalette p;//调色板
            p.setColor(QPalette::WindowText/*设置文本颜色*/, c);
            lab->setPalette(p);//设置调色板

        } else {
            QColor c(0, 0, 0);
            QPalette p;//调色板
            p.setColor(QPalette::WindowText/*设置文本颜色*/, c);
            lab->setPalette(p);//设置调色板
        }
        flag3 = !flag3;
    });
}

void ChangeLab::btn_clicked() {
    if (flag2) {
        QColor c(0, 255, 0);
        QPalette p;//调色板
        p.setColor(QPalette::WindowText/*设置文本颜色*/, c);
        lab->setPalette(p);//设置调色板
        flag2 = false;
    } else {
        QColor c(0, 0, 0);
        QPalette p;//调色板
        p.setColor(QPalette::WindowText/*设置文本颜色*/, c);
        lab->setPalette(p);//设置调色板
        flag2 = true;
    }
}

ChangeLab::~ChangeLab() {

}
