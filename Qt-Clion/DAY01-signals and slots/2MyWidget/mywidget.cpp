#include "mywidget.h"
#include <QFont>
#include <QPalette>
#include <QColor>
#include <QCursor>


MyWidget::MyWidget(QWidget *parent)
        : QWidget(parent) {
    QString::fromLocal8Bit("����");
    //��ʼ�����ڲ�����Ա
    lab1 = new QLabel(this);//this�Ǹ�����
    lab2 = new QLabel(this);

    //��������
//    lab2->setText("һ��Ҳ����Ц"); ����д������

    lab1->setText(QString::fromLocal8Bit("�������"));
    lab2->setText(QString::fromLocal8Bit("һ��Ҳ����Ц"));

    //�ƶ�λ��
    lab1->move(400, 240);
    //lab1->resize(100,20);�ֵĴ�С��ֽ�޹�

    //����lab1������ 32 X 32
    QFont f("Times", 16, 16, true/*б��*/);
    lab1->setFont(f);

    //����lab1�������ɫ
    QColor c(255, 0, 0);//���
    QPalette p;//��ɫ�壬�ܶ���ɫ�����԰����Ҫ������ɫ�ࣩ
    p.setColor(QPalette::WindowText/*�����ı���ɫ*/, c);
    lab1->setPalette(p);//���õ�ɫ��

    //���������״
    //QCursor cs(Qt::CrossCursor/*׼��*/);
    QCursor cs(Qt::PointingHandCursor/*С��*/);
    lab1->setCursor(cs);
}

MyWidget::~MyWidget() {
}

