#include "mytext.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyText w;
    w.show();


    return a.exec();
}
