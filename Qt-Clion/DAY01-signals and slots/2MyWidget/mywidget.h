#ifndef MYWIDGET_H
#define MYWIDGET_H


#include <QWidget>
#include <QLabel>

class MyWidget : public QWidget {
Q_OBJECT //信号和槽要写这个

public:
    MyWidget(QWidget *parent = nullptr);

    ~MyWidget();

private:
    QLabel *lab1;
    QLabel *lab2;
};

#endif // MYWIDGET_H
