#include "mycamera.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyCamera w;
    w.show();
    return a.exec();
}
