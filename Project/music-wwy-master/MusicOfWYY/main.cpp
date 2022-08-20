#include "allmain.h"
#include "loadfileqss.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoadFileQss::setStyle("./Allthe.qss"); //加载qss 样式表，用静态方式
    AllMain w;
    w.show();

    return a.exec();
}
