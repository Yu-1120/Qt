#include "mythreadcamera.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyThreadCamera w;
    w.show();
    return a.exec();
}
