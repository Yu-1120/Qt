#include "messageform.h"
#include "ui_messageform.h"
#include "messageitem.h"
#include <QScrollBar>

MessageForm::MessageForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageForm)
{
    ui->setupUi(this);
//    this->setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_StyledBackground); //设置样式表
    setButttonGroup();//设置按钮
    setListMessage();//设置列表消息
    ui->listMessage->setStyleSheet("QListWidget{border:1px;background:white;border-radius:5px;}"
                                  "QListWidget::Item{ background:white; height:60px;}"
                                  "QListWidget::Item:hover{background:rgb(246,246,247);}"
                                  );

   QScrollBar* sv = ui->listMessage->verticalScrollBar();
   sv->setStyleSheet("QScrollBar:vertical{background:transparent; width:6px;}"
                     "QScrollBar::handle:vertical{min-height:10px;max-height:20px;background:rgb(224,224,224); width:6px; border-radius:3px;}"
                     "QScrollBar::up-arrow:vertical{border:none;}"
                     "QScrollBar::sub-line:vertical{background:transparent;}"
                     "QScrollBar::add-line:vertical{background:transparent;}");
   this->setStyleSheet("QWidget{border:0px; background:white; border-radius:1px;}");
    ui->labRead->setStyleSheet("QLabel{color:rgb(80,125,175);}");

//    ui->listMessage->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

MessageForm::~MessageForm()
{
    delete ui;
}

void MessageForm::setButttonGroup()
{
    ui->widGroupBut->setGeometry(10,60,342,30);
    ui->widGroupBut->setStyleSheet("QWidget#widGroupBut{background:rgb(255,255,255);border:1px solid rgb(187,187,187);border-radius:15px;}");
    /*私信按钮*/
    ui->ptnPer->setParent(ui->widGroupBut);
    ui->ptnPer->setGeometry(0,1,85,28);
    ui->ptnPer->move(1,1);
    ui->ptnPer->setCheckable(true);
    ui->ptnPer->setStyleSheet("QPushButton{color:rgb(55,55,55);border:0px;background:rgb(255,255,255);border-radius:14px;}"
                            "QPushButton:hover{border:0px;background:rgb(244,244,244);border-radius:14px;}"
                            "QPushButton:checked{color:rgb(255,255,255);border:0px;background:rgb(187,187,187);border-radius:14px;}");
    /*评论按钮*/
    ui->ptnComment->setParent(ui->widGroupBut);
    ui->ptnComment->setGeometry(0,1,85,28);
    ui->ptnComment->move(86,1);
    ui->ptnComment->setCheckable(true);
    ui->ptnComment->setStyleSheet("QPushButton{color:rgb(55,55,55);border:0px;background:rgb(255,255,255);border-radius:14px;}"
                            "QPushButton:hover{border:0px;background:rgb(244,244,244);border-radius:14px;}"
                            "QPushButton:checked{color:rgb(255,255,255);border:0px;background:rgb(187,187,187);border-radius:14px;}");
    /*@我按钮*/
    ui->ptnMe->setParent(ui->widGroupBut);
    ui->ptnMe->setGeometry(0,1,85,28);
    ui->ptnMe->move(171,1);
    ui->ptnMe->setCheckable(true);
    ui->ptnMe->setStyleSheet("QPushButton{color:rgb(55,55,55);border:0px;background:rgb(255,255,255);border-radius:14px;}"
                            "QPushButton:hover{border:0px;background:rgb(244,244,244);border-radius:14px;}"
                            "QPushButton:checked{color:rgb(255,255,255);border:0px;background:rgb(187,187,187);border-radius:14px;}");
    /*通知按钮*/
    ui->ptnInform->setParent(ui->widGroupBut);
    ui->ptnInform->setGeometry(0,1,85,28);
    ui->ptnInform->move(256,1);
    ui->ptnInform->setCheckable(true);
    ui->ptnInform->setStyleSheet("QPushButton{color:rgb(55,55,55);border:0px;background:rgb(255,255,255);border-radius:14px;}"
                            "QPushButton:hover{border:0px;background:rgb(244,244,244);border-radius:14px;}"
                            "QPushButton:checked{color:rgb(255,255,255);border:0px;background:rgb(187,187,187);border-radius:14px;}");
    QButtonGroup * btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->ptnPer,0);
    btnGroup->addButton(ui->ptnComment,1);
    btnGroup->addButton(ui->ptnMe,2);
    btnGroup->addButton(ui->ptnInform,3);
    btnGroup->setExclusive(true);
    btnGroup->button(0)->setChecked(true);

    //连接槽
    connect(btnGroup, QOverload<int>::of(&QButtonGroup::buttonClicked),
          [=](int id){
          //这里处理对应界面
          setMessageId(id);
    });

}

void MessageForm::setMessageId(int id)
{
    switch (id) {

    default:
        break;
    }
}

void MessageForm::setListMessage()
{
  // MessageItem  QListWidgetItem
    //加载图片路径 名字 消息 时间
    QStringList pictureList;
    for(int i = 0; i<11; i++)
    {
        QString str = QString::asprintf("./images/message/per%d.png",i);
        pictureList.append(str);
    }
    QVector<bool> flog  = {true,false,false,false,false,false,false,false,false,false,false};
    QStringList perNameList = {"比卡丘不皮", "云贝小助手","云音乐小秘书","网易云音乐",
                              "云音乐福利", "吉法师","ICY","九月","公孙二狗",
                               "龚建波","默片"};
    QStringList timerList = {"2021年10月3日","2021年9月15日","2021年9月4日","2021年6月3日",
                            "2021年4月24日","2021年4月12日","2021年3月27日","2021年3月10日",
                            "2021年2月18日","2021年2月5日","2021年1月1日"};

    QStringList messageInformList ={"通知：你终于完成了你想做的东西，希望这个能给你带来好运",
                                   "[通知]：中心完成了任务，送你更好的东西",
                                   "通知：你的账号已经在别的地方登录了，希望你快点解决",
                                   "通知：不开VIP还听啥歌，开了也听不到啥歌",
                                   "通知：恭喜你成功达到8级，继续加油",
                                   "通知：[技惊四坐]",
                                   "通知：我设计的游戏好完莫",
                                   "通知：一个能打的都没有",
                                   "通知：狗哥牛逼",
                                   "通知：荣县QT第一人不是吹的",
                                   "通知：。。。。。。"};

    for (int i = 0; i <11; i++) {
        QListWidgetItem *item = new QListWidgetItem(ui->listMessage);
        MessageItem *messItem = new MessageItem();
        messItem->setRed(flog[i]);
        messItem->setStringPic(pictureList[i]);
        messItem->setName(perNameList[i]);
        messItem->setTime(timerList[i]);
        messItem->setInformMessage(messageInformList[i]);
        ui->listMessage->setItemWidget(item,messItem);
    }

}

void MessageForm::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    this->close();
}
