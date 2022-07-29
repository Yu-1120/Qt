#include "mypic.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyPic w;
    w.show();
    return a.exec();
}
