#include "multilayout.h"

MultiLayout::MultiLayout(QWidget *parent)
    : QWidget(parent)
{
    lab1 = new QLabel("lab1",this);
    lab2 = new QLabel("lab2",this);
    btn1 = new QPushButton("btn1",this);
    btn2 = new QPushButton("btn2",this);
    AA = new QPushButton("AA",this);
    BB = new QPushButton("BB",this);
    CC = new QPushButton("CC",this);

    //initialize layout supervisor
    hlayout1 = new QHBoxLayout;
    hlayout2 = new QHBoxLayout;
    hlayout3 = new QHBoxLayout; //水平
    layout = new QVBoxLayout;  //垂直

    //添加窗口部件到布局管理器  add windows in layout supervisor
    hlayout1->addWidget(lab1);
    hlayout1->addWidget(btn1);
    hlayout2->addWidget(lab2);
    hlayout2->addWidget(btn2);
    hlayout3->addWidget(AA);
    hlayout3->addWidget(BB);
    hlayout3->addWidget(CC);
    //将布局管理器加入到布局管理器
    layout->addLayout(hlayout1);
    layout->addLayout(hlayout2);
    layout->addLayout(hlayout3);

    //设置窗口布局管理器
    this->setLayout(layout);//vertical set up enter
}

MultiLayout::~MultiLayout()
{
}

