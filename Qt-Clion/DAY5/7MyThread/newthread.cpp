#include "newthread.h"
#include <QDebug>

NewThread::NewThread(QObject *parent):QThread(parent)
{
    count = 0;
}

//线程函数
void NewThread::run()
{
    qDebug()<<"线程启动成功!";

    while(1){
        qDebug()<<"线程正在运行!cout="<<count++;
        sleep(1);
    }
}
