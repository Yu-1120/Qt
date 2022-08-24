#include "studb.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StuDB w;
    w.show();
    return a.exec();
}
