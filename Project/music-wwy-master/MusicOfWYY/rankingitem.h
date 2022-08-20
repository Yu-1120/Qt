#ifndef RANKINGITEM_H
#define RANKINGITEM_H

#include <QWidget>

namespace Ui {
class RankingItem;
}

class RankingItem : public QWidget
{
    Q_OBJECT

public:
    explicit RankingItem(QWidget *parent = nullptr);
    ~RankingItem();

    //设置第一数据，false 为普通颜色, true为红色
    void setNum(int num,bool b);
    //设置第2个数据 str  or  pic(int)
    void setStringOrPic(QString str);
    //num = 0 加载上  1加载下 2加载-， 其它不处理
    void setStringOrPic(int  num);
    //设置歌名
    void setMusicName(QString strName);
    //设置作者
    void setMusicAutor(QString name);

private:
    Ui::RankingItem *ui;
};

#endif // RANKINGITEM_H
