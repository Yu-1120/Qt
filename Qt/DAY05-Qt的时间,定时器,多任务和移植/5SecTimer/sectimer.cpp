#include "sectimer.h"
#include "ui_sectimer.h"

SecTimer::SecTimer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SecTimer)
{
    ui->setupUi(this);

    t = new QTimer(this);
    sec_time.setHMS(0,0,0,0);

    QObject::connect(t,&QTimer::timeout,this,[&](){
        sec_time = sec_time.addMSecs(10);
        //显示
        ui->label->setText(sec_time.toString("hh:mm:ss.zzz"));
    });
}

SecTimer::~SecTimer()
{
    delete ui;
}


void SecTimer::on_pushButton_start_clicked()
{
    t->start(10);

    ui->pushButton_stop->setEnabled(true);
    ui->pushButton_gettime->setEnabled(true);
    ui->pushButton_start->setEnabled(false);
}

void SecTimer::on_pushButton_stop_clicked()
{
    t->stop();

    ui->pushButton_stop->setEnabled(false);
    ui->pushButton_gettime->setEnabled(false);
    ui->pushButton_start->setEnabled(true);
}

void SecTimer::on_pushButton_gettime_clicked()
{
    ui->listWidget->addItem(ui->label->text());
}

void SecTimer::on_pushButton_clear_clicked()
{
    ui->listWidget->clear();
    sec_time.setHMS(0,0,0,0);
    ui->label->setText("00:00:00.000");
}
