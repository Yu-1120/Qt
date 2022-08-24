#include "sqlstu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SQLStu w;
    w.show();
    return a.exec();
}
