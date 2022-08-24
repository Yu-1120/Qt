#ifndef MYTHREADCAMERA_H
#define MYTHREADCAMERA_H

#include <QWidget>
#include "camerathread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyThreadCamera; }
QT_END_NAMESPACE

class MyThreadCamera : public QWidget
{
    Q_OBJECT

public:
    MyThreadCamera(QWidget *parent = nullptr);
    ~MyThreadCamera();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

signals:
    void send_flag();

private:
    Ui::MyThreadCamera *ui;
    //摄像头线程对象
    CameraThread *thread;
    quint64 count;
};
#endif // MYTHREADCAMERA_H
