#ifndef MYLAYOUT_H
#define MYLAYOUT_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

class MyLayout : public QWidget {
Q_OBJECT

public:
    MyLayout(QWidget *parent = nullptr);

    ~MyLayout();

private:
    QLabel *lab1;
    QLabel *lab2;
    QPushButton *btn1;
    QPushButton *btn2;

    //垂直布局管理器
    QHBoxLayout *layout;
    //垂直布局管理器
//    QVBoxLayout *layout;
    //网格布局管理器
//    QGridLayout *layout;
};

#endif // MYLAYOUT_H
