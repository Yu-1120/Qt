#ifndef NEWCOURIERITEM_H
#define NEWCOURIERITEM_H

#include <QWidget>

namespace Ui {
class NewCourierItem;
}

class NewCourierItem : public QWidget
{
    Q_OBJECT

public:
    explicit NewCourierItem(QWidget *parent = nullptr);
    ~NewCourierItem();

    //设置id
    void setNum(int id);
    //设置图片
    void setPicture(QString url);
    //设置歌名
    void setMusicName(QString musicName);
    //设置log 默认
    void setLogPic();
    //设置作者
    void setMusicAuthor(QString author);
    //设置专辑
    void setMusicAlbum(QString name);
    //设置timer
    void setMusicTimer(QString strTimer);

private:
    Ui::NewCourierItem *ui;
};

#endif // NEWCOURIERITEM_H
