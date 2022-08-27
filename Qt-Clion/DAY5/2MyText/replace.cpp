#include "replace.h"
#include "ui_replace.h"

Replace::Replace(QString s,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Replace)
{
    ui->setupUi(this);

    //将传递过来的字符串显示到lineEdit
    ui->lineEdit_find->setText(s);
    //如果字符串为空，禁止查找按钮
    if(s.isEmpty()){
        ui->pushButton_find->setEnabled(false);
    }
}

Replace::~Replace()
{
    delete ui;
}


//替换
void Replace::on_pushButton_find_clicked()
{
    //取出查找的字符串
    QString src_str = ui->lineEdit_find->text();
    QString dest_str = ui->lineEdit_replace->text();

    if(ui->checkBox->isChecked()){//区分大小写 true
        if(ui->radioButton_down->isChecked()){//向下 true
            emit replace_str(src_str,dest_str,true,true);
        }
        else{
            emit replace_str(src_str,dest_str,true,false);
        }
    }
    else{//不区分大小写
        if(ui->radioButton_down->isChecked()){//向下 true
            emit replace_str(src_str,dest_str,false,true);
        }
        else{
            emit replace_str(src_str,dest_str,false,false);
        }
    }
}

void Replace::on_pushButton_cancel_clicked()
{
    this->done(0);
}

void Replace::on_lineEdit_find_textEdited(const QString &arg1)
{
    if(arg1.isEmpty()){
        ui->pushButton_find->setEnabled(false);
    }
    else{
        ui->pushButton_find->setEnabled(true);
    }
}
