#include "myprocess.h"
#include "ui_myprocess.h"

MyProcess::MyProcess(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyProcess)
{
    ui->setupUi(this);

    pro = new QProcess(this);
    //pro = new QProcess;
}

MyProcess::~MyProcess()
{
    delete ui;
}

//开始
void MyProcess::on_pushButton_start_clicked()
{
    //如果进程未运行,启动
    if(pro->state()==QProcess::NotRunning){
        QString cmd = QString("\"C:/Program Files (x86)/Tencent/QQ/Bin/QQ.exe\"");
        pro->start(cmd);
    }
}

//停止
void MyProcess::on_pushButton_stop_clicked()
{
    pro->kill();
    //等待结束
    pro->waitForFinished();
}
