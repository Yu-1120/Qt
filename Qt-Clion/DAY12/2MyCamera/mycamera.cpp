#include "mycamera.h"
#include "ui_mycamera.h"
#include <QDebug>

MyCamera::MyCamera(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyCamera)
{
    ui->setupUi(this);

    //获取系统可用的摄像头
    QList<QCameraInfo> infos = QCameraInfo::availableCameras();
    //显示到下拉列表框
    foreach(QCameraInfo info,infos){
        ui->comboBox->addItem(info.deviceName());
    }
}

MyCamera::~MyCamera()
{
    delete ui;
}

//采集
void MyCamera::on_pushButton_start_clicked()
{
    //构造摄像头对象
    ca = new QCamera(ui->comboBox->currentText().toUtf8(),this);
    //构造截屏对象
    cap = new QCameraImageCapture(ca,this);

    //连接截屏完成的信号
    QObject::connect(cap,&QCameraImageCapture::imageCaptured,this,[&](int id,const QImage &preview){
        qDebug()<<id;

        QPixmap map = QPixmap::fromImage(preview);

        //保存图片
        QString picpath = QString("D:\\GZFX2108\\02-QtSenior\\day05\\%1.jpg").arg(id);
        map.save(picpath);

        //显示
        map = map.scaled(ui->label_cap->size());
        ui->label_cap->setPixmap(map);
    });

    //构造显示窗口
    vw = new QVideoWidget(ui->widget);
    //调整大小移植
    vw->resize(ui->widget->size());

    //设置摄像头的显示窗口
    ca->setViewfinder(vw);
    vw->show();

    //启动采集
    ca->start();

    ui->pushButton_start->setEnabled(false);
    ui->pushButton_stop->setEnabled(true);
    ui->pushButton_capture->setEnabled(true);
}

//停止
void MyCamera::on_pushButton_stop_clicked()
{
    //停止采集
    ca->stop();
    //隐藏窗口
    vw->hide();

    delete ca;
    delete vw;

    ui->pushButton_start->setEnabled(true);
    ui->pushButton_stop->setEnabled(false);
    ui->pushButton_capture->setEnabled(false);
}

//截屏
void MyCamera::on_pushButton_capture_clicked()
{
    cap->capture();
    //cap->capture("D:\\GZFX2108\\02-QtSenior\\day05\\1.jpg");
    //不能在此显示图片，此时截屏还没有完成
}
