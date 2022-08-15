#include "widgetdesigner.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WidgetDesigner w;
    w.show();
    return a.exec();
}
