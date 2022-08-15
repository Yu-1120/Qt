#include "widgetitem.h"
#include <QDebug>

WidgetItem::WidgetItem(QWidget *parent)
    : QWidget(parent)
{
    lab = new QLabel("你好",this);
    edit = new QLineEdit(this);

    lyt = new QVBoxLayout;
    lyt->addWidget(lab);
    lyt->addWidget(edit);

    this->setLayout(lyt);

    //QLineEdit信号
    QObject::connect(edit,&QLineEdit::textChanged,this,[&](const QString &str){//文本改变
        qDebug()<<"textChanged:"<<str;
    });

    QObject::connect(edit,&QLineEdit::textEdited,this,[&](const QString &str){//文本改变
        qDebug()<<"textEdited:"<<str;
    });

    QObject::connect(edit,&QLineEdit::returnPressed,this,[&](){//文本改变
        qDebug()<<"returnPressed";
    });

    edit->setText("111");
}

WidgetItem::~WidgetItem()
{

}

