#include "filedownloadthread.h"
#include <QDebug>

FileDownloadThread::FileDownloadThread(QObject *parent):QThread(parent)
{
    value = 0;
    flag = false;//默认不下载
}

void FileDownloadThread::run()
{
    //模拟文件下载
    while(1){
        //下载
        if(get_flag()&&value<100){
            msleep(100);//100ms模拟下载1%
            qDebug()<<"%1下载完成";
            value++;
            //发送下载进度改变信号
            emit updateDownload(value);
        }
        else if(get_flag()&&value==100){//下完
            value = 0;
            set_flag(false);
            qDebug()<<"%100下载完成";
            //发送下载完成信号
            emit DownloadReady();
        }
    }
}

//开始/停止下载
void FileDownloadThread::set_flag(bool fg)
{
    //加锁
    mutex.lock();

    flag = fg;

    //解锁
    mutex.unlock();
}

bool FileDownloadThread::get_flag()
{
    bool temp = false;

    //加锁
    mutex.lock();

    temp = flag;

    //解锁
    mutex.unlock();

    return temp;
}
