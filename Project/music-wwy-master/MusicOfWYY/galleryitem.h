#ifndef GALLERYITEM_H
#define GALLERYITEM_H

#include <QWidget>

namespace Ui {
class GalleryItem;
}

class GalleryItem : public QWidget
{
    Q_OBJECT

public:
    explicit GalleryItem(QWidget *parent = nullptr);
    ~GalleryItem();
    //设置说明
    void setMessage(QString str);
    //设置图片
    void setPicture(QString url);

private:
    Ui::GalleryItem *ui;
};

#endif // GALLERYITEM_H
