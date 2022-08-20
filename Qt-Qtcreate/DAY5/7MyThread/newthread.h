#ifndef NEWTHREAD_H
#define NEWTHREAD_H

#include <QThread>

class NewThread : public QThread
{
    Q_OBJECT
public:
    NewThread(QObject *parent=nullptr);
    //重写线程函数
    void run();

private:
    int count;
};

#endif // NEWTHREAD_H
