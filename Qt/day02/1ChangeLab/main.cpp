#include "changelab.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChangeLab w;

    w.resize(800,480);

    w.show();
    return a.exec();
}
