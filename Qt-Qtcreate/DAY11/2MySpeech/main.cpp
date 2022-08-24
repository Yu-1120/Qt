#include "myspeech.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MySpeech w;
    w.show();
    return a.exec();
}
