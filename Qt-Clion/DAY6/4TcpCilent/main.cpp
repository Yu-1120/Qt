#include "tcpcilent.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TcpCilent w;
    w.show();
    return a.exec();
}
