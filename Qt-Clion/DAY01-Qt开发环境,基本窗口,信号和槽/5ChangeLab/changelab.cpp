#include "changelab.h"

ChangeLab::ChangeLab(QWidget *parent)
    : QWidget(parent)
{
    lab = new QLabel("你好",this);
    red_btn = new QPushButton("红色",this);
    green_btn = new QPushButton("绿色",this);
    blue_btn = new QPushButton("蓝色",this);

    lab->move(480,200);
    red_btn->move(200,600);
    green_btn->move(550,600);
    blue_btn->move(700,600);

    QObject::connect(red_btn,&QPushButton::clicked,this,[&](){
        QColor c(255,0,0);
        QPalette p;//调色板
        p.setColor(QPalette::WindowText/*设置文本颜色*/,c);
        lab->setPalette(p);//设置调色板
    });

    QObject::connect(green_btn,&QPushButton::clicked,this,[&](){
        QColor c(0,255,0);
        QPalette p;//调色板
        p.setColor(QPalette::WindowText/*设置文本颜色*/,c);
        lab->setPalette(p);//设置调色板
    });
    QObject::connect(blue_btn,&QPushButton::clicked,this,[&](){
        QColor c(0,0,255);
        QPalette p;//调色板
        p.setColor(QPalette::WindowText/*设置文本颜色*/,c);
        lab->setPalette(p);//设置调色板
    });

}

ChangeLab::~ChangeLab()
{

}

