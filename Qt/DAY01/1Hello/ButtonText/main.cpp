#include "ButtonText.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ButtonText w;

    //设置大小
    w.resize(1024,768);

    w.show();
    return a.exec();
}
