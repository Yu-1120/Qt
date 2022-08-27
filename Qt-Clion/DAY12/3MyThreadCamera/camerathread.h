#ifndef CAMERATHREAD_H
#define CAMERATHREAD_H

//摄像头采集线程
#include <QThread>
#include <QImage>

typedef struct{
    char *start;
    size_t length;
}buffer_t;

class CameraThread : public QThread
{
    Q_OBJECT
public:
    explicit CameraThread(QObject *parent=nullptr);
    ~CameraThread();
    //重写线程函数
    void run();

private:
    buffer_t buffer[4];
    buffer_t current;//保存当前取出的一帧
    int fd;
    unsigned int sign3;
    bool flag;

    int yuyv2rgb(int y, int u, int v);
    int yuyv2rgb0(unsigned char *yuv, unsigned char *rgb, unsigned int width, unsigned int height);
    //初始化
    void camera_init();
    //释放
    void camera_free();

signals:
    void send_image(QImage image);

public slots:
    void set_flag();
};

#endif // CAMERATHREAD_H
