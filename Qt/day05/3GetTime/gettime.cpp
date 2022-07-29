#include "gettime.h"
#include "ui_gettime.h"
#include <QTime>

GetTime::GetTime(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GetTime)
{
    ui->setupUi(this);

}

GetTime::~GetTime()
{
    delete ui;
}


void GetTime::on_pushButton_clicked()
{
    //QTime t = QTime::currentTime();
    QDateTime t = QDateTime::currentDateTime();

    //ui->label->setText(t.toString("hh:mm:ss"));
    ui->label->setText(t.toString("yyyy-MM-dd hh:mm:ss"));
}


