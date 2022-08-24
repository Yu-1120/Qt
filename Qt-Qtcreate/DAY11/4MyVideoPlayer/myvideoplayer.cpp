#include "myvideoplayer.h"
#include "ui_myvideoplayer.h"
#include <QFileDialog>
#include <QKeyEvent>

MyVideoPlayer::MyVideoPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyVideoPlayer)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    vw = new QVideoWidget(this);
    //为vw安装过滤器，以外部窗口作为观察者
    vw->installEventFilter(this);

    //将播放窗口放入布局管理器
    ui->horizontalLayout->addWidget(vw);
    //设置播放器的显示窗口
    player->setVideoOutput(vw);

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
        video_duration = QString("%1:%2:%3").arg(duration/1000/60/60,2,10,QChar('0'))
                                            .arg(duration/1000/60%60,2,10,QChar('0'))
                                            .arg(duration/1000%60,2,10,QChar('0'));
        ui->label_pos->setText(QString("00:00:00/%1").arg(video_duration));

        //显示歌曲切换
        ui->listWidget->setCurrentRow(playlist->currentIndex());
    });

    QObject::connect(player,&QMediaPlayer::positionChanged,this,[&](quint64 position){
        //进度改变
        //更新进度条的值
        ui->horizontalSlider->setValue(position);
        //显示进度
        ui->label_pos->setText(QString("%1:%2:%3/%4").arg(position/1000/60/60,2,10,QChar('0'))
                                                     .arg(position/1000/60%60,2,10,QChar('0'))
                                                     .arg(position/1000%60,2,10,QChar('0'))
                                                     .arg(video_duration));
    });
}

MyVideoPlayer::~MyVideoPlayer()
{
    delete ui;
}

//过滤器函数
bool MyVideoPlayer::eventFilter(QObject *watched,QEvent *event)
{
    //Esc退出全屏
    if(event->type()==QEvent::KeyPress){
        QKeyEvent *keyevent = dynamic_cast<QKeyEvent *>(event);

        if(keyevent->key()==Qt::Key_Escape){
            //恢复成子窗口
            vw->setWindowFlag(Qt::SubWindow);
            //退出全屏
            vw->showNormal();
            //设置父对象
            vw->setParent(this);
            //加入到布局管理器
            ui->horizontalLayout->addWidget(vw);
        }
    }

    return QWidget::eventFilter(watched,event);
}

void MyVideoPlayer::on_pushButton_addvideo_clicked()
{
    QStringList video_files = QFileDialog::getOpenFileNames(this,"选择视频文件","D:/GZFX2108/Qt高级资料","*.mp4 *.avi *.mp3 *.WAV");

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

    //添加到listWidget和playlist
    for(int i=0;i<video_files.count();i++){
        QString file = video_files.at(i);
        //把文件加入播放列表
        playlist->addMedia(QUrl::fromLocalFile(file));
    }

    ui->listWidget->addItems(video_files);
    //定位
    ui->listWidget->setCurrentRow(0);
}

void MyVideoPlayer::on_pushButton_deletevideo_clicked()
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

void MyVideoPlayer::on_pushButton_clearvideo_clicked()
{
    ui->listWidget->clear();
    playlist->clear();
}

void MyVideoPlayer::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
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

void MyVideoPlayer::on_pushButton_play_clicked()
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

void MyVideoPlayer::on_pushButton_cancel_clicked()
{
    player->stop();

    ui->pushButton_stop_cont->setText("暂停");
    ui->pushButton_stop_cont->setEnabled(false);
}

void MyVideoPlayer::on_pushButton_stop_cont_clicked()
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

void MyVideoPlayer::on_pushButton_prev_clicked()
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

void MyVideoPlayer::on_pushButton_next_clicked()
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

//全屏
void MyVideoPlayer::on_pushButton_fullscreen_clicked()
{
    //升级为顶层窗口
    vw->setWindowFlag(Qt::Window);
    //全屏
    vw->showFullScreen();
}

void MyVideoPlayer::on_verticalSlider_sliderMoved(int position)
{
    //设置音量
    player->setVolume(position);
    //更新显示
    ui->label_vol->setText(QString("音量：%1").arg(position));
}

void MyVideoPlayer::on_horizontalSlider_sliderMoved(int position)
{
    player->setPosition(position);
}
