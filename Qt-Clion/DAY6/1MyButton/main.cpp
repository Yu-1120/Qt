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

//继承QApplication类
class MyApplication:public QApplication{
public:
    MyApplication(int argc,char *argv[]):QApplication(argc,argv)
    {

    }

    //重写notify
    virtual bool notify(QObject *reciever,QEvent *event)
    {
        //***捕获关心的事件****
        //鼠标点击按钮事件
        if(event->type()==QEvent::MouseButtonPress){
            qDebug()<<"4.1捕获到了QEvent::MouseButtonPress "<<reciever;
        }
//        else if(event->type()==QEvent::MouseMove){
//            qDebug()<<"4.2捕获到了QEvent::MouseMove";
//        }

        //调用父类的事件处理函数
        return QApplication::notify(reciever,event);
    }
};

//实现观察者类
class Obser:public QObject{
public:
    Obser(QObject *parent=nullptr):QObject(parent)
    {

    }
/*
事件过滤器可以对指定的而时间进行过滤(特殊处理)，处理完成之后可以选择继续交给下一层，也可以到此处理结束。

事件过滤器安装在某个对象上，处于notify和event之间。z
*/

    //注意：实际应用中事件处理的四层不会对其全部重写，而是根据实际情况选择合适位置重写事件处理的方法。
    //重写过滤器函数
    //Qt中可以使用notify来捕获所有的事件。观察哪个函数被触发实现函数
    virtual bool eventFilter(QObject *watched, QEvent *event)
    {
        if(event->type()==QEvent::MouseButtonPress){
            qDebug()<<"3.1捕获到了QEvent::MouseButtonPress";
            //事件处理完毕后，不再往下传递
            return true;//返回真,过滤掉
            //继续往下传递
//            return false;
        }
        /*
        else if(event->type()==QEvent::MouseMove){
            qDebug()<<"3.2捕获到了QEvent::MouseMove";
        }*/

        //调用父类的事件处理函数
        return QObject::eventFilter(watched,event);
    }
};

int main(int argc, char *argv[])
{
    MyApplication a(argc, argv);

    MyButton btn("点我");
    btn.resize(100,50);

    //构造观察者
    Obser ob;
    //安装过滤器
    btn.installEventFilter(&ob);

    btn.show();

    //连接信号和槽
    QObject::connect(&btn,&MyButton::clicked,&btn,[&](){  //把重写函数注释就会触发
        //qDebug()<<"按钮点击信号";
    });

    //手动发送事件
    //QEvent *e = new QMouseEvent(QEvent::MouseButtonPress,QPointF(1,1),QPointF(1,1),QPointF(1,1),Qt::NoButton,Qt::NoButton,Qt::NoModifier);
    //QCoreApplication::postEvent(&btn,e);

    return a.exec();
}
