#include "myaudio.h"
#include "ui_myaudio.h"

MyAudio::MyAudio(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyAudio)
{
    ui->setupUi(this);

    p = new QProcess(this);

    //连接进程结束的信号
    QObject::connect(p,QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),this,[&](int exitCode, QProcess::ExitStatus exitStatus){
        ui->pushButton_record->setText("录音");
    });
}

MyAudio::~MyAudio()
{
    if(p->state()==QProcess::Running){
        p->kill();
        p->waitForFinished();
    }

    delete ui;
}

//录音
void MyAudio::on_pushButton_record_clicked()
{
    if(p->state()==QProcess::Running){
        p->kill();
        p->waitForFinished();

        ui->pushButton_record->setText("录音");
    }
    else{
        QString cmd = "arecord";
        QStringList args;

        args<<"-d30"<<"-c1"<<"-r16000"<<"-twav"
            <<"-fS16_LE"<<"test.WAV"<<"&";

        p->start(cmd,args);

        ui->pushButton_record->setText("停止");
    }
}

//播放
void MyAudio::on_pushButton_play_clicked()
{
    if(p->state()==QProcess::Running){
        p->kill();
        p->waitForFinished();

        ui->pushButton_record->setText("录音");
    }

    QString cmd = "aplay";
    QStringList args;

    args<<"test.WAV"<<"&";

    p->start(cmd,args);
}
