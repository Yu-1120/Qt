#include "calculate.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculate w;
    w.show();
    return a.exec();
}
