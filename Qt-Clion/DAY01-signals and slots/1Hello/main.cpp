#include <QApplication>
#include <QtWidgets>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    //具体操作
    QWidget w;

//   QLabel lab(&w);  //作为一个父对象传入
//   lab.setText("Hello,欢迎点击");
//   -----------
    QLabel *lab = new QLabel(&w);
    lab->setText("Hello");//大小会被锁定
//为什么这里不用释放掉delate
//because
//Qt中几乎所有的类都直接/间接继承自QObject，
//QObject继承产生的子类对象的内存都可以交给父类对象来释放
//  ------------
    w.show();
    return app.exec();
}
