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
//    QObject::connect(btn,&QPushButton::clicked,this,&MyPushButton::btn_clicked);
    //(对象，信号，接收对象的函数，槽函数是)
    QObject::connect(btn,&QPushButton::clicked,this,[&](){  //槽函数是匿名函数的写法

        qDebug()<<"Lambda表达式slot0---";
    });

    //代码发射信号
    emit send_sig(100);

    //连接信号和信号  自己传给自己
    QObject::connect(this,SIGNAL(send_sig(int)),btn,SIGNAL(clicked()));
//    QObject::connect(this,&MyPushButton::send_sig,this,[&](int n){
//        qDebug()<<"num="<<n;
//    });


}

MyPushButton::~MyPushButton()
{
}

//槽函数的实现
void MyPushButton::btn_clicked()
{
    //qDebug是Qt的调试输出，可以像printf和cout一样使用
    //qt里的cout
    qDebug()<<"btn_clicked";
}

