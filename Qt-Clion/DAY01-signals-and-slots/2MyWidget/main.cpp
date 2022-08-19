#include "mywidget.h"

#include <QTextCodec>

#include <QApplication>

int main(int argc, char *argv[]) {
    QString::fromLocal8Bit("中文");
    QApplication a(argc, argv);
    MyWidget w;

    //设置大小
    w.resize(800, 480);
    //设置显示位置
    w.move(400, 200);
    //设置窗口标题
    w.setWindowTitle("英雄联盟");

    w.show();
    return a.exec();
}
