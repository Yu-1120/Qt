#include "mymplayer.h"
#include "ui_mymplayer.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

MyMplayer::MyMplayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyMplayer)
{
    ui->setupUi(this);

    p = new QProcess(this);
}

MyMplayer::~MyMplayer()
{
    if(p->state()==QProcess::Running){
        p->kill();
        p->waitForFinished();
    }

    delete ui;
}

//添加视频
void MyMplayer::on_pushButton_addvideo_clicked()
{
    QStringList video_files = QFileDialog::getOpenFileNames(this,"选择视频文件","/Even/GZFX2108","*.mp4 *.avi");

    //去重
    for(int i=0;i<ui->listWidget->count();i++){
        for(int j=0;j<video_files.count();j++){
            if(ui->listWidget->item(i)->text()==video_files.at(j)){
                video_files.removeAt(j);
                break;
            }
        }
    }

    //如果无添加文件，直接返回
    if(video_files.isEmpty())
        return;

    //添加到listWidget
    ui->listWidget->addItems(video_files);
    //定位
    ui->listWidget->setCurrentRow(0);
}

//删除视频
void MyMplayer::on_pushButton_deletevideo_clicked()
{
    int row = ui->listWidget->currentRow();
    //取出一项
    QListWidgetItem *item = ui->listWidget->takeItem(row);
    //删除的是正在播放的歌曲，停止播放
    if(item->text()==current_video){
        on_pushButton_cancel_clicked();
    }

    if(item){
        delete item;
    }
}

void MyMplayer::on_pushButton_clearvideo_clicked()
{
    ui->listWidget->clear();

    on_pushButton_cancel_clicked();
}

//播放
void MyMplayer::on_pushButton_play_clicked()
{
    //只有没有运行才开始播放
    if(p->state()==QProcess::Running){
        p->kill();
        p->waitForFinished();
    }

    QString cmd = QString("mplayer");
    QStringList args;//参数

    current_video = ui->listWidget->currentItem()->text();
    args<<"-quiet"<<"-slave"<<"-af"<<"volume=-10"<<"-zoom"
        <<"-x"<<"600"<<"-y"<<"360"<<current_video<<"&";

    p->start(cmd,args);

    ui->pushButton_stop_cont->setText("暂停");
    ui->pushButton_stop_cont->setEnabled(true);
}

//停止
void MyMplayer::on_pushButton_cancel_clicked()
{
    if(p->state()==QProcess::Running){
        p->kill();
        p->waitForFinished();
    }

    ui->pushButton_stop_cont->setText("暂停");
    ui->pushButton_stop_cont->setEnabled(false);

    ui->label->clear();
}

//暂停继续
void MyMplayer::on_pushButton_stop_cont_clicked()
{
    QString cmd = "killall";
    QStringList args;

    if(ui->pushButton_stop_cont->text()=="暂停"){
        args<<"-STOP"<<"mplayer";
        ui->pushButton_stop_cont->setText("继续");
    }
    else{
        args<<"-CONT"<<"mplayer";
        ui->pushButton_stop_cont->setText("暂停");
    }

    //阻塞执行
    p->execute(cmd,args);
}

//上一首
void MyMplayer::on_pushButton_prev_clicked()
{
    int row = ui->listWidget->currentRow();
    if(row==0)
        row = ui->listWidget->count();

    row--;

    ui->listWidget->setCurrentRow(row);

    //播放下一首
    on_pushButton_play_clicked();
}

//下一首
void MyMplayer::on_pushButton_next_clicked()
{
    int row = ui->listWidget->currentRow();
    if(row==ui->listWidget->count()-1)
        row = 0;
    else
        row++;

    ui->listWidget->setCurrentRow(row);

    //播放下一首
    on_pushButton_play_clicked();
}

//双击播放
void MyMplayer::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    //只有没有运行才开始播放
    if(p->state()==QProcess::Running){
        p->kill();
        p->waitForFinished();
    }

    QString cmd = QString("mplayer");
    QStringList args;//参数

    current_video = item->text();
    args<<"-quiet"<<"-slave"<<"-af"<<"volume=-10"<<"-zoom"
        <<"-x"<<"600"<<"-y"<<"360"<<current_video<<"&";

    p->start(cmd,args);

    ui->pushButton_stop_cont->setText("暂停");
    ui->pushButton_stop_cont->setEnabled(true);
}
