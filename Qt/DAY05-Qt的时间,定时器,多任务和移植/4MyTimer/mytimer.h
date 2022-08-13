#ifndef MYTIMER_H
#define MYTIMER_H

#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MyTimer; }
QT_END_NAMESPACE

class MyTimer : public QWidget
{
    Q_OBJECT

public:
    MyTimer(QWidget *parent = nullptr);
    ~MyTimer();
    //重写定时器超时处理函数
    virtual void timerEvent(QTimerEvent *event);

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

private:
    Ui::MyTimer *ui;
    //定时器ID
    int timer_id;
    //定时器对象
    QTimer *timer;
};
#endif // MYTIMER_H
