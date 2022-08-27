#ifndef MYCAMERA_H
#define MYCAMERA_H

#include <QWidget>
#include <QCamera>
#include <QCameraInfo>
#include <QVideoWidget>
#include <QCameraImageCapture>

QT_BEGIN_NAMESPACE
namespace Ui { class MyCamera; }
QT_END_NAMESPACE

class MyCamera : public QWidget
{
    Q_OBJECT

public:
    MyCamera(QWidget *parent = nullptr);
    ~MyCamera();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_capture_clicked();

private:
    Ui::MyCamera *ui;
    //摄像头对象
    QCamera *ca;
    QVideoWidget *vw;
    //截屏对象
    QCameraImageCapture *cap;
};
#endif // MYCAMERA_H
