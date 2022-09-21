#include "enterform.h"
#include "ui_enterform.h"
#include "sericaltest.h"

EnterForm::EnterForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterForm)
{
    ui->setupUi(this);
}

EnterForm::~EnterForm()
{
    delete ui;
}

//打开串口测试槽函数,窗体跳转
void EnterForm::on_btn_Serial_clicked()
{
SericalTest s;
s.exec();
}
