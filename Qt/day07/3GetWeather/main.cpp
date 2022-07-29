#include "getweather.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GetWeather w;
    w.show();
    return a.exec();
}
