#include <QApplication>
#include <QPushButton>
#include <QDebug>
#include <QMouseEvent>

class MyButton:public QPushButton{
public:
    MyButton(const QString &text,QWidget *parent=nullptr):QPushButton(text,parent)
    {

    }

    //1.重写特定事件(鼠标点击)的事件处理函数

    virtual void mousePressEvent(QMouseEvent *event)//要加上虚函数
    {
        qDebug()<<"1.1捕获到了mousePressEvent "<<this;
        //如果要保留父类的事件默认处理方式，可以调用父类对应的虚函数
        return QPushButton::mousePressEvent(event);
    }


};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyButton btn("点我");
    btn.resize(100,50);

    //构造观察者


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
