#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "calculate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //********************************************

    //*********************************************
//    //设置窗口透明
//    setAttribute(Qt::WA_TranslucentBackground);
//    //设置无边窗体   并且为 tool的模式
//    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    this->window()->close();
    Calculate *cal = new Calculate();//要指针
    cal->show();
}
