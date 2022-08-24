#include "mythreadcamera.h"
#include "ui_mythreadcamera.h"

MyThreadCamera::MyThreadCamera(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyThreadCamera)
{
    ui->setupUi(this);

    count = 0;
    thread = new CameraThread(this);
    //连接信号和槽
    QObject::connect(this,&MyThreadCamera::send_flag,thread,&CameraThread::set_flag);
    QObject::connect(thread,&CameraThread::send_image,this,[&](QImage image){
        //显示
        QPixmap map = QPixmap::fromImage(image);
        map = map.scaled(ui->label->size());

        ui->label->setPixmap(map);

        if(count==50){
            count = 0;
            //识别.....
        }

        count++;
    });
}

MyThreadCamera::~MyThreadCamera()
{
    delete ui;
}


void MyThreadCamera::on_pushButton_start_clicked()
{
    thread->start();
}

void MyThreadCamera::on_pushButton_stop_clicked()
{
    //thread->terminate();
    emit send_flag();
}
