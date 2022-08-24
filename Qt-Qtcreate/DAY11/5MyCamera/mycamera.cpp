#include "mycamera.h"
#include "ui_mycamera.h"

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

}
