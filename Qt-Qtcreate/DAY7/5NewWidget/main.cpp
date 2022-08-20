#include "newwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NewWidget w;
    w.show();
    return a.exec();
}
