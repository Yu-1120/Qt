#include "changelab.h"

ChangeLab::ChangeLab(QWidget *parent)
    : QWidget(parent)
{
    lab = new QLabel("你好你好你好你好你好你好",this);
    text_btn = new QPushButton("切换内容",this);
    color_btn = new QPushButton("切换颜色",this);

    text_flag = true;
    color_flag = true;

    hlyt = new QHBoxLayout;
    lyt = new QVBoxLayout;

    //将窗口部件加入到布局管理器
    hlyt->addWidget(text_btn);
    hlyt->addWidget(color_btn);

    lyt->addWidget(lab);
    lyt->addLayout(hlyt);

    QObject::connect(text_btn,&QPushButton::clicked,this,[&](){
        if(text_flag){
            lab->setText("再见");
            text_flag = false;
        }
        else{
            lab->setText("你好你好你好你好你好你好");
            text_flag = true;
        }
    });

    QObject::connect(color_btn,&QPushButton::clicked,this,[&](){
        if(color_flag){
            QColor c(0,255,0);
            QPalette p;
            p.setColor(QPalette::WindowText,c);
            lab->setPalette(p);
            color_flag = false;
        }
        else{
            QColor c(0,0,255);
            QPalette p;
            p.setColor(QPalette::WindowText,c);
            lab->setPalette(p);
            color_flag = true;
        }
    });

    //设置窗口布局管理器
    this->setLayout(lyt);
}

ChangeLab::~ChangeLab()
{
}

