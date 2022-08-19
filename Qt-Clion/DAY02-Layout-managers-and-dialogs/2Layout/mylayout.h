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

    //��ֱ���ֹ�����
    QHBoxLayout *layout;
    //��ֱ���ֹ�����
//    QVBoxLayout *layout;
    //���񲼾ֹ�����
//    QGridLayout *layout;
};

#endif // MYLAYOUT_H
