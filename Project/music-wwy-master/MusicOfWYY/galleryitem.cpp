#include "galleryitem.h"
#include "ui_galleryitem.h"
#include <QPalette>
GalleryItem::GalleryItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GalleryItem)
{
    ui->setupUi(this);
    //去掉滑动条

    setAttribute(Qt::WA_StyledBackground); //设置样式表
    //设置样式
    this->setStyleSheet("QWidget#GalleryItem{border:0px; background:white; border-radius:5px;}");
//    ui->itemPic->setStyleSheet("QWidget#itemPic{border:1px; background:white; border-radius:5px;}");
    ui->textEdit->setStyleSheet("QTextEdit{border:0px; background:white;}"
                                "QTextEdit{color:rgb(55,55,55)}");

    ui->itemPic->setAutoFillBackground(true); //用调色板需要用到
    ui->textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

GalleryItem::~GalleryItem()
{
    delete ui;
}

void GalleryItem::setMessage(QString str)
{
    ui->textEdit->setText(str);
}

void GalleryItem::setPicture(QString url)
{
      QPalette pal = ui->itemPic->palette();
      pal.setBrush(QPalette::Background,QBrush(QPixmap(url)));
      ui->itemPic->setPalette(pal);
}
