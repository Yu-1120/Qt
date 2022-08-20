#include "newcourieritem.h"
#include "ui_newcourieritem.h"

NewCourierItem::NewCourierItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewCourierItem)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setStyleSheet("QWidget{background:transparent; border-radius:8px;}"
                        "QWidget:hover{background:transparent;}");


}

NewCourierItem::~NewCourierItem()
{
    delete ui;
}

void NewCourierItem::setNum(int id)
{
    ui->labMusicNum->setNum(id);
    ui->labMusicNum->setStyleSheet("QLabel#labMusicNum{color:rgb(195,195,219);}");

}

void NewCourierItem::setPicture(QString url)
{
   QString str = "QWidget{border-image:url("+url+");}";
   ui->widMusicPic->setStyleSheet(str);
}

void NewCourierItem::setMusicName(QString musicName)
{
    ui->MusicName->setText(musicName);
     ui->MusicName->setStyleSheet("QLabel#MusicName{color:rgb(54,54,54);}");

}

void NewCourierItem::setLogPic()
{
    ui->labMusicLog->setMaximumSize(27,17);

 //   ui->labMusicLog->setStyleSheet("QLable{border-image:url(:/images/NewMusic/sq2.png);}");
}

void NewCourierItem::setMusicAuthor(QString author)
{
    ui->MusicAuthor->setText(author);
    ui->MusicAuthor->setStyleSheet("QLabel#MusicAuthor{color:rgb(101,101,101);}");
}

void NewCourierItem::setMusicAlbum(QString name)
{
    ui->MusicAlbum->setText(name);
    ui->MusicAlbum->setStyleSheet("QLabel#MusicAlbum{color:rgb(101,101,101);}");
}

void NewCourierItem::setMusicTimer(QString strTimer)
{
    ui->MusicTimer->setText(strTimer);
    ui->MusicTimer->setStyleSheet("QLabel#MusicTimer{color:rgb(155,155,202);}");
}
