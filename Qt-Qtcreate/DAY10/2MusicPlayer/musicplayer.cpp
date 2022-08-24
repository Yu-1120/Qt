#include "musicplayer.h"
#include "ui_musicplayer.h"
#include <QFileDialog>

MusicPlayer::MusicPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MusicPlayer)
{
    ui->setupUi(this);

    p = new QProcess(this);
}

MusicPlayer::~MusicPlayer()
{
    if(p->state()==QProcess::Running){
        p->kill();
        p->waitForFinished();
    }

    delete ui;
}

//播放
void MusicPlayer::on_pushButton_play_clicked()
{
    //只有没有运行才开始播放
    if(p->state()==QProcess::Running){
        p->kill();
        p->waitForFinished();
    }

    QString cmd = QString("madplay");
    QStringList args;//参数

    current_music = ui->listWidget->currentItem()->text();
    args<<current_music<<"&";

    p->start(cmd,args);

    ui->pushButton_stop_cont->setText("暂停");
    ui->pushButton_stop_cont->setEnabled(true);
}

//停止
void MusicPlayer::on_pushButton_cancel_clicked()
{
    if(p->state()==QProcess::Running){
        p->kill();
        p->waitForFinished();
    }

    ui->pushButton_stop_cont->setText("暂停");
    ui->pushButton_stop_cont->setEnabled(false);
}

//添加音乐
void MusicPlayer::on_pushButton_addmusic_clicked()
{
    QStringList music_files = QFileDialog::getOpenFileNames(this,"选择音乐文件","/GZFX2108/music","*.mp3 *.WAV");

    //去重
    for(int i=0;i<ui->listWidget->count();i++){
        for(int j=0;j<music_files.count();j++){
            if(ui->listWidget->item(i)->text()==music_files.at(j)){
                music_files.removeAt(j);
                break;
            }
        }
    }

    //如果无添加文件，直接返回
    if(music_files.isEmpty())
        return;

    //添加到listWidget
    ui->listWidget->addItems(music_files);
    //定位
    ui->listWidget->setCurrentRow(0);
}

//删除音乐
void MusicPlayer::on_pushButton_deletemusic_clicked()
{
    int row = ui->listWidget->currentRow();
    //取出一项
    QListWidgetItem *item = ui->listWidget->takeItem(row);
    //删除的是正在播放的歌曲，停止播放
    if(item->text()==current_music){
        on_pushButton_cancel_clicked();
    }

    if(item){
        delete item;
    }
}

//清空
void MusicPlayer::on_pushButton_clearmusic_clicked()
{
    ui->listWidget->clear();

    on_pushButton_cancel_clicked();
}

//暂停
void MusicPlayer::on_pushButton_stop_cont_clicked()
{
    QString cmd = "killall";
    QStringList args;

    if(ui->pushButton_stop_cont->text()=="暂停"){
        args<<"-STOP"<<"madplay"<<"&";
        ui->pushButton_stop_cont->setText("继续");
    }
    else{
        args<<"-CONT"<<"madplay"<<"&";
        ui->pushButton_stop_cont->setText("暂停");
    }

    //阻塞执行
    p->execute(cmd,args);
}

//上一首
void MusicPlayer::on_pushButton_prev_clicked()
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
void MusicPlayer::on_pushButton_next_clicked()
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

void MusicPlayer::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    //只有没有运行才开始播放
    if(p->state()==QProcess::Running){
        p->kill();
        p->waitForFinished();
    }

    QString cmd = QString("madplay");
    QStringList args;//参数

    current_music = item->text();
    args<<current_music<<"&";

    p->start(cmd,args);

    ui->pushButton_stop_cont->setText("暂停");
    ui->pushButton_stop_cont->setEnabled(true);
}
