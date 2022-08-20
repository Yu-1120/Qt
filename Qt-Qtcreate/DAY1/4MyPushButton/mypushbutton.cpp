#include "mypushbutton.h"
#include <QDebug>

MyPushButton::MyPushButton(QWidget *parent)
    : QWidget(parent)
{
    btn = new QPushButton(this);
    btn->setText("点我");

    btn->move(400,400);

    //连接信号和槽
    //QObject::connect(btn,SIGNAL(clicked()),this,SLOT(btn_clicked()));
    //QObject::connect(btn,&QPushButton::clicked,this,&MyPushButton::btn_clicked);
    QObject::connect(btn,&QPushButton::clicked,this,[&](){
        qDebug()<<"Lambda表达式slot";
    });

    //连接信号和信号
    QObject::connect(this,SIGNAL(send_sig(int)),btn,SIGNAL(clicked()));
    QObject::connect(this,&MyPushButton::send_sig,this,[&](int n){
        qDebug()<<"num="<<n;
    });

    //代码发射信号
    emit send_sig(100);
}

MyPushButton::~MyPushButton()
{
}

//槽函数的实现
void MyPushButton::btn_clicked()
{
    //qDebug是Qt的调试输出，可以像printf和cout一样使用
    qDebug()<<"btn_clicked";
}

