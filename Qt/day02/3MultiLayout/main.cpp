#include "multilayout.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MultiLayout w;
    w.show();
    return a.exec();
}
