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
        //这个开源通过下面  edit->setText("111");触发
        //说明这个通过代码来发生sinal来驱动slots
        /*

        [signal] void QLineEdit::textChanged(const QString &text)
        This signal is emitted whenever the text changes. The text argument is the new text.
        Unlike textEdited(), this signal is also emitted when the text is changed programmatically, for example, by calling setText().
        Note: Notifier signal for property text.

        [signal] void QLineEdit::textEdited(const QString &text)
        This signal is emitted whenever the text is edited. The text argument is the new text.
        Unlike textChanged(), this signal is not emitted when the text is changed programmatically, for example, by calling setText().

       */

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

