#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QWidget>
#include <QProcess>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MusicPlayer; }
QT_END_NAMESPACE

class MusicPlayer : public QWidget
{
    Q_OBJECT

public:
    MusicPlayer(QWidget *parent = nullptr);
    ~MusicPlayer();

private slots:
    void on_pushButton_play_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_addmusic_clicked();

    void on_pushButton_deletemusic_clicked();

    void on_pushButton_clearmusic_clicked();

    void on_pushButton_stop_cont_clicked();

    void on_pushButton_prev_clicked();

    void on_pushButton_next_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MusicPlayer *ui;
    QProcess *p;
    //记录正在播放的音乐
    QString current_music;
};
#endif // MUSICPLAYER_H
