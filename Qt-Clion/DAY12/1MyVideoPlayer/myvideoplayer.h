#ifndef MYVIDEOPLAYER_H
#define MYVIDEOPLAYER_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QListWidgetItem>
#include <QVideoWidget>
#include "myvideowidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyVideoPlayer; }
QT_END_NAMESPACE

class MyVideoPlayer : public QWidget
{
    Q_OBJECT

public:
    MyVideoPlayer(QWidget *parent = nullptr);
    ~MyVideoPlayer();
    //过滤器函数
    bool eventFilter(QObject *watched,QEvent *event);
    //加入到布局管理器
    void add_Layout(QWidget *w);

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_addvideo_clicked();

    void on_pushButton_deletevideo_clicked();

    void on_pushButton_clearvideo_clicked();

    void on_pushButton_play_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_stop_cont_clicked();

    void on_pushButton_prev_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_fullscreen_clicked();

    void on_verticalSlider_sliderMoved(int position);

    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::MyVideoPlayer *ui;
    //播放器
    QMediaPlayer *player;
    //播放列表
    QMediaPlaylist *playlist;
    //记录当前媒体周期
    QString video_duration;
    //播放窗口
    MyVideoWidget *vw;
};
#endif // MYVIDEOPLAYER_H
