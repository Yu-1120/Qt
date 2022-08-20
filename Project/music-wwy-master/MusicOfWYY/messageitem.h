#ifndef MESSAGEITEM_H
#define MESSAGEITEM_H

#include <QWidget>

namespace Ui {
class MessageItem;
}

class MessageItem : public QWidget
{
    Q_OBJECT

public:
    explicit MessageItem(QWidget *parent = nullptr);
    ~MessageItem();
    //设置是否有红点flog true 为红 false 为false
    void setRed(bool flog);
    //设置用户图片路径
    void setStringPic(QString url);
    //设置用户名字
    void setName(QString str);
    //设置时间
    void setTime(QString str);
    //设置说明
    void setInformMessage(QString str);


private:
    Ui::MessageItem *ui;
};

#endif // MESSAGEITEM_H
