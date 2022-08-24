#include "sqllogin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SQLLogin w;
    w.show();
    return a.exec();
}
