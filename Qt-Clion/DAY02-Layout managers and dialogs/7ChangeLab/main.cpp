#include "changelab.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChangeLab w;
    w.show();
    return a.exec();
}
