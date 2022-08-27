#include "mytimer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyTimer w;
    w.show();
    return a.exec();
}
