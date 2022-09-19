#include "gettime.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GetTime w;
    w.show();
    return a.exec();
}
