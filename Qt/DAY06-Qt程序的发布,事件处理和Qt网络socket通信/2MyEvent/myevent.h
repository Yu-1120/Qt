#ifndef MYEVENT_H
#define MYEVENT_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MyEvent; }
QT_END_NAMESPACE

class MyEvent : public QWidget
{
    Q_OBJECT

public:
    MyEvent(QWidget *parent = nullptr);
    ~MyEvent();
    //重写窗口的过滤器处理函数
    virtual bool eventFilter(QObject *watched,QEvent *e);

private:
    Ui::MyEvent *ui;
};
#endif // MYEVENT_H
