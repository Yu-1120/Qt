#include "login.h"

#include <QApplication>
#include "mywidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;

    MyWidget mw;
    mw.resize(800,480);

    /*
    if(QDialog::Accepted==w.exec()){
        //登录成功，显示界面
        mw.show();
        return a.exec();
    }
    */

    if(100==w.exec()){
        //登录成功，显示界面
        mw.show();
        return a.exec();
    }

    return 0;
    //w.show();
    //return a.exec();
}
