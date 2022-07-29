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
    QString picpath = QFileDialog::getOpenFileName(this,"添加图片","D:/GZFX2108/01-Qt/day04","*.bmp *.png *.jpg");

    ui->comboBox->addItem(picpath);
}

void ShowPic::on_comboBox_currentTextChanged(const QString &arg1)
{
    //显示图片
    QPixmap pix(arg1);

    pix = pix.scaled(ui->label->size());
    ui->label->setPixmap(pix);
}
