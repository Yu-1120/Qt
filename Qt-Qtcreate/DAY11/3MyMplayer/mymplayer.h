#ifndef MYMPLAYER_H
#define MYMPLAYER_H

#include <QWidget>
#include <QProcess>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MyMplayer; }
QT_END_NAMESPACE

class MyMplayer : public QWidget
{
    Q_OBJECT

public:
    MyMplayer(QWidget *parent = nullptr);
    ~MyMplayer();

private slots:
    void on_pushButton_addvideo_clicked();

    void on_pushButton_deletevideo_clicked();

    void on_pushButton_clearvideo_clicked();

    void on_pushButton_play_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_stop_cont_clicked();

    void on_pushButton_prev_clicked();

    void on_pushButton_next_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MyMplayer *ui;
    QProcess *p;
    //记录正在播放的视频
    QString current_video;
};
#endif // MYMPLAYER_H
