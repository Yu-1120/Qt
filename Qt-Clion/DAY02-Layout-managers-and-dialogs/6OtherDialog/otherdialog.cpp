#include "otherdialog.h"
#include <QFileDialog>//文件对话框
#include <QDebug>
#include <QInputDialog>//输入对话框
#include <QColorDialog>//颜色对话框
#include <QFontDialog>//字体对话框

OtherDialog::OtherDialog(QWidget *parent)
        : QWidget(parent) {
    lab = new QLabel("Hello,世界", this);//要指明父对象，不然会内存揭露
    btn = new QPushButton("改字体", this);
    btn1 = new QPushButton("改颜色", this);
    btn2 = new QPushButton("改内容", this);

    lab->move(380, 200);
    btn->move(380, 300);
    btn1->move(380, 350);
    btn2->move(380, 400);

    lab->resize(200, 50);

    QObject::connect(btn, &QPushButton::clicked, this, [&]() {


        bool flag = true;
        QFont f = QFontDialog::getFont(&flag, this);
        lab->setFont(f);
    });
    QObject::connect(btn1, &QPushButton::clicked, this, [&]() {


        QColor c = QColorDialog::getColor(Qt::black, this, "选择字体颜色");
        QPalette p;
        p.setColor(QPalette::WindowText, c);
        lab->setPalette(p);


    });
    QObject::connect(btn2, &QPushButton::clicked, this, [&]() {
        QString str = QInputDialog::getText(this, "内容修改", "请输入你的内容");
        qDebug() << str;
        if (str == "") {
            str = "已经为空，请编辑";
            lab->setText(str);
        }
    });
}

OtherDialog::~OtherDialog() {
}

