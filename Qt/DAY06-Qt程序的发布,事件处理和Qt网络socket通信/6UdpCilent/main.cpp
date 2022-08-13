#include "udpcilent.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UdpCilent w;
    w.show();
    return a.exec();
}
