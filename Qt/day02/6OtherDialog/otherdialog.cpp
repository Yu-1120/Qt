#include "otherdialog.h"
#include <QFileDialog>//文件对话框
#include <QDebug>
#include <QInputDialog>//输入对话框
#include <QColorDialog>//颜色对话框
#include <QFontDialog>//字体对话框

OtherDialog::OtherDialog(QWidget *parent)
    : QWidget(parent)
{
    lab = new QLabel("晨光",this);
    btn = new QPushButton("点我",this);

    lab->move(380,200);
    btn->move(380,300);

    lab->resize(200,50);

    QObject::connect(btn,&QPushButton::clicked,this,[&](){
        //打开文件对话框
        //QString open_path = QFileDialog::getOpenFileName(this,"打开文件","D:/GZFX2108/01-Qt","*.cpp");
        //保存文件对话框
        //QString save_path = QFileDialog::getSaveFileName(this,"保存文件","D:/GZFX2108/01-Qt","*.h");
        //获取已存在目录路径
        //QString Der_path = QFileDialog::getExistingDirectory(this,"目录","D:/GZFX2108/01-Qt");
        //qDebug()<<Der_path;

        //QString str = QInputDialog::getText(this,"说明信息","请输入你的简介");
        //int num = QInputDialog::getInt(this,"说明信息","请输入你的身高",170);
        //double num = QInputDialog::getDouble(this,"说明信息","请输入你的身高");
        //qDebug()<<str;
        //lab->setText(str);
        //lab->setNum(num);

        //QColor c = QColorDialog::getColor(Qt::black,this,"选择字体颜色");
        //QPalette p;
        //p.setColor(QPalette::WindowText,c);
        //lab->setPalette(p);

        bool flag = true;
        QFont f = QFontDialog::getFont(&flag,this);
        lab->setFont(f);
    });
}

OtherDialog::~OtherDialog()
{
}

