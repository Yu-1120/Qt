#ifndef MYVIDEOWIDGET_H
#define MYVIDEOWIDGET_H

#include <QVideoWidget>

class MyVideoWidget : public QVideoWidget
{
    Q_OBJECT
public:
    MyVideoWidget(QWidget *parent=nullptr);
    //重写按键事件处理函数
    virtual void keyPressEvent(QKeyEvent *event);

private:
    QWidget *p;//记录父对象
};

#endif // MYVIDEOWIDGET_H
