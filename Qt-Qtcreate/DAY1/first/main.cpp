#include <QApplication>//Qt界面事件循环类
#include <QWidget>//标准窗口类
#include <QLabel>//标签类

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);

    //具体操作
    //创建一个标准窗口对象
    QWidget w;
    //创建一个标签,以w作为父对象 ----- 显示到w上
    QLabel lab(&w);
    //设置lab显示的文字
    lab.setText("欢迎你来!");

    //显示窗口
    w.show();

    return app.exec();
}
