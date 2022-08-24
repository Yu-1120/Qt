#include "mymplayer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMplayer w;
    w.show();
    return a.exec();
}
