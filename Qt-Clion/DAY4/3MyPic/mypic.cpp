#include "mypic.h"
#include "ui_mypic.h"
#include <QPixmap>

MyPic::MyPic(QWidget *parent)
        : QWidget(parent), ui(new Ui::MyPic) {
    ui->setupUi(this);
}

MyPic::~MyPic() {
    delete ui;
}


void MyPic::on_pushButton_clicked() {
    //图片路径构造QPixmap对象
    //QPixmap map("D:\\GZFX2108\\01-Qt\\day04\\testimgp.jpg");
    //QPixmap map("D:\\GZFX2108\\01-Qt\\day04\\test.png");

    //使用资源图片文件来构造QPixmap
    //QPixmap map(":/testimgp.jpg");
    QPixmap map(":/me.jpg");

    //图片缩放至lab大小
    map = map.scaled(ui->label->size());//拉伸到lab的大小--Stretch to the size of the lab

    //使用label显示图像
    //-----------------------------------
    ui->label->setPixmap(map);
    //-----------------------------------
}
