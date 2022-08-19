#include "mycalculate.h"
#include "calculate.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyCalculate w;

    Calculate cal;

    if(QDialog::Accepted==w.exec()){
        //登录成功，显示界面
        cal.show();
        return a.exec();
    }


    return 0;
}
