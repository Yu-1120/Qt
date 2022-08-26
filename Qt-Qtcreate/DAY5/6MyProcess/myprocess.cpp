#include "myprocess.h"
#include "ui_myprocess.h"

MyProcess::MyProcess(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyProcess)
{
    ui->setupUi(this);

    pro = new QProcess(this);
    //pro = new QProcess;
   //newthread = new NewThread(this);
}

MyProcess::~MyProcess()
{
    delete ui;
}

//开始
void MyProcess::on_pushButton_start_clicked()
{
    //**************************************进程
    //如果进程未运行,启动
    if(pro->state()==QProcess::NotRunning){
        QString cmd = QString("\"D:/QQ/Bin/QQ.exe\"");//这是我电脑的qq启动程序
        pro->start(cmd);//win下进程调用的命令行也不一样
       //launger是调用启动进程的进程，调用后把自己销毁了
    }
    //**************************************
}

//停止
void MyProcess::on_pushButton_stop_clicked()
{
    pro->kill();
    //等待结束
    pro->waitForFinished();
}

