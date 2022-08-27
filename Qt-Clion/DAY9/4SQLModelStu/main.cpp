#include "sqlmodelstu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SQLModelStu w;
    w.show();
    return a.exec();
}
