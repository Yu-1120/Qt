#include "find.h"
#include "ui_find.h"

Find::Find(QString s,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Find)
{
    ui->setupUi(this);

    //将传递过来的字符串显示到lineEdit
    ui->lineEdit->setText(s);
    //如果字符串为空，禁止查找按钮
    if(s.isEmpty()){
        ui->pushButton_find->setEnabled(false);
    }
}

Find::~Find()
{
    delete ui;
}

//查找
void Find::on_pushButton_find_clicked()
{
    //取出查找的字符串
    QString str = ui->lineEdit->text();

    if(ui->checkBox->isChecked()){//区分大小写 true
        if(ui->radioButton_down->isChecked()){//向下 true
            emit find_str(str,true,true);
        }
        else{
            emit find_str(str,true,false);
        }
    }
    else{//不区分大小写
        if(ui->radioButton_down->isChecked()){//向下 true
            emit find_str(str,false,true);
        }
        else{
            emit find_str(str,false,false);
        }
    }
}

void Find::on_pushButton_cancel_clicked()
{
    this->done(0);
}

//发生了编辑动作
void Find::on_lineEdit_textEdited(const QString &arg1)
{
    if(arg1.isEmpty()){
        ui->pushButton_find->setEnabled(false);
    }
    else{
        ui->pushButton_find->setEnabled(true);
    }
}
