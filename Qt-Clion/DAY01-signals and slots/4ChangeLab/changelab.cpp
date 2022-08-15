#include "changelab.h"
#include <QDebug>

int flag = 0;

ChangeLab::ChangeLab(QWidget *parent)
        : QWidget(parent) {


    lab = new QLabel(QString::fromLocal8Bit("���"), this);
    red_btn = new QPushButton(QString::fromLocal8Bit("��ɫ"), this);
    green_btn = new QPushButton(QString::fromLocal8Bit("��ɫ"), this);
    blue_btn = new QPushButton(QString::fromLocal8Bit("��ɫ"), this);
//    openswitch = new QPushButton(QString::fromLocal8Bit("�򿪰�ť"), this);

    lab->move(480, 200);
    red_btn->move(400, 600);
    green_btn->move(550, 600);
    blue_btn->move(700, 600);
//    openswitch->move(0, 300);


    QObject::connect(red_btn, &QPushButton::clicked, this, [&]() {
        if (flag1) {
            QColor c(255, 0, 0);
            QPalette p;//��ɫ��
            p.setColor(QPalette::WindowText/*�����ı���ɫ*/, c);
            lab->setPalette(p);//���õ�ɫ��
            flag1 = false;

        } else {
            QColor c(0, 0, 0);
            QPalette p;//��ɫ��
            p.setColor(QPalette::WindowText/*�����ı���ɫ*/, c);
            lab->setPalette(p);//���õ�ɫ��
            flag1 = true;
        }
    });

    QObject::connect(green_btn, &QPushButton::clicked, this, &ChangeLab::btn_clicked);

    QObject::connect(blue_btn, &QPushButton::clicked, this, [&]() {
        if (flag3) {
            QColor c(0, 0, 255);
            QPalette p;//��ɫ��
            p.setColor(QPalette::WindowText/*�����ı���ɫ*/, c);
            lab->setPalette(p);//���õ�ɫ��

        } else {
            QColor c(0, 0, 0);
            QPalette p;//��ɫ��
            p.setColor(QPalette::WindowText/*�����ı���ɫ*/, c);
            lab->setPalette(p);//���õ�ɫ��
        }
        flag3 = !flag3;
    });
}

void ChangeLab::btn_clicked() {
    if (flag2) {
        QColor c(0, 255, 0);
        QPalette p;//��ɫ��
        p.setColor(QPalette::WindowText/*�����ı���ɫ*/, c);
        lab->setPalette(p);//���õ�ɫ��
        flag2 = false;
    } else {
        QColor c(0, 0, 0);
        QPalette p;//��ɫ��
        p.setColor(QPalette::WindowText/*�����ı���ɫ*/, c);
        lab->setPalette(p);//���õ�ɫ��
        flag2 = true;
    }
}

ChangeLab::~ChangeLab() {

}
