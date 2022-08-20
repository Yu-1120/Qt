#include "messageitem.h"
#include "ui_messageitem.h"

MessageItem::MessageItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageItem)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground); //设置样式表
    this->setStyleSheet("QWidget{border:1px; background:white; border-radius:1px;}");
    this->setStyleSheet("QWidget{background:transparent; border-radius:8px;}"
                        "QWidget:hover{background:transparent;}");

}

MessageItem::~MessageItem()
{
    delete ui;
}

void MessageItem::setRed(bool flog)
{
   if(flog == true)
   {
      ui->labred->setPixmap(QPixmap(":/images/message/red.png"));
   }
   else {
      ui->labred->setPixmap(QPixmap(""));
   }
}

void MessageItem::setStringPic(QString url)
{
    QString str = "QWidget{border-image:url("+url+");}";
    ui->widPicturePer->setStyleSheet(str);
}

void MessageItem::setName(QString str)
{
    ui->labNameMess->setText(str);
    ui->labNameMess->setStyleSheet("QLabel#labNameMess{color:rgb(91,133,180);}");
}

void MessageItem::setTime(QString str)
{
    ui->labTimer->setText(str);
    ui->labTimer->setStyleSheet("QLabel#labTimer{color:rgb(217,217,217);}");
}

void MessageItem::setInformMessage(QString str)
{
    ui->labInform->setText(str);
    ui->labInform->setStyleSheet("QLabel#labNameMess{color:rgb(49,49,49);}");
}
