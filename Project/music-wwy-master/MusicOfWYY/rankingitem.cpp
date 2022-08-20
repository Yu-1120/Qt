#include "rankingitem.h"
#include "ui_rankingitem.h"
#include <QString>
RankingItem::RankingItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RankingItem)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    ui->labNum->setStyleSheet("QLabel{color:rgb(255,61,61);background:transparent;}");
    ui->labCon->setStyleSheet("QLabel{color:rgb(54,54,54);background:transparent;}");
    //152,152,152
    ui->labEnd->setStyleSheet("QLabel{color:rgb(152,152,152);background:transparent;}");
    this->setStyleSheet("QWidget{background:transparent; border-radius:8px;}"
                        "QWidget:hover{background:transparent;}");

}

RankingItem::~RankingItem()
{
    delete ui;
}

void RankingItem::setNum(int num, bool b)
{
    ui->labNum->setText(QString::number(num));
    if(b == true)
    {
        ui->labNum->setStyleSheet("QLabel{color:rgb(255,61,61);background:transparent;}");
    }
    else {
        ui->labNum->setStyleSheet("QLabel{color:rgb(222,222,222;background:transparent;)}");
    }
}

void RankingItem::setStringOrPic(QString str)
{
    ui->labPicOrText->setText(str);
    ui->labPicOrText->setStyleSheet("QLabel{color:rgb(152,152,152);background:transparent;}");
}

void RankingItem::setStringOrPic(int num)
{
    // 0 加载上  1加载下 2加载-， 其它不处理
    ui->labPicOrText->setMinimumSize(8,4);
    ui->labPicOrText->setMaximumSize(8,8);
    if(num == 0)
    {
         ui->labPicOrText->setStyleSheet("QLabel{border-image:url(./images/ranking/up.png);}");
    }
    else if(num == 1)
    {
         ui->labPicOrText->setStyleSheet("QLabel{border-image:url(./images/ranking/down.png);}");
    }
    else if (num == 2) {
          ui->labPicOrText->setStyleSheet("QLabel{border-image:url(./images/ranking/nor.png);}");
    }
    else {
        //什么都补处理
    }

}

void RankingItem::setMusicName(QString strName)
{
    ui->labCon->setText(strName);
}

void RankingItem::setMusicAutor(QString name)
{
   ui->labEnd->setText(name);
}
