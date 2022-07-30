#include "mylayout.h"
#include <QDebug>

MyLayout::MyLayout(QWidget *parent)
    : QWidget(parent)
{
    lab1 = new QLabel("lab1",this);
    lab2 = new QLabel("lab2",this);
    btn1 = new QPushButton("btn1",this);
    btn2 = new QPushButton("btn2",this);

    //初始化布局管理器
    //layout = new QHBoxLayout;  //水平布局
    layout = new QVBoxLayout; //垂直布局
    //layout = new QGridLayout;

    //将窗口部件加入到布局管理器

    layout->addWidget(lab1);
    layout->addWidget(lab2);
    layout->addWidget(btn1);
    layout->addWidget(btn2);


//    layout->addWidget(lab1,0,0);
//    layout->addWidget(lab2,0,1);
//    layout->addWidget(btn1,1,0);
//    layout->addWidget(btn2,1,1);

    //设置窗口的布局管理器
    this->setLayout(layout);

    qDebug()<<layout->parent();
    qDebug()<<this;
}

MyLayout::~MyLayout()
{

}

