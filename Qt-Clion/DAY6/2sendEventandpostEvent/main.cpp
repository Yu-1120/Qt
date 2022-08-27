#include <QApplication>
#include <QPushButton>
#include <QDebug>
#include <QMouseEvent>

class MyButton:public QPushButton{
public:
    MyButton(const QString &text,QWidget *parent=nullptr):QPushButton(text,parent)
    {

    }
/*
# 事件处理

事件属于Qt的基础通信机制，信号和槽也是通过事件机制来实现的，作用是用于实现Qt对象的通信和对各种动作的响应。

## 1.产生事件

既可以通过某个预定义类的对象产生，也可以通过代码触发。

*/
    //1.重写特定事件(鼠标点击)的事件处理函数

    virtual void mousePressEvent(QMouseEvent *event)//要加上虚函数
    {
        qDebug()<<"1.1捕获到了mousePressEvent "<<this;
        //如果要保留父类的事件默认处理方式，可以调用父类对应的虚函数
        return QPushButton::mousePressEvent(event);
    }

    virtual void mouseMoveEvent(QMouseEvent *event)//鼠标过去触发
    {
        qDebug()<<"1.2捕获到了mouseMoveEvent";
        //如果要保留父类的事件默认处理方式，可以调用父类对应的虚函数
        return QPushButton::mouseMoveEvent(event);
    }

    //2.重写所有事件的事件处理函数
    virtual bool event(QEvent *evt)//重写所有事件先执行这个
    {
        //鼠标点击按钮事件
        if(evt->type()==QEvent::MouseButtonPress){ //根据事件去调用去调用这个函数
            qDebug()<<"2.1捕获到了QEvent::MouseButtonPress";
        }
//        else if(evt->type()==QEvent::MouseMove){
//            qDebug()<<"2.2捕获到了QEvent::MouseMove";
//        }

        //调用父类的事件处理函数
        return QPushButton::event(evt);
    }
};

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);

    MyButton btn("点我");
    btn.resize(100,50);



    //连接信号和槽
    QObject::connect(&btn,&MyButton::clicked,&btn,[&](){  //把重写函数注释就会触发
        //qDebug()<<"按钮点击信号";
    });
  /*
Qt除了预定义的类类型对象能够发送预定义事件以外，也可以手动通过代码发送事件，手动通过代码发送的函数定义在QCoreApplication类中。
*/
    //手动发送事件-----这个鬼代码是啥意思，这么多参数
    QEvent *e = new QMouseEvent(QEvent::MouseButtonPress,QPointF(1,1),QPointF(1,1),QPointF(1,1),Qt::NoButton,Qt::NoButton,Qt::NoModifier);
    QCoreApplication::postEvent(&btn,e);
//    QCoreApplication::sendEvent(&btn,e);一个是事件发送，俩行效果是一样的

    return a.exec();
}
