#include "showpic.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShowPic w;
    w.show();
    return a.exec();
}
