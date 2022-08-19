#include "mypushbutton.h"
#include <QDebug>

MyPushButton::MyPushButton(QWidget *parent)
        : QWidget(parent) {
    btn = new QPushButton(this);
//    btn->setText("����");
    btn->setText(QString::fromLocal8Bit("����"));

    btn->move(400, 400);

    //�����źźͲ�
    //QObject::connect(btn,SIGNAL(clicked()),this,SLOT(btn_clicked()));
//    QObject::connect(btn,&QPushButton::clicked,this,&MyPushButton::btn_clicked);
    //(�����źţ����ն���ĺ������ۺ�����)
    QObject::connect(btn, &QPushButton::clicked, this, [&]() {  //�ۺ���������������д��

        qDebug() << "Lambda���ʽslot0---";
    });

    //���뷢���ź�
    emit send_sig(100);

    //�����źź��ź�  �Լ������Լ�
    QObject::connect(this, SIGNAL(send_sig(int)), btn, SIGNAL(clicked()));
//    QObject::connect(this,&MyPushButton::send_sig,this,[&](int n){
//        qDebug()<<"num="<<n;
//    });


}

MyPushButton::~MyPushButton() {
}

//�ۺ�����ʵ��
void MyPushButton::btn_clicked() {
    //qDebug��Qt�ĵ��������������printf��coutһ��ʹ��
    //qt���cout
    qDebug() << "btn_clicked";
}

