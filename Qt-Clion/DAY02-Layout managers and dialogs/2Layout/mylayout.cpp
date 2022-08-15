#include "mylayout.h"
#include <QDebug>
#include <QHBoxLayout>

MyLayout::MyLayout(QWidget *parent)
        : QWidget(parent) {

    lab1 = new QLabel("lab1", this);
    lab2 = new QLabel("lab2", this);
    btn1 = new QPushButton("btn1", this);
    btn2 = new QPushButton("btn2", this);

    //��ʼ�����ֹ�����
    layout = new QHBoxLayout;  //ˮƽ����
//    layout = new QVBoxLayout; //��ֱ����
    //layout = new QGridLayout;

    //�����ڲ������뵽���ֹ�����

    layout->addWidget(lab1);
    layout->addWidget(lab2);
    layout->addWidget(btn1);
    layout->addWidget(btn2);


//    layout->addWidget(lab1,0,0);
//    layout->addWidget(lab2,0,1);
//    layout->addWidget(btn1,1,0);
//    layout->addWidget(btn2,1,1);

    //���ô��ڵĲ��ֹ�����
    this->setLayout(layout);

    qDebug() << layout->parent();
    qDebug() << this;
}

MyLayout::~MyLayout() {

}

