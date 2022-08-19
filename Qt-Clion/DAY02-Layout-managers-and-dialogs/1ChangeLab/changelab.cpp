#include "changelab.h"
#include <QColor>
#include <QPalette>

ChangeLab::ChangeLab(QWidget *parent)
        : QWidget(parent) {

    lab = new QLabel(QString::fromLocal8Bit("���"), this);
    text_btn = new QPushButton(QString::fromLocal8Bit("�л�����"), this);
    color_btn = new QPushButton(QString::fromLocal8Bit("�л���ɫ"), this);


    text_flag = true;
    color_flag = true;

    lab->move(360, 100);
    text_btn->move(200, 300);
    color_btn->move(600, 300);

    QObject::connect(text_btn, &QPushButton::clicked, this, [&]() {
        if (text_flag) {
            lab->setText(QString::fromLocal8Bit("�ټ�"));
            text_flag = false;
        } else {
            lab->setText(QString::fromLocal8Bit("���"));
            text_flag = true;
        }
    });

    QObject::connect(color_btn, &QPushButton::clicked, this, [&]() {
        if (color_flag) {
            QColor c(0, 255, 0);
            QPalette p;
            p.setColor(QPalette::WindowText, c);
            lab->setPalette(p);
            color_flag = false;
        } else {
            QColor c(0, 0, 255);
            QPalette p;
            p.setColor(QPalette::WindowText, c);
            lab->setPalette(p);
            color_flag = true;
        }
    });
}

ChangeLab::~ChangeLab() {
}

