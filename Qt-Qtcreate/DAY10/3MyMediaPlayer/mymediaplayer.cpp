#include "mymediaplayer.h"
#include "ui_mymediaplayer.h"
#include <QUrl>
#include <QFileDialog>

MyMediaPlayer::MyMediaPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyMediaPlayer)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);

    //设置播放列表播放模式
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    //设置播放器的播放列表
    player->setPlaylist(playlist);

    //连接信号和槽
    QObject::connect(player,&QMediaPlayer::durationChanged,this,[&](quint64 duration){
        //周期改变
        //设置进度条的最大值
        ui->horizontalSlider->setRange(0,duration);
        //显示周期
        music_duration = QString("%1:%2").arg(duration/1000/60).arg(duration/1000%60);
        ui->label_pos->setText(QString("00:00/%1").arg(music_duration));

        //显示歌曲切换
        ui->listWidget->setCurrentRow(playlist->currentIndex());
    });

    QObject::connect(player,&QMediaPlayer::positionChanged,this,[&](quint64 position){
        //进度改变
        //更新进度条的值
        ui->horizontalSlider->setValue(position);
        //显示进度

    });

    //设置播放媒体
    //player->setMedia(QUrl("D:/GZFX2108/Qt高级资料/music/1one.mp3"));
}

MyMediaPlayer::~MyMediaPlayer()
{
    delete ui;
}


void MyMediaPlayer::on_pushButton_addmusic_clicked()
{
    QStringList music_files = QFileDialog::getOpenFileNames(this,"选择音乐文件","D:/GZFX2108/Qt高级资料/music","*.mp3 *.WAV");

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

    //添加到listWidget和playlist
    for(int i=0;i<music_files.count();i++){
        QString file = music_files.at(i);
        //把文件加入播放列表
        playlist->addMedia(QUrl::fromLocalFile(file));
    }

    ui->listWidget->addItems(music_files);
    //定位
    ui->listWidget->setCurrentRow(0);
}

void MyMediaPlayer::on_pushButton_deletemusic_clicked()
{
    int row = ui->listWidget->currentRow();
    //取出一项
    QListWidgetItem *item = ui->listWidget->takeItem(row);

    if(item){
        delete item;
    }

    //从播放列表中删除
    playlist->removeMedia(row);
}

void MyMediaPlayer::on_pushButton_clearmusic_clicked()
{
    ui->listWidget->clear();
    playlist->clear();
}

void MyMediaPlayer::on_pushButton_play_clicked()
{
    //指定当前播放的文件
    int row = ui->listWidget->currentRow();
    playlist->setCurrentIndex(row);

    player->play();
    //设置音量
    player->setVolume(ui->verticalSlider->value());


    ui->pushButton_stop_cont->setText("暂停");
    ui->pushButton_stop_cont->setEnabled(true);
}

void MyMediaPlayer::on_pushButton_cancel_clicked()
{
    player->stop();

    ui->pushButton_stop_cont->setText("暂停");
    ui->pushButton_stop_cont->setEnabled(false);
}

//暂停/继续
void MyMediaPlayer::on_pushButton_stop_cont_clicked()
{
    if(player->state()==QMediaPlayer::PlayingState){
        //暂停
        player->pause();
        ui->pushButton_stop_cont->setText("继续");
    }
    else if(player->state()==QMediaPlayer::PausedState){
        //继续
        player->play();
        ui->pushButton_stop_cont->setText("暂停");
    }
}

//上一首
void MyMediaPlayer::on_pushButton_prev_clicked()
{
    int row = ui->listWidget->currentRow();
    if(row==0)
        row = ui->listWidget->count();

    row--;

    ui->listWidget->setCurrentRow(row);
    //设置playlist
    playlist->setCurrentIndex(row);

    player->play();
    //设置音量
    player->setVolume(ui->verticalSlider->value());

    ui->pushButton_stop_cont->setText("暂停");
    ui->pushButton_stop_cont->setEnabled(true);
}

//下一首
void MyMediaPlayer::on_pushButton_next_clicked()
{
    int row = ui->listWidget->currentRow();
    if(row==ui->listWidget->count()-1)
        row = 0;
    else
        row++;

    ui->listWidget->setCurrentRow(row);
    //设置playlist
    playlist->setCurrentIndex(row);

    player->play();
    //设置音量
    player->setVolume(ui->verticalSlider->value());

    ui->pushButton_stop_cont->setText("暂停");
    ui->pushButton_stop_cont->setEnabled(true);
}

//双击播放
void MyMediaPlayer::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    int row = ui->listWidget->currentRow();
    playlist->setCurrentIndex(row);

    player->play();
    //设置音量
    player->setVolume(ui->verticalSlider->value());

    ui->pushButton_stop_cont->setText("暂停");
    ui->pushButton_stop_cont->setEnabled(true);
}

//移动声音滑动条
void MyMediaPlayer::on_verticalSlider_sliderMoved(int position)
{
    //设置音量
    player->setVolume(position);
    //更新显示
    ui->label_vol->setText(QString("音量：%1").arg(position));
}

//移动进度条
void MyMediaPlayer::on_horizontalSlider_sliderMoved(int position)
{
    player->setPosition(position);
}
