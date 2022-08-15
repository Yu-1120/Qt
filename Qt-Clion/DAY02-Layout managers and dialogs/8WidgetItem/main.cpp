#include "widgetitem.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WidgetItem w;
    w.show();
    return a.exec();
}
