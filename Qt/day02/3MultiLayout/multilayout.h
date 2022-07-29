#ifndef MULTILAYOUT_H
#define MULTILAYOUT_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>


class MultiLayout : public QWidget
{
    Q_OBJECT

public:
    MultiLayout(QWidget *parent = nullptr);
    ~MultiLayout();

private:
    QLabel *lab1;
    QLabel *lab2;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *AA;
    QPushButton *BB;
    QPushButton *CC;

    //水平布局管理器
    QHBoxLayout *hlayout1;
    QHBoxLayout *hlayout2;
    QHBoxLayout *hlayout3;
    //垂直布局管理器
    QVBoxLayout *layout;
};
#endif // MULTILAYOUT_H
