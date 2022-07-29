#ifndef CHANGELAB_H
#define CHANGELAB_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class ChangeLab : public QWidget
{
    Q_OBJECT

public:
    ChangeLab(QWidget *parent = nullptr);
    ~ChangeLab();

private:
    QLabel *lab;
    QPushButton *red_btn;
    QPushButton *green_btn;
};
#endif // CHANGELAB_H
