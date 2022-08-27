#include "myserial.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MySerial w;
    w.show();
    return a.exec();
}
