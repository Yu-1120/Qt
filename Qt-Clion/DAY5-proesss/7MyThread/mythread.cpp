#include "mythread.h"
#include "ui_mythread.h"

MyThread::MyThread(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyThread)
{
    ui->setupUi(this);

    thread = new NewThread(this);
}

MyThread::~MyThread()
{
    thread->terminate();//这里要销毁，同下

    delete ui;
}

//开始
void MyThread::on_pushButton_start_clicked()
{
    thread->start();
}

//停止
void MyThread::on_pushButton_stop_clicked()
{
    thread->terminate();
}
