#include "showpic.h"
#include "ui_showpic.h"
#include <QFileDialog>

ShowPic::ShowPic(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ShowPic)
{
    ui->setupUi(this);
}

ShowPic::~ShowPic()
{
    delete ui;
}


void ShowPic::on_pushButton_clicked()
{
//    QString picpath = QFileDialog::getOpenFileName(this,"添加图片","D:/GZFX2108/01-Qt/day04","*.bmp *.png *.jpg");
    QString picpath = QFileDialog::getOpenFileName(this,"添加图片","E:/","*.bmp *.png *.jpg");
     //路径不存在会为空
    ui->comboBox->addItem(picpath);//路径显示到lab上去
}

void ShowPic::on_comboBox_currentTextChanged(const QString &arg1)
{
    //显示图片
    QPixmap pix(arg1);

    pix = pix.scaled(ui->label->size());
    ui->label->setPixmap(pix);
}
