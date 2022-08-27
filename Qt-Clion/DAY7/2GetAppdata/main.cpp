#include "getappdata.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GetAppdata w;
    w.show();
    return a.exec();
}
