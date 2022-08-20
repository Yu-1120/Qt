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

    return QWidget::eventFilter(watched,e);
}

