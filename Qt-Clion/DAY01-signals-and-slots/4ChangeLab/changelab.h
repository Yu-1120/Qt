#ifndef CHANGELAB_H
#define CHANGELAB_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class ChangeLab : public QWidget {
Q_OBJECT

public:
    ChangeLab(QWidget *parent = nullptr);

    ~ChangeLab();

private:
    QLabel *lab;
    QPushButton *red_btn;
    QPushButton *green_btn;
    QPushButton *blue_btn;
    //指针方便管理
    bool flag1 = true;
    bool flag2 = true;
    bool flag3 = true;
    //槽函数
private slots:

    //格式要和信号完全一致
    void btn_clicked();
};

#endif // CHANGELAB_H
