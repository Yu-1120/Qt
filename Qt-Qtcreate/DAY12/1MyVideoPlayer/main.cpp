#include "myvideoplayer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyVideoPlayer w;
    w.show();
    return a.exec();
}
