#include "mywidget.h"
#include <QFont>
#include <QPalette>
#include <QColor>
#include <QCursor>


MyWidget::MyWidget(QWidget *parent)
        : QWidget(parent) {
    QString::fromLocal8Bit("中文");
    //初始化窗口部件成员
    lab1 = new QLabel(this);//this是父对象
    lab2 = new QLabel(this);

    //设置文字
//    lab2->setText("一点也不好笑"); 这样写会乱码

    lab1->setText(QString::fromLocal8Bit("你好世界"));
    lab2->setText(QString::fromLocal8Bit("一点也不好笑"));

    //移动位置
    lab1->move(400, 240);
    //lab1->resize(100,20);字的大小跟纸无关

    //设置lab1的字体 32 X 32
    QFont f("Times", 16, 16, true/*斜体*/);
    lab1->setFont(f);

    //设置lab1字体的颜色
    QColor c(255, 0, 0);//大红
    QPalette p;//调色板，很多颜色，调试板的类要传（颜色类）
    p.setColor(QPalette::WindowText/*设置文本颜色*/, c);
    lab1->setPalette(p);//设置调色板

    //设置鼠标形状
    //QCursor cs(Qt::CrossCursor/*准心*/);
    QCursor cs(Qt::PointingHandCursor/*小手*/);
    lab1->setCursor(cs);
}

MyWidget::~MyWidget() {
}

