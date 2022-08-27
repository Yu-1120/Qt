#include "calculate.h"
#include "ui_calculate.h"

Calculate::Calculate(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Calculate) {
    ui->setupUi(this);
    //初始化自定义成员
    num = 0;
    temp = 0;
}

Calculate::~Calculate() {
    delete ui;
}

void Calculate::on_pushButton_1_clicked() {
    if (num <= 999999999)
        num = num * 10 + 1;

    //显示
    ui->lcdNumber->display(num);
}

void Calculate::on_pushButton_2_clicked() {
    if (num <= 999999999)
        num = num * 10 + 2;

    //显示
    ui->lcdNumber->display(num);
}

void Calculate::on_pushButton_3_clicked() {
    if (num <= 999999999)
        num = num * 10 + 3;

    //显示
    ui->lcdNumber->display(num);
}

void Calculate::on_pushButton_4_clicked() {
    if (num <= 999999999)
        num = num * 10 + 4;

    //显示
    ui->lcdNumber->display(num);
}

void Calculate::on_pushButton_5_clicked() {
    if (num <= 999999999)
        num = num * 10 + 5;

    //显示
    ui->lcdNumber->display(num);
}

void Calculate::on_pushButton_6_clicked() {
    if (num <= 999999999)
        num = num * 10 + 6;

    //显示
    ui->lcdNumber->display(num);
}

void Calculate::on_pushButton_7_clicked() {
    if (num <= 999999999)
        num = num * 10 + 7;

    //显示
    ui->lcdNumber->display(num);
}

void Calculate::on_pushButton_8_clicked() {
    if (num <= 999999999)
        num = num * 10 + 8;

    //显示
    ui->lcdNumber->display(num);
}

void Calculate::on_pushButton_9_clicked() {
    if (num <= 999999999)
        num = num * 10 + 9;

    //显示
    ui->lcdNumber->display(num);
}

void Calculate::on_pushButton_0_clicked() {
    if (num <= 999999999)
        num = num * 10;

    //显示
    ui->lcdNumber->display(num);
}

//清0
void Calculate::on_pushButton_clear_clicked() {
    num = 0;
    temp = 0;

    //显示
    ui->lcdNumber->display(num);
}

//加法
void Calculate::on_pushButton_add_clicked() {
    //*****************this code meaning????*****************
    //如果temp不为0,前面已经输入过运算符
    if (temp > 0) {
        //计算
        on_pushButton_equ_clicked();
    }

    //记录加法
    op = oper_add; //?????
    //当前值放入第一操作数
    temp = num;
    //num清0
    num = 0;
    //********************************
}

void Calculate::on_pushButton_sub_clicked() {
    //如果temp不为0,前面已经输入过运算符
    if (temp > 0) {
        //计算
        on_pushButton_equ_clicked();
    }

    //记录
    op = oper_sub;
    //当前值放入第一操作数
    temp = num;
    //num清0
    num = 0;
}

void Calculate::on_pushButton_mul_clicked() {
    //如果temp不为0,前面已经输入过运算符
    if (temp > 0) {
        //计算
        on_pushButton_equ_clicked();
    }

    //记录
    op = oper_mul;
    //当前值放入第一操作数
    temp = num;
    //num清0
    num = 0;
}

void Calculate::on_pushButton_div_clicked() {
    //如果temp不为0,前面已经输入过运算符
    if (temp > 0) {
        //计算
        on_pushButton_equ_clicked();
    }

    //记录
    op = oper_div;
    //当前值放入第一操作数
    temp = num;
    //num清0
    num = 0;
}

void Calculate::on_pushButton_equ_clicked() {
    switch (op) {
        case oper_add:
            num = temp + num;
            break;
        case oper_sub:
            num = temp - num;
            break;
        case oper_mul:
            num = temp * num;
            break;
        case oper_div:
            if (num == 0) {
                num = 0;
                temp = 0;
                ui->lcdNumber->display("Err");
                return;
            }

            num = temp / num;
            break;
    }

    //操作数清0
    temp = 0;
    //显示
    if (num > 999999999) {
        ui->lcdNumber->display("Error");
        num = 0;
    } else
        ui->lcdNumber->display(num);
}
