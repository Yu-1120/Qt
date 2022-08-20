#include "allmain.h"
#include "ui_allmain.h"
#include <QListWidgetItem>
#include <QColor>

AllMain::AllMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AllMain)
{
    ui->setupUi(this);
    //首先去除自带的边框
    this->setWindowFlag(Qt::FramelessWindowHint);
    //加入过滤器
    ui->line_Search->installEventFilter(this);
    ui->line_Search->setMouseTracking(true);
    searchForm = new SearchForm(this); //创建一个新的搜索框
    searchForm->installEventFilter(this);
    searchForm->setMouseTracking(true);
    searchForm->hide();

 //   setAttribute(Qt::WA_StyledBackground); //设置样式表

    setListT1(); //设置ListT1
    setListT2();
    setListT3();
    setTabWidget(); //设置tabWidget 页
    setPictureWall(); //添加轮播图
    setGallery();  //添加画廊部分
    setButtonMus(); //添加按钮组
    setRankData();//设置排行榜数据
    setRankNew(); //设置新歌榜
   /*歌手模块*/
    setSingerLaug();
    setSingerClass();
    setSingerScreen();
    /*最新音乐模块*/
    setAddWidget();
    setNewMusicButton();
    setNewMusicChooseButton();
    /*左下角模块*/
    setMusicLeft();
    //初始化音乐
    setMusicList();

}

AllMain::~AllMain()
{
    delete ui;
}

void AllMain::setListT1()
{
    //首先我们要把滚动条给取消掉 垂直与水平
    ui->listT1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listT1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QListWidgetItem *findMusic = new QListWidgetItem(ui->listT1);
    findMusic->setText("发现音乐");
    QListWidgetItem *podcast = new QListWidgetItem(ui->listT1);
    podcast->setText("播客");
    QListWidgetItem *video = new QListWidgetItem(ui->listT1);
    video->setText("视频");
    QListWidgetItem *friends = new QListWidgetItem(ui->listT1);
    friends->setText("朋友");
    QListWidgetItem *live = new QListWidgetItem(ui->listT1);
    live->setText("直播");
    QListWidgetItem *pcFM = new QListWidgetItem(ui->listT1);
    pcFM->setText("私人FM");

}

void AllMain::setListT2()
{
    ui->listT2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listT2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QListWidgetItem *localDownload = new QListWidgetItem(ui->listT2);
    localDownload->setIcon(QIcon("./images/下载.png"));
    localDownload->setText("本地与下载");

    QListWidgetItem *recentPlay = new QListWidgetItem(ui->listT2);
    recentPlay->setIcon(QIcon("./images/最近播放.png"));
    recentPlay->setText("最近播放");

    QListWidgetItem *myMusic = new QListWidgetItem(ui->listT2);
    myMusic->setIcon(QIcon("./images/云盘.png"));
    myMusic->setText("我的音乐云盘");

    QListWidgetItem *myPodcast = new QListWidgetItem(ui->listT2);
    myPodcast->setIcon(QIcon("./images/播客.png"));
    myPodcast->setText("我的播客");

    QListWidgetItem *myCollect = new QListWidgetItem(ui->listT2);
    myCollect->setIcon(QIcon("./images/收藏.png"));
    myCollect->setText("我的收藏");
}

void AllMain::setListT3()
{
    ui->listT3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listT3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QListWidgetItem *myLove = new QListWidgetItem(ui->listT3);
    myLove->setIcon(QIcon("./images/心.png"));
    myLove->setText("我喜欢的音乐");

}

void AllMain::setTabWidget()
{
    ui->tabWidget->setTabText(0,"个性推荐");
    ui->tabWidget->setTabText(1,"专属定制");
    ui->tabWidget->setTabText(2,"歌单");
    ui->tabWidget->setTabText(3,"排行榜");
    ui->tabWidget->setTabText(4,"歌手");
    ui->tabWidget->setTabText(5,"最新音乐");
}

void AllMain::setPictureWall()
{
    pictureWidget = new PictureWidget();
    ui->verLout_pic->addWidget(pictureWidget);
}

void AllMain::setGallery()
{
    //初始话数据
    gallerPrivate = new GalleryPrivate();

    QList<GalleryItem * > items;
    //添加8个数据
    GalleryItem *item = new GalleryItem();
    item->setPicture("./images/Gallery/1.png");
    item->setMessage("从《远方》开启保障音乐环游|宝藏雷达");
    items.append(item);
    //2
    GalleryItem *item2 = new GalleryItem();
    item2->setPicture("./images/Gallery/2.png");
    item2->setMessage("还在听《隐隐约约》吗|时光雷达");
    items.append(item2);

    GalleryItem *item3 = new GalleryItem();
    item3->setPicture("./images/Gallery/3.png");
    item3->setMessage("今天从《当爱已成往事》听起|私人雷达");
    items.append(item3);

    GalleryItem *item4 = new GalleryItem();
    item4->setPicture("./images/Gallery/4.png");
    item4->setMessage("孙楠的歌总是令人心动|时光雷达");
    items.append(item4);

    GalleryItem *item5 = new GalleryItem();
    item5->setPicture("./images/Gallery/5.png");
    item5->setMessage("吉法师带你来听听歌 |qq雷达");
    items.append(item5);

    GalleryItem *item6 = new GalleryItem();
    item6->setPicture("./images/Gallery/6.png");
    item6->setMessage("从《爱的代价》开启宝藏音乐|时光雷达");
    items.append(item6);

    GalleryItem *item7 = new GalleryItem();
    item7->setPicture("./images/Gallery/7.png");
    item7->setMessage("你喜欢的韩国音乐|你的雷达");
    items.append(item7);

    GalleryItem *item8 = new GalleryItem();
    item8->setPicture("./images/Gallery/8.png");
    item8->setMessage("《The end of word》就是那么好听|时光雷达");
    items.append(item8);

    gallerPrivate->setItemRes(item->width(),item->height(),items);

    ui->horizontalLayout_6->setContentsMargins(0,0,0,0);
    ui->horizontalLayout_6->addWidget(gallerPrivate->getItemViewport());

    this->setStyleSheet("QWidget#customization{border:1px; background:white; border-radius:5px;}");
}

void AllMain::setButtonMus()
{
    pButtonMus = new QButtonGroup(this);
    pButtonMus->addButton(ui->ptn0,0);
    pButtonMus->addButton(ui->ptn1,1);
    pButtonMus->addButton(ui->ptn2,2);
    pButtonMus->addButton(ui->ptn3,3);
    pButtonMus->addButton(ui->ptn4,4);
    pButtonMus->addButton(ui->ptn5,5);
    pButtonMus->addButton(ui->ptn6,6);
    pButtonMus->addButton(ui->ptn7,7);
    pButtonMus->addButton(ui->ptn8,8);
    pButtonMus->addButton(ui->ptn9,9);
    pButtonMus->setExclusive(true);
    pButtonMus->button(0)->setChecked(true);

    connect(pButtonMus, QOverload<int>::of(&QButtonGroup::buttonClicked),
          [=](int id){
          setSourceMus(id);
    });

}

void AllMain::setSourceMus(int id)
{
    QString str = pButtonMus->button(id)->text();
    ui->ptnChange->setText(str+" >");
    switch (id)
    {
    //0 华语
     case 0:
        {
            QList<QString> arrHuayu;
            for (int i = 0; i<5;i++) {
                arrHuayu.append(QString::asprintf("./images/pictureMusic/huayu%d.png",i));
            }
            QString style = "QWidget#picTitle{border-image:url("+arrHuayu[0]+");}";
            ui->picTitle->setStyleSheet(style);
            style = "QWidget#widMus1{border-image:url("+arrHuayu[1]+");}";
            ui->widMus1->setStyleSheet(style);
            style = "QWidget{border-image:url("+arrHuayu[2]+");}";
            ui->widMus2->setStyleSheet(style);
            style = "QWidget{border-image:url("+arrHuayu[3]+");}";
            ui->widMus3->setStyleSheet(style);
            style = "QWidget{border-image:url("+arrHuayu[4]+");}";
            ui->widMus4->setStyleSheet(style);
            break;
        }
    //流行
    case 1:
    {
        QList<QString> arrLiuxing;
        for (int i = 0; i<5;i++) {
            arrLiuxing.append(QString::asprintf("./images/pictureMusic/liuxing%d.png",i));
        }
        QString style = "QWidget#picTitle{border-image:url("+arrLiuxing[0]+");}";
        ui->picTitle->setStyleSheet(style);
        style = "QWidget#widMus1{border-image:url("+arrLiuxing[1]+");}";
        ui->widMus1->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrLiuxing[2]+");}";
        ui->widMus2->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrLiuxing[3]+");}";
        ui->widMus3->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrLiuxing[4]+");}";
        ui->widMus4->setStyleSheet(style);
        break;
    }
    //摇滚
    case 2:
    {
        QList<QString> arrYaogun;
        for (int i = 0; i<5;i++) {
            arrYaogun.append(QString::asprintf("./images/pictureMusic/yaogun%d.png",i));
        }
        QString style = "QWidget#picTitle{border-image:url("+arrYaogun[0]+");}";
        ui->picTitle->setStyleSheet(style);
        style = "QWidget#widMus1{border-image:url("+arrYaogun[1]+");}";
        ui->widMus1->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrYaogun[2]+");}";
        ui->widMus2->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrYaogun[3]+");}";
        ui->widMus3->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrYaogun[4]+");}";
        ui->widMus4->setStyleSheet(style);
        break;
    }
        //民谣
    case 3:
    {
        QList<QString> arrMinyao;
        for (int i = 0; i<5;i++) {
            arrMinyao.append(QString::asprintf("./images/pictureMusic/minyao%d.png",i));
        }
        QString style = "QWidget#picTitle{border-image:url("+arrMinyao[0]+");}";
        ui->picTitle->setStyleSheet(style);
        style = "QWidget#widMus1{border-image:url("+arrMinyao[1]+");}";
        ui->widMus1->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrMinyao[2]+");}";
        ui->widMus2->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrMinyao[3]+");}";
        ui->widMus3->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrMinyao[4]+");}";
        ui->widMus4->setStyleSheet(style);
        break;
    }
        //电子
    case 4:
    {
        QList<QString> arrDianzi;
        for (int i = 0; i<5;i++) {
            arrDianzi.append(QString::asprintf("./images/pictureMusic/dianzi%d.png",i));
        }
        QString style = "QWidget#picTitle{border-image:url("+arrDianzi[0]+");}";
        ui->picTitle->setStyleSheet(style);
        style = "QWidget#widMus1{border-image:url("+arrDianzi[1]+");}";
        ui->widMus1->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrDianzi[2]+");}";
        ui->widMus2->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrDianzi[3]+");}";
        ui->widMus3->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrDianzi[4]+");}";
        ui->widMus4->setStyleSheet(style);
        break;
    }
        //另类
    case 5:
    {
        QList<QString> arrLinglei;
        for (int i = 0; i<5;i++) {
            arrLinglei.append(QString::asprintf("./images/pictureMusic/linglei%d.png",i));
        }
        QString style = "QWidget#picTitle{border-image:url("+arrLinglei[0]+");}";
        ui->picTitle->setStyleSheet(style);
        style = "QWidget#widMus1{border-image:url("+arrLinglei[1]+");}";
        ui->widMus1->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrLinglei[2]+");}";
        ui->widMus2->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrLinglei[3]+");}";
        ui->widMus3->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrLinglei[4]+");}";
        ui->widMus4->setStyleSheet(style);
        break;
    }
        //轻音乐
    case 6:
    {
        QList<QString> arrQingyinyue;
        for (int i = 0; i<5;i++) {
            arrQingyinyue.append(QString::asprintf("./images/pictureMusic/qingyinyue%d.png",i));
        }
        QString style = "QWidget#picTitle{border-image:url("+arrQingyinyue[0]+");}";
        ui->picTitle->setStyleSheet(style);
        style = "QWidget#widMus1{border-image:url("+arrQingyinyue[1]+");}";
        ui->widMus1->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrQingyinyue[2]+");}";
        ui->widMus2->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrQingyinyue[3]+");}";
        ui->widMus3->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrQingyinyue[4]+");}";
        ui->widMus4->setStyleSheet(style);
        break;
    }
        //综艺
    case 7:
    {
        QList<QString> arrZongyi;
        for (int i = 0; i<5;i++) {
            arrZongyi.append(QString::asprintf("./images/pictureMusic/zongyi%d.png",i));
        }
        QString style = "QWidget#picTitle{border-image:url("+arrZongyi[0]+");}";
        ui->picTitle->setStyleSheet(style);
        style = "QWidget#widMus1{border-image:url("+arrZongyi[1]+");}";
        ui->widMus1->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrZongyi[2]+");}";
        ui->widMus2->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrZongyi[3]+");}";
        ui->widMus3->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrZongyi[4]+");}";
        ui->widMus4->setStyleSheet(style);
        break;
    }
        //原声
    case 8:
    {
        QList<QString> arrYuansheng;
        for (int i = 0; i<5;i++) {
            arrYuansheng.append(QString::asprintf("./images/pictureMusic/yuansheng%d.png",i));
        }
        QString style = "QWidget#picTitle{border-image:url("+arrYuansheng[0]+");}";
        ui->picTitle->setStyleSheet(style);
        style = "QWidget#widMus1{border-image:url("+arrYuansheng[1]+");}";
        ui->widMus1->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrYuansheng[2]+");}";
        ui->widMus2->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrYuansheng[3]+");}";
        ui->widMus3->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrYuansheng[4]+");}";
        ui->widMus4->setStyleSheet(style);
        break;
    }
        //ACG
    case 9:
    {
        QList<QString> arrAcg;
        for (int i = 0; i<5;i++) {
            arrAcg.append(QString::asprintf("./images/pictureMusic/Acg%d.png",i));
        }
        QString style = "QWidget#picTitle{border-image:url("+arrAcg[0]+");}";
        ui->picTitle->setStyleSheet(style);
        style = "QWidget#widMus1{border-image:url("+arrAcg[1]+");}";
        ui->widMus1->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrAcg[2]+");}";
        ui->widMus2->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrAcg[3]+");}";
        ui->widMus3->setStyleSheet(style);
        style = "QWidget{border-image:url("+arrAcg[4]+");}";
        ui->widMus4->setStyleSheet(style);
        break;
    }
    default:
        break;
    }
}

void AllMain::setRankData()
{
    //第一个
    QListWidgetItem * newWidget = new QListWidgetItem(ui->listCont);
    RankingItem * item = new  RankingItem();
    newWidget->setBackgroundColor(QColor(249,249,249));
    newWidget->setSizeHint(QSize(item->width(),item->height()));
    item->setNum(1,true);
    item->setStringOrPic("792%");
    item->setMusicName("删了吧");
    item->setMusicAutor("烟(许佳豪)");
    ui->listCont->insertItem(0,newWidget);
    ui->listCont->setItemWidget(newWidget,item);

    //
    QListWidgetItem * newWidget1 = new QListWidgetItem(ui->listCont);
    RankingItem * item1 = new  RankingItem();
    newWidget1->setBackgroundColor(QColor(255,255,255));
    newWidget1->setSizeHint(QSize(item->width(),item->height()));
    item1->setNum(2,true);
    item1->setStringOrPic("127%");
    item1->setMusicName("时间轴");
    item1->setMusicAutor("余佳运");
    ui->listCont->insertItem(1,newWidget1);
    ui->listCont->setItemWidget(newWidget1,item1);

    QListWidgetItem * newWidget2 = new QListWidgetItem(ui->listCont);
    RankingItem * item2 = new  RankingItem();
    newWidget2->setBackgroundColor(QColor(249,249,249));
    newWidget2->setSizeHint(QSize(item->width(),item->height()));
    item2->setNum(3,true);
    item2->setStringOrPic("113%");
    item2->setMusicName("没你也能活下去");
    item2->setMusicAutor("Jony J");
    ui->listCont->insertItem(2,newWidget2);
    ui->listCont->setItemWidget(newWidget2,item2);

    QListWidgetItem * newWidget3 = new QListWidgetItem(ui->listCont);
    RankingItem * item3 = new  RankingItem();
    newWidget3->setBackgroundColor(QColor(255,255,255));
    newWidget3->setSizeHint(QSize(item->width(),item->height()));
    item3->setNum(4,false);
    item3->setStringOrPic("111%");
    item3->setMusicName("都不懂");
    item3->setMusicAutor("吉法师");
    ui->listCont->insertItem(3,newWidget3);
    ui->listCont->setItemWidget(newWidget3,item3);


    QListWidgetItem * newWidget4 = new QListWidgetItem(ui->listCont);
    RankingItem * item4 = new  RankingItem();
    newWidget4->setBackgroundColor(QColor(249,249,249));
    newWidget4->setSizeHint(QSize(item->width(),item->height()));
    item4->setNum(5,false);
    item4->setStringOrPic("88%");
    item4->setMusicName("透明轨迹");
    item4->setMusicAutor("ICY");
    ui->listCont->insertItem(4,newWidget4);
    ui->listCont->setItemWidget(newWidget4,item4);
    //设置第一个选中
    ui->listCont->setCurrentRow(0);

}

void AllMain::setRankNew()
{
    QListWidgetItem * newWidget = new QListWidgetItem(ui->listCont2);
    RankingItem * item = new  RankingItem();
    newWidget->setBackgroundColor(QColor(249,249,249));
    newWidget->setSizeHint(QSize(item->width(),item->height()));
    item->setNum(1,true);
    item->setStringOrPic(0);
    item->setMusicName("删了吧");
    item->setMusicAutor("烟(许佳豪)");
    ui->listCont2->insertItem(0,newWidget);
    ui->listCont2->setItemWidget(newWidget,item);

    //
    QListWidgetItem * newWidget1 = new QListWidgetItem(ui->listCont2);
    RankingItem * item1 = new  RankingItem();
    newWidget1->setBackgroundColor(QColor(255,255,255));
    newWidget1->setSizeHint(QSize(item->width(),item->height()));
    item1->setNum(2,true);
    item1->setStringOrPic(1);
    item1->setMusicName("时间轴");
    item1->setMusicAutor("余佳运");
    ui->listCont2->insertItem(1,newWidget1);
    ui->listCont2->setItemWidget(newWidget1,item1);

    QListWidgetItem * newWidget2 = new QListWidgetItem(ui->listCont2);
    RankingItem * item2 = new  RankingItem();
    newWidget2->setBackgroundColor(QColor(249,249,249));
    newWidget2->setSizeHint(QSize(item->width(),item->height()));
    item2->setNum(3,true);
    item2->setStringOrPic(2);
    item2->setMusicName("没你也能活下去");
    item2->setMusicAutor("Jony J");
    ui->listCont2->insertItem(2,newWidget2);
    ui->listCont2->setItemWidget(newWidget2,item2);

    QListWidgetItem * newWidget3 = new QListWidgetItem(ui->listCont2);
    RankingItem * item3 = new  RankingItem();
    newWidget3->setBackgroundColor(QColor(255,255,255));
    newWidget3->setSizeHint(QSize(item->width(),item->height()));
    item3->setNum(4,false);
    item3->setStringOrPic(2);
    item3->setMusicName("都不懂");
    item3->setMusicAutor("吉法师");
    ui->listCont2->insertItem(3,newWidget3);
    ui->listCont2->setItemWidget(newWidget3,item3);


    QListWidgetItem * newWidget4 = new QListWidgetItem(ui->listCont2);
    RankingItem * item4 = new  RankingItem();
    newWidget4->setBackgroundColor(QColor(249,249,249));
    newWidget4->setSizeHint(QSize(item->width(),item->height()));
    item4->setNum(5,false);
    item4->setStringOrPic(2);
    item4->setMusicName("透明轨迹");
    item4->setMusicAutor("ICY");
    ui->listCont2->insertItem(4,newWidget4);
    ui->listCont2->setItemWidget(newWidget4,item4);
    //设置第一个选中
    ui->listCont2->setCurrentRow(0);
}

void AllMain::setSingerLaug()
{
    pButtonLaug = new QButtonGroup(this);
    pButtonLaug->addButton(ui->ptnAll1,0);
    pButtonLaug->addButton(ui->ptnChinese,1);
    pButtonLaug->addButton(ui->ptnEurope,2);
    pButtonLaug->addButton(ui->ptnJapan,3);
    pButtonLaug->addButton(ui->ptnKorea,4);
    pButtonLaug->addButton(ui->ptnOther1,5);
    pButtonLaug->setExclusive(true);
    pButtonLaug->button(0)->setChecked(true);

    connect(pButtonLaug, QOverload<int>::of(&QButtonGroup::buttonClicked),
          [=](int id){
          setSingerSourLaug(id);
    });

}

void AllMain::setSingerSourLaug(int id)
{
    //这里可以加载对应图片
    switch (id) {

    default:
        break;
    }
}

void AllMain::setSingerClass()
{
    pButtonClass = new QButtonGroup(this);
    pButtonClass->addButton(ui->ptnAll2,0);
    pButtonClass->addButton(ui->ptnMan,1);
    pButtonClass->addButton(ui->ptnWomen,2);
    pButtonClass->addButton(ui->ptnBank,3);
    pButtonClass->setExclusive(true);
    pButtonClass->button(0)->setChecked(true);

    connect(pButtonClass, QOverload<int>::of(&QButtonGroup::buttonClicked),
          [=](int id){
          setSingerSourClass(id);
    });
}

void AllMain::setSingerSourClass(int id)
{
    //这里可以加载对应图片
    //这里省略一下
    switch (id) {

    default:
        break;
    }

}

void AllMain::setSingerScreen()
{
    pButtonScreen = new QButtonGroup(this);
    pButtonScreen->addButton(ui->ptnhot,0);
    pButtonScreen->addButton(ui->ptnA,1);
    pButtonScreen->addButton(ui->ptnB,2);
    pButtonScreen->addButton(ui->ptnC,3);
    pButtonScreen->addButton(ui->ptnD,4);
    pButtonScreen->addButton(ui->ptnE,5);
    pButtonScreen->addButton(ui->ptnF,6);
    pButtonScreen->addButton(ui->ptnG,7);
    pButtonScreen->addButton(ui->ptnH,8);
    pButtonScreen->addButton(ui->ptnI,9);
    pButtonScreen->addButton(ui->ptnJ,10);
    pButtonScreen->addButton(ui->ptnK,11);
    pButtonScreen->addButton(ui->ptnL,12);
    pButtonScreen->addButton(ui->ptnM,13);
    pButtonScreen->addButton(ui->ptnN,14);
    pButtonScreen->addButton(ui->ptnO,15);
    pButtonScreen->addButton(ui->ptnP,16);
    pButtonScreen->addButton(ui->ptnQ,17);
    pButtonScreen->addButton(ui->ptnR,18);
    pButtonScreen->addButton(ui->ptnS,19);
    pButtonScreen->addButton(ui->ptnT,20);
    pButtonScreen->addButton(ui->ptnU,21);
    pButtonScreen->addButton(ui->ptnV,22);
    pButtonScreen->addButton(ui->ptnW,23);
    pButtonScreen->addButton(ui->ptnX,24);
    pButtonScreen->addButton(ui->ptnY,25);
    pButtonScreen->addButton(ui->ptnZ,26);
    pButtonScreen->addButton(ui->ptnOH,27);
    pButtonScreen->setExclusive(true);
    pButtonScreen->button(0)->setChecked(true);

    connect(pButtonScreen, QOverload<int>::of(&QButtonGroup::buttonClicked),
          [=](int id){
          setSingerSourScreen(id);
    });

}

void AllMain::setSingerSourScreen(int id)
{
    //这里可以加载对应图片
    switch (id) {

    default:
        break;
    }

}

void AllMain::setNewMusicButton()
{
    ui->widNewMus->setGeometry(280,10,232,32);
    ui->widNewMus->setStyleSheet("QWidget#widNewMus{background:rgb(255,255,255);border:1px solid rgb(187,187,187);border-radius:16px;}");
    ui->ptnNew->setParent(ui->widNewMus);
    ui->ptnNew->setGeometry(0,1,115,30);
    ui->ptnNew->move(1,1);
    ui->ptnNew->setCheckable(true);
    ui->ptnNew2->setParent(ui->widNewMus);
    ui->ptnNew2->setGeometry(ui->ptnNew->width()+2,1,115,30);
    ui->ptnNew2->move(ui->ptnNew->width()+1,1);
    ui->ptnNew2->setCheckable(true);
    ui->ptnNew->setStyleSheet("QPushButton{color:rgb(55,55,55);border:0px;background:rgb(255,255,255);border-radius:14px;}"
                            "QPushButton:hover{border:0px;background:rgb(244,244,244);border-radius:14px;}"
                            "QPushButton:checked{color:rgb(255,255,255);border:0px;background:rgb(187,187,187);border-radius:14px;}");
    ui->ptnNew2->setStyleSheet("QPushButton{color:rgb(55,55,55);border:0px;background:rgb(255,255,255);border-radius:14px;}"
                            "QPushButton:hover{border:0px;background:rgb(244,244,244);border-radius:14px;}"
                            "QPushButton:checked{color:rgb(255,255,255);border:0px;background:rgb(187,187,187);border-radius:14px;}");
    QButtonGroup * btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->ptnNew,0);
    btnGroup->addButton(ui->ptnNew2,1);
    btnGroup->setExclusive(true);
    btnGroup->button(0)->setChecked(true);

    //连接槽
    connect(btnGroup, QOverload<int>::of(&QButtonGroup::buttonClicked),
          [=](int id){
          //这里处理对应界面
        setShowWidget(id);
    });
}

void AllMain::setShowWidget(int id)
{
    currentFlog = id;
    changeChose();

}

void AllMain::setNewMusicChooseButton()
{
    QButtonGroup * btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->ptnMusAll,0);
    btnGroup->addButton(ui->ptnMusChinese,1);
    btnGroup->addButton(ui->ptnMusEurope,2);
    btnGroup->addButton(ui->ptnMusKorea,3);
    btnGroup->addButton(ui->ptnMusJapan,4);
    btnGroup->setExclusive(true);
    btnGroup->button(0)->setChecked(true);

    //连接槽
    connect(btnGroup, QOverload<int>::of(&QButtonGroup::buttonClicked),
          [=](int id){
          //这里处理对应界面
          setLanguageChose(id);
    });

}

void AllMain::setAddWidget()
{
   pCourier = new NewCourier;
   pDisMusic = new NewDisc;
   stackedLayout = new QStackedLayout;
   stackedLayout->addWidget(pCourier);
   stackedLayout->addWidget(pDisMusic);
   pCourier->move(0,0);
   ui->verAddWidget->addLayout(stackedLayout);
   stackedLayout->setCurrentIndex(0);

}

void AllMain::setLanguageChose(int id)
{
    currentClass = id;
    changeChose();
}

void AllMain::changeChose()
{
    if(currentFlog == 0)
    {
       pCourier->setChose(currentClass);
       stackedLayout->setCurrentIndex(0);
    }
    else if (currentFlog == 1) {
       pDisMusic->setChose(currentClass);
       stackedLayout->setCurrentIndex(1);
    }
}

void AllMain::setMusicLeft()
{
    MusicForm *musicForm = new MusicForm();
    musicForm->setMusicName("能解答一切的答案");
    musicForm->setMusicAuthor("周深");
    musicForm->setMusicPicture("./images/Messageform/pic.png");
    ui->verticalLayout->addWidget(musicForm);
}

void AllMain::setMusicList()
{
    player = new QMediaPlayer(this);//
    playlist = new QMediaPlaylist(this);//
    playlist->setPlaybackMode(QMediaPlaylist::Loop); //循环模式
    player->setPlaylist(playlist);
    connect(player,&QMediaPlayer::positionChanged,[=](qint64 duration){
            if(ui->horizontalSlider_music->isSliderDown())
            {
                return ;
            }
            ui->horizontalSlider_music->blockSignals(true);
            ui->horizontalSlider_music->setSliderPosition(int(duration));
            ui->horizontalSlider_music->blockSignals(false);
            int secs = int(duration)/1000;
            int min = secs/60; //取整
            secs = secs%60; //剩余秒
            positionTime=QString::asprintf("%d:%d",min,secs);
            ui->label_time->setText(positionTime);
    });

    connect(player,&QMediaPlayer::durationChanged,[=](qint64 duration){
             ui->horizontalSlider_music->setMaximum(int(duration));
             int secs = int(duration)/1000;
             int min = secs/60; //取整
             secs = secs%60; //剩余秒
             durationTime = QString::asprintf("%d:%d",min,secs);
             ui->label_time_long->setText(durationTime);
    });

    //加载音乐
     playlist->addMedia(QUrl::fromLocalFile("./music/music.mp3"));//添加文件
     playlist->setCurrentIndex(0);

}

void AllMain::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter_mainback(this);
    painter_mainback.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/mianwindow/images/mainback.png"));
    ui->pushButton_people->setMask(QRegion(0,0,28,28,QRegion::Ellipse));
}

void AllMain::mousePressEvent(QMouseEvent *event)
{
    //获取title widget 的高度，这里固定为60px
    int titleHeight = ui->title_Widget->height();
    if(event->y() <titleHeight)
    {
        last = event->globalPos(); //获取到按压的位置
    }
}

void AllMain::mouseMoveEvent(QMouseEvent *event)
{
    int titleHeight = ui->title_Widget->height();
    if(event->y() <titleHeight)
    {
        int dx = event->globalX() - last.x();
        int dy = event->globalY() - last.y();
        last = event->globalPos();
        this->move(this->x()+dx,this->y()+dy);
    }

}

void AllMain::mouseReleaseEvent(QMouseEvent *event)
{
    int titleHeight = ui->title_Widget->height();
    if(event->y() <titleHeight)
    {
        int dx = event->globalX() - last.x();
        int dy = event->globalY() - last.y();
        this->move(this->x()+dx,this->y()+dy);
    }
}

bool AllMain::eventFilter(QObject *watched, QEvent *event)
{
    //当点击查询按钮
    if(watched == ui->line_Search)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {

            int x = ui->line_Search->x();
            int y = ui->line_Search->y();
            int hight = ui->line_Search->height();
            searchForm->setGeometry(x-45,y+hight+2,searchForm->width(),searchForm->height());
            searchForm->show();
            return true;
        }
        else {
            return false;
        }

    }
    else if (watched == searchForm)
    {
        //当鼠标离开时候，界面隐藏
        if(event->type() == QEvent::Leave)
        {
            searchForm->hide();
            return true;
        }
        else {
            return false;
        }

    }

    return QWidget::eventFilter(watched,event);
}

void AllMain::on_pushButton_close_clicked()
{
    this->close();
}

void AllMain::on_pushButton_name_clicked()
{
    if(p_person)
    {
        if(p_person->isHidden())
        {
            p_person->show();
        }
        else {
            p_person->hide();
        }

    }
    else {
        p_person = new personForm(this);
        p_person->setGeometry(538,55,290,400); //这里要调整好
        p_person->raise();  //提示显示层数
        p_person->show();
    }
}

void AllMain::on_pushButton_min_clicked()
{
    this->showMinimized(); //最小化
}

/*专属定制中的按钮*/
void AllMain::on_btnPerL_clicked()
{
    int num = gallerPrivate->getPreviousItemIndex();
    gallerPrivate->showImage(num);
}

void AllMain::on_btnPerR_clicked()
{
    int num =gallerPrivate->getNextItemIndex();
    gallerPrivate->showImage(num);
}

void AllMain::on_pushButton_cloth_clicked()
{
    if(changeColor)
    {
        if(changeColor->isHidden())
        {
            changeColor->show();
        }
        else {
            changeColor->hide();
        }

    }
    else {
        changeColor = new ChangeColorForm(this);
        changeColor->setGeometry(578,60,409,317); //这里要调整好
        changeColor->raise();  //提示显示层数
        changeColor->show();
    }


}


/*消息框*/
void AllMain::on_pushButton_message_clicked()
{
    if(pMessageForm)
    {
        if(pMessageForm->isHidden())
        {
            pMessageForm->show();
        }
        else {
            pMessageForm->hide();
        }

    }
    else {
        pMessageForm = new MessageForm(this);
        pMessageForm->setMouseTracking(true);
        pMessageForm->setGeometry(630,60,365,565); //这里要调整好
        pMessageForm->raise();  //提示显示层数
        pMessageForm->show();
    }

}



void AllMain::on_horizontalSlider_music_valueChanged(int value)
{
    player->blockSignals(true);
    player->setPosition(value);
    player->blockSignals(false);
}

void AllMain::on_pushButton_stop_clicked(bool checked)
{
    if(checked)
    {
        player->play();
        this->setWindowTitle("能解答一切的答案");
    }
    else {
        player->pause();
    }
}
