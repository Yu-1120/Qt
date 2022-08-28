#include "newthread.h"
#include <QDebug>
NewThread::NewThread()
{

}
void NewThread::run(){//线程是用于一直在做一个工作
    while (1) {
        qDebug()<<"start";
        sleep(1);
    }


}
