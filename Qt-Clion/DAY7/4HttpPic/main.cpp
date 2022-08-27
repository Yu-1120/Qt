#include "httppic.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HttpPic w;
    w.show();
    return a.exec();
}
