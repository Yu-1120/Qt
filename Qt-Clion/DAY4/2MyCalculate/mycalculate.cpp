#include "mycalculate.h"
#include "ui_mycalculate.h"
#include <QDebug>
#include <QMessageBox>

MyCalculate::MyCalculate(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyCalculate)
{
    ui->setupUi(this);
}

MyCalculate::~MyCalculate()
{
    delete ui;
}


void MyCalculate::on_pushButton_login_clicked()
{
    if(ui->lineEdit_username->text().isEmpty()||ui->lineEdit_password->text().isEmpty()){//用户名或密码为空
        if(QMessageBox::Ok==QMessageBox::warning(this,"提示","用户名或密码为空",QMessageBox::Ok|QMessageBox::Cancel)){
            qDebug()<<"QMessageBox::Ok!";
        }
        else{
            qDebug()<<"QMessageBox::Cancel!";
        }
    }
    else if(ui->lineEdit_username->text()=="admin"&&ui->lineEdit_password->text()=="12345"){
        //进入主界面
        this->accept();//隐藏对话框，让exec函数返回QDialog::Accepted
    }
    else{
        qDebug()<<"用户名或密码错误";
        if(QMessageBox::Yes==QMessageBox::warning(this,"提示","用户名或密码错误,是否重新输入",QMessageBox::Yes|QMessageBox::No)){
            ui->lineEdit_username->clear();
            ui->lineEdit_password->clear();
        }
    }
}

void MyCalculate::on_pushButton_exit_clicked()
{
    this->reject();
}

void MyCalculate::on_lineEdit_password_returnPressed()
{
    on_pushButton_login_clicked();
}
