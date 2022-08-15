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
    //ָ�뷽�����
    bool flag1 = true;
    bool flag2 = true;
    bool flag3 = true;
    //�ۺ���
private slots:

    //��ʽҪ���ź���ȫһ��
    void btn_clicked();
};

#endif // CHANGELAB_H
