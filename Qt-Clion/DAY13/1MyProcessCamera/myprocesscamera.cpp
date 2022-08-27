#include "myprocesscamera.h"
#include "ui_myprocesscamera.h"

MyProcessCamera::MyProcessCamera(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyProcessCamera)
{
    ui->setupUi(this);

    p = new QProcess(this);
}

MyProcessCamera::~MyProcessCamera()
{
    if(p->state()==QProcess::Running){
        p->kill();
        p->waitForFinished();
    }

    delete ui;
}

//开始
void MyProcessCamera::on_pushButton_start_clicked()
{
    if(p->state()==QProcess::NotRunning){
        p->start("./camera_test");
    }
}

//停止
void MyProcessCamera::on_pushButton_stop_clicked()
{
    if(p->state()==QProcess::Running){
        p->kill();
        p->waitForFinished();

        ui->label->clear();
    }
}
