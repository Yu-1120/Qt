#ifndef MYMEDIAPLAYER_H
#define MYMEDIAPLAYER_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MyMediaPlayer; }
QT_END_NAMESPACE

class MyMediaPlayer : public QWidget
{
    Q_OBJECT

public:
    MyMediaPlayer(QWidget *parent = nullptr);
    ~MyMediaPlayer();

private slots:
    void on_pushButton_addmusic_clicked();

    void on_pushButton_deletemusic_clicked();

    void on_pushButton_clearmusic_clicked();

    void on_pushButton_play_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_stop_cont_clicked();

    void on_pushButton_prev_clicked();

    void on_pushButton_next_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_verticalSlider_sliderMoved(int position);

    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::MyMediaPlayer *ui;
    //播放器
    QMediaPlayer *player;
    //播放列表
    QMediaPlaylist *playlist;
    //记录当前媒体周期
    QString music_duration;
};
#endif // MYMEDIAPLAYER_H
