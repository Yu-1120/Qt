#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>

class MyPushButton : public QWidget
{
    Q_OBJECT

public:
    MyPushButton(QWidget *parent = nullptr);
    ~MyPushButton();

private:
    QPushButton *btn;

//�ź�
signals:
    void send_sig(int num);//����ʵ��

//�ۺ���
private slots:
    //��ʽҪ���ź���ȫһ��
    void btn_clicked();
};
#endif // MYPUSHBUTTON_H
