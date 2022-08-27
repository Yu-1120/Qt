#include "myvideowidget.h"
#include <QKeyEvent>
#include "myvideoplayer.h"

MyVideoWidget::MyVideoWidget(QWidget *parent):QVideoWidget(parent)
{
    //记录父对象
    p = parent;
}

void MyVideoWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape){
        //恢复成子窗口
        this->setWindowFlag(Qt::SubWindow);
        //退出全屏
        this->showNormal();
        //设置父对象
        this->setParent(p);
        //加入到布局管理器
        MyVideoPlayer *vp = dynamic_cast<MyVideoPlayer *>(p);
        vp->add_Layout(this);
    }
}
