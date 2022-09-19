#include "mytimer.h"
#include "ui_mytimer.h"
#include <QDebug>
#include <QDateTime>

MyTimer::MyTimer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyTimer)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    //连接定时器超时的信号和槽
    QObject::connect(timer,&QTimer::timeout,this,[&](){
        //刷新显示当前日期时间
        QDateTime t = QDateTime::currentDateTime();
        ui->label->setText(t.toString("yyyy-MM-dd hh:mm:ss.zzz"));
    });
}

MyTimer::~MyTimer()
{
    delete ui;
}


void MyTimer::on_pushButton_start_clicked()
{
    //启动定时器
    //timer_id = startTimer(1000);//1s刷新一次
    timer->start(100);//100ms刷新一次 //定时器对象
}

void MyTimer::on_pushButton_stop_clicked()
{
    //关闭定时器
    //killTimer(timer_id);
    timer->stop();//  //定时器对象
}

//重写定时器超时处理函数
void MyTimer::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==timer_id){//这里为什么还是timer_id
        qDebug()<<"定时器时间到";
        //刷新显示当前日期时间
        QDateTime t = QDateTime::currentDateTime();
        ui->label->setText(t.toString("yyyy-MM-dd hh:mm:ss"));
    }
}
