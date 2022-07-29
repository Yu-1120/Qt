#include "mywidget.h"
#include <QFont>
#include <QPalette>
#include <QColor>
#include <QCursor>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    //初始化窗口部件成员
    lab1 = new QLabel(this);
    lab2 = new QLabel(this);

    //设置文字
    lab1->setText("下雨了,收衣服了");
    lab2->setText("你骗人,没下雨");
    lab1->resize(300,50);
    //移动位置
    lab1->move(100,100);
    lab2->move(240,240);

    //设置lab1的字体
    QFont f("Times",16,16,true/*斜体*/);
    lab1->setFont(f);

    //设置lab1字体的颜色
    QColor c(0,0,255);
    QPalette p;//调色板
    p.setColor(QPalette::WindowText/*设置文本颜色*/,c);
    lab1->setPalette(p);//设置调色板

    c.setRgb(255,0,0);
    p.setColor(QPalette::WindowText/*设置文本颜色*/,c);
    lab2->setPalette(p);//设置调色板

    //设置鼠标形状
    QCursor cs(Qt::PointingHandCursor/*小手*/);
    lab2->setCursor(cs);
}

MyWidget::~MyWidget()
{

}

