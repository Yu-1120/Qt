#include "ButtonText.h"
#include <QDebug>

ButtonText::ButtonText(QWidget *parent)
    : QWidget(parent)
{
    btn = new QPushButton(this);
    btn->setText("点我");

    btn->move(400,400);

//    连接信号和槽
    QObject::connect(btn,SIGNAL(clicked()),this,SLOT(btn_clicked()));
    //第二个参数是固定写法，都可以这么写。还加上如下的写法
//    -----------------------------------------------------------
//    QObject::connect(btn,&QPushButton::clicked,this,&ButtonText::btn_clicked);
//    QObject::connect(btn,&QPushButton::clicked,this,[&](){  //(对象，信号，接收对象的函数，槽函数是)
//        qDebug()<<"HELLOworld";
//    });

    //连接信号和信号
//    QObject::connect(this,SIGNAL(send_sig(int)),btn,SIGNAL(clicked()));
//    QObject::connect(this,&ButtonText::send_sig,this,[&](int n){
//        qDebug()<<"num="<<n;
//    });

    //代码发射信号
    emit send_sig(100);
}

ButtonText::~ButtonText()
{
}

//槽函数的实现
void ButtonText::btn_clicked()
{
    //qDebug是Qt的调试输出，可以像printf和cout一样使用
    qDebug()<<"btn_clicked";
}

