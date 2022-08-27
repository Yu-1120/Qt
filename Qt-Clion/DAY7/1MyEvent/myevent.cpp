#include "myevent.h"
#include "ui_myevent.h"
#include <QDebug>
#include <QKeyEvent>

MyEvent::MyEvent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyEvent)
{
    ui->setupUi(this);
    //为按钮安装过滤器，以本窗口作为观察者
    ui->pushButton->installEventFilter(this);
}

MyEvent::~MyEvent()
{
    delete ui;
}
/*
重构:QWidget:: wheelEvent (QWheelEvent *事件)。

这个事件处理程序可以在子类中重新实现，以接收viewport()小部件的轮状事件。事件在e中传递
滚轮事件
。
*/
void MyEvent::wheelEvent(QWheelEvent *event)
{
    int delta = event->delta();
    QRect rct = ui->pushButton->geometry();
//**************************************************
    if(delta<0&&rct.width()>50&&rct.height()>25){//缩小
        rct.setWidth(rct.width()-6);//右下角要减少
        rct.setHeight(rct.height()-3);
        rct.setX(rct.x()+6);//左上角要增加
        rct.setY(rct.y()+3);
    }
    else if(delta>0&&rct.x()+rct.width()+6<=this->width()
                   &&rct.y()+rct.height()+3<=this->height()
                   &&rct.x()-6>=0
                   &&rct.y()-3>=0){
        rct.setWidth(rct.width()+6);
        rct.setHeight(rct.height()+3);
        rct.setX(rct.x()-6);
        rct.setY(rct.y()-3);
    }
//**************************************************
    //设置按钮的坐标和大小
    ui->pushButton->setGeometry(rct);
}

//按钮对象收到的所有事件都会先调用该函数
bool MyEvent::eventFilter(QObject *watched,QEvent *e)
{
    //处理按键事件
    if(e->type()==QEvent::KeyPress){
        //qDebug()<<"QEvent::KeyPress";

        //获取按键当前坐标
        int x = ui->pushButton->x();
        int y = ui->pushButton->y();

        //获取按键和窗口的宽度和高度
        int btn_width = ui->pushButton->width();
        int btn_height = ui->pushButton->height();
        int win_width = this->width();
        int win_height = this->height();
//**************************************************
        //恢复成按键事件的类型
        QKeyEvent *pkey = dynamic_cast<QKeyEvent *>(e);
        switch (pkey->key()) {
            case Qt::Key_Up:
                //qDebug()<<"Key_Up";
                if(y>0)
                    y--;
                break;
            case Qt::Key_Down:
                //qDebug()<<"Key_Down";
                if(y<win_height-btn_height)
                    y++;
                break;
            case Qt::Key_Right:
                //qDebug()<<"Key_Right";
                if(x<win_width-btn_width)
                    x++;
                break;
            case Qt::Key_Left:
                //qDebug()<<"Key_Left";
                if(x>0)
                    x--;
                break;
        }

        //移动按键
        ui->pushButton->move(x,y);
    }
//**************************************************
    return QWidget::eventFilter(watched,e);
}

