#include "changelab.h"
#include <QInputDialog>
#include <QColorDialog>
#include <QFontDialog>

ChangeLab::ChangeLab(QWidget *parent)
    : QWidget(parent)
{

    lab = new QLabel("你好你好你好你好你好你好",this);
    text_btn = new QPushButton("设置内容",this);
    color_btn = new QPushButton("设置颜色",this);
    font_btn = new QPushButton("设置字体",this);

    hlyt = new QHBoxLayout;
    lyt = new QVBoxLayout;

    //将窗口部件加入到布局管理器
    hlyt->addWidget(text_btn);
    hlyt->addWidget(color_btn);
    hlyt->addWidget(font_btn);

    lyt->addWidget(lab);
    lyt->addLayout(hlyt);

    //设置内容
    QObject::connect(text_btn,&QPushButton::clicked,this,[&](){
        QString str = QInputDialog::getText(this,"输入内容","请输入文本信息");
        lab->setText(str);
    });

    //设置颜色
    QObject::connect(color_btn,&QPushButton::clicked,this,[&](){
        QColor c = QColorDialog::getColor(Qt::black,this,"选择颜色");
        QPalette p;
        p.setColor(QPalette::WindowText,c);
        lab->setPalette(p);
    });

    //设置字体
    QObject::connect(font_btn,&QPushButton::clicked,this,[&](){
        bool flag = true;
        QFont f = QFontDialog::getFont(&flag,this);
        lab->setFont(f);
    });

    //设置窗口布局管理器
    this->setLayout(lyt);
}

ChangeLab::~ChangeLab()
{
}

