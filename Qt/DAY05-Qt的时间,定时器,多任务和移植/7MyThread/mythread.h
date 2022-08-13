#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QWidget>
#include "newthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyThread; }
QT_END_NAMESPACE

class MyThread : public QWidget
{
    Q_OBJECT

public:
    MyThread(QWidget *parent = nullptr);
    ~MyThread();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

private:
    Ui::MyThread *ui;
    //线程对象
    NewThread *thread;
};
#endif // MYTHREAD_H
