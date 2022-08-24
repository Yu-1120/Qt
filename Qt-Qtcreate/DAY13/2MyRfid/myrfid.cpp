#include "myrfid.h"
#include "ui_myrfid.h"

MyRfid::MyRfid(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyRfid)
{
    ui->setupUi(this);

    flag = false;
    thread = new RfidThread(this);
    //连接信号和槽
    QObject::connect(thread,&RfidThread::send_id,this,[&](unsigned int id){
        if(id){
            ui->label->setText(QString("卡号:%1").arg(id,0,16));
            flag = true;
        }
        else{
            if(flag){
                ui->label->clear();
                flag = false;
            }
        }
    });
}

MyRfid::~MyRfid()
{
    thread->terminate();

    delete ui;
}


void MyRfid::on_pushButton_start_clicked()
{
    thread->start();
}

void MyRfid::on_pushButton_stop_clicked()
{
    thread->terminate();
}
