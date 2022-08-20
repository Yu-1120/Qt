#ifndef FILEDOWNLOADTHREAD_H
#define FILEDOWNLOADTHREAD_H

#include <QThread>
#include <QMutex>

class FileDownloadThread : public QThread
{
    Q_OBJECT
public:
    FileDownloadThread(QObject *parent=nullptr);
    void run();

private:
    //下载进度
    int value;
    bool flag;//1-下载 0-不下载
    QMutex mutex;//互斥锁

    bool get_flag();

signals:
    //下载进度改变信号
    void updateDownload(int val);
    //下载完成信号
    void DownloadReady();

public slots:
    //开始/停止下载
    void set_flag(bool fg);
};

#endif // FILEDOWNLOADTHREAD_H
