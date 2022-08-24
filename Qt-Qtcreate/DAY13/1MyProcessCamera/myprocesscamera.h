#ifndef MYPROCESSCAMERA_H
#define MYPROCESSCAMERA_H

#include <QWidget>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class MyProcessCamera; }
QT_END_NAMESPACE

class MyProcessCamera : public QWidget
{
    Q_OBJECT

public:
    MyProcessCamera(QWidget *parent = nullptr);
    ~MyProcessCamera();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

private:
    Ui::MyProcessCamera *ui;
    QProcess *p;
};
#endif // MYPROCESSCAMERA_H
