#include "newcourier.h"
#include "ui_newcourier.h"
#include "newcourieritem.h"
NewCourier::NewCourier(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewCourier)
{
    ui->setupUi(this);
    setInitData();
}

NewCourier::~NewCourier()
{
    delete ui;
}

void NewCourier::setInitData()
{
    ui->listAll->clear();
    //
    QListWidgetItem *item = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem = new NewCourierItem();
    nitem->setNum(01); //设置编号
    nitem->setPicture(":/images/NewMusic/01.png");
    nitem->setMusicName("一起向未来");
    nitem->setLogPic();
    nitem->setMusicAuthor("易烊千玺");
    nitem->setMusicAlbum("一起向未来");
    nitem->setMusicTimer("03:19");
    ui->listAll->setItemWidget(item,nitem);

    QListWidgetItem *item2 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem2 = new NewCourierItem();
    nitem2->setNum(02); //设置编号
    nitem2->setPicture(":/images/NewMusic/02.png");
    nitem2->setMusicName("灯牌");
    nitem2->setLogPic();
    nitem2->setMusicAuthor("刘也");
    nitem2->setMusicAlbum("朝圣者");
    nitem2->setMusicTimer("05:20");
    ui->listAll->setItemWidget(item2,nitem2);

    QListWidgetItem *item3 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem3 = new NewCourierItem();
    nitem3->setNum(03); //设置编号
    nitem3->setPicture(":/images/NewMusic/03.png");
    nitem3->setMusicName("漠河舞厅2020");
    nitem3->setLogPic();
    nitem3->setMusicAuthor("柳爽");
    nitem3->setMusicAlbum("漠河舞厅2020");
    nitem3->setMusicTimer("05:04");
    ui->listAll->setItemWidget(item3,nitem3);

    QListWidgetItem *item4 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem4 = new NewCourierItem();
    nitem4->setNum(04); //设置编号
    nitem4->setPicture(":/images/NewMusic/04.png");
    nitem4->setMusicName("B级鲨鱼");
    nitem4->setLogPic();
    nitem4->setMusicAuthor("裴德");
    nitem4->setMusicAlbum("B级鲨鱼");
    nitem4->setMusicTimer("03:51");
    ui->listAll->setItemWidget(item4,nitem4);

    QListWidgetItem *item5 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem5 = new NewCourierItem();
    nitem5->setNum(05); //设置编号
    nitem5->setPicture(":/images/NewMusic/05.png");
    nitem5->setMusicName("春天花会开");
    nitem5->setLogPic();
    nitem5->setMusicAuthor("张杰");
    nitem5->setMusicAlbum("时光音乐会");
    nitem5->setMusicTimer("04:14");
    ui->listAll->setItemWidget(item5,nitem5);
}

void NewCourier::setChose(int id)
{
    switch (id) {
    case 0:
        setInitData();
        break;
    case 1:
        setChinese();
        break;
    case 2:
        setEurope();
        break;
    case 3:
        setKorea();
        break;
    case 4:
        setJapan();
        break;
    }
}

void NewCourier::setChinese()
{
    ui->listAll->clear();
    //
    QListWidgetItem *item = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem = new NewCourierItem();
    nitem->setNum(01); //设置编号
    nitem->setPicture(":/images/NewMusic/06.png");
    nitem->setMusicName("宣言");
    nitem->setLogPic();
    nitem->setMusicAuthor("赵磊");
    nitem->setMusicAlbum("进击之月");
    nitem->setMusicTimer("04:28");
    ui->listAll->setItemWidget(item,nitem);

    QListWidgetItem *item2 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem2 = new NewCourierItem();
    nitem2->setNum(02); //设置编号
    nitem2->setPicture(":/images/NewMusic/01.png");
    nitem2->setMusicName("一起向未来");
    nitem2->setLogPic();
    nitem2->setMusicAuthor("易烊千玺");
    nitem2->setMusicAlbum("一起向未来");
    nitem2->setMusicTimer("03:19");
    ui->listAll->setItemWidget(item2,nitem2);

    QListWidgetItem *item3 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem3 = new NewCourierItem();
    nitem3->setNum(03); //设置编号
    nitem3->setPicture(":/images/NewMusic/03.png");
    nitem3->setMusicName("漠河舞厅2020");
    nitem3->setLogPic();
    nitem3->setMusicAuthor("柳爽");
    nitem3->setMusicAlbum("漠河舞厅2020");
    nitem3->setMusicTimer("05:04");
    ui->listAll->setItemWidget(item3,nitem3);

    QListWidgetItem *item4 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem4 = new NewCourierItem();
    nitem4->setNum(04); //设置编号
    nitem4->setPicture(":/images/NewMusic/04.png");
    nitem4->setMusicName("B级鲨鱼");
    nitem4->setLogPic();
    nitem4->setMusicAuthor("裴德");
    nitem4->setMusicAlbum("B级鲨鱼");
    nitem4->setMusicTimer("03:51");
    ui->listAll->setItemWidget(item4,nitem4);

    QListWidgetItem *item5 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem5 = new NewCourierItem();
    nitem5->setNum(05); //设置编号
    nitem5->setPicture(":/images/NewMusic/05.png");
    nitem5->setMusicName("春天花会开");
    nitem5->setLogPic();
    nitem5->setMusicAuthor("张杰");
    nitem5->setMusicAlbum("时光音乐会");
    nitem5->setMusicTimer("04:14");
    ui->listAll->setItemWidget(item5,nitem5);
}

void NewCourier::setEurope()
{
    ui->listAll->clear();
    //
    QListWidgetItem *item = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem = new NewCourierItem();
    nitem->setNum(01); //设置编号
    nitem->setPicture(":/images/NewMusic/07.png");
    nitem->setMusicName("Fay As Me");
    nitem->setLogPic();
    nitem->setMusicAuthor("Bruno Mars");
    nitem->setMusicAlbum("An Evening With Silk Sonic");
    nitem->setMusicTimer("03:39");
    ui->listAll->setItemWidget(item,nitem);

    QListWidgetItem *item2 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem2 = new NewCourierItem();
    nitem2->setNum(02); //设置编号
    nitem2->setPicture(":/images/NewMusic/08.png");
    nitem2->setMusicName("Already Dead");
    nitem2->setLogPic();
    nitem2->setMusicAuthor("Juice WRLD");
    nitem2->setMusicAlbum("Already Dead");
    nitem2->setMusicTimer("03:51");
    ui->listAll->setItemWidget(item2,nitem2);

    QListWidgetItem *item3 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem3 = new NewCourierItem();
    nitem3->setNum(03); //设置编号
    nitem3->setPicture(":/images/NewMusic/09.png");
    nitem3->setMusicName("Be Alive");
    nitem3->setLogPic();
    nitem3->setMusicAuthor("Beyonce");
    nitem3->setMusicAlbum("Be Alive");
    nitem3->setMusicTimer("03:40");
    ui->listAll->setItemWidget(item3,nitem3);

    QListWidgetItem *item4 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem4 = new NewCourierItem();
    nitem4->setNum(04); //设置编号
    nitem4->setPicture(":/images/NewMusic/10.png");
    nitem4->setMusicName("Bite Me");
    nitem4->setLogPic();
    nitem4->setMusicAuthor("Avril Lavigne");
    nitem4->setMusicAlbum("Bite Me");
    nitem4->setMusicTimer("02:39");
    ui->listAll->setItemWidget(item4,nitem4);

    QListWidgetItem *item5 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem5 = new NewCourierItem();
    nitem5->setNum(05); //设置编号
    nitem5->setPicture(":/images/NewMusic/11.png");
    nitem5->setMusicName("World We Used To Know");
    nitem5->setLogPic();
    nitem5->setMusicAuthor("Alan");
    nitem5->setMusicAlbum("World We Used To Know");
    nitem5->setMusicTimer("04:14");
    ui->listAll->setItemWidget(item5,nitem5);
}

void NewCourier::setKorea()
{
    ui->listAll->clear();
    //
    QListWidgetItem *item = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem = new NewCourierItem();
    nitem->setNum(01); //设置编号
    nitem->setPicture(":/images/NewMusic/12.png");
    nitem->setMusicName("거대한 말");
    nitem->setLogPic();
    nitem->setMusicAuthor("B1A4");
    nitem->setMusicAlbum("거대한 말");
    nitem->setMusicTimer("03:56");
    ui->listAll->setItemWidget(item,nitem);

    QListWidgetItem *item2 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem2 = new NewCourierItem();
    nitem2->setNum(02); //设置编号
    nitem2->setPicture(":/images/NewMusic/13.png");
    nitem2->setMusicName("SNAPSHOT");
    nitem2->setLogPic();
    nitem2->setMusicAuthor("jessica");
    nitem2->setMusicAlbum("제시카 & 크리스탈 - US로드");
    nitem2->setMusicTimer("03:10");
    ui->listAll->setItemWidget(item2,nitem2);

    QListWidgetItem *item3 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem3 = new NewCourierItem();
    nitem3->setNum(03); //设置编号
    nitem3->setPicture(":/images/NewMusic/14.png");
    nitem3->setMusicName("DAYDREAM");
    nitem3->setLogPic();
    nitem3->setMusicAuthor("jessica");
    nitem3->setMusicAlbum("제시카 & 크리스탈 - US로드");
    nitem3->setMusicTimer("05:04");
    ui->listAll->setItemWidget(item3,nitem3);

    QListWidgetItem *item4 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem4 = new NewCourierItem();
    nitem4->setNum(04); //设置编号
    nitem4->setPicture(":/images/NewMusic/15.png");
    nitem4->setMusicName("같은 곳을 향해가");
    nitem4->setLogPic();
    nitem4->setMusicAuthor("유지현 김상지");
    nitem4->setMusicAlbum("같은 곳을 향해가");
    nitem4->setMusicTimer("03:51");
    ui->listAll->setItemWidget(item4,nitem4);

    QListWidgetItem *item5 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem5 = new NewCourierItem();
    nitem5->setNum(05); //设置编号
    nitem5->setPicture(":/images/NewMusic/16.png");
    nitem5->setMusicName("9号线少女");
    nitem5->setLogPic();
    nitem5->setMusicAuthor("Yourbeagle");
    nitem5->setMusicAlbum("9号线少女");
    nitem5->setMusicTimer("03:00");
    ui->listAll->setItemWidget(item5,nitem5);
}

void NewCourier::setJapan()
{
    ui->listAll->clear();
    //
    QListWidgetItem *item = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem = new NewCourierItem();
    nitem->setNum(01); //设置编号
    nitem->setPicture(":/images/NewMusic/17.png");
    nitem->setMusicName("MAKAFUKA");
    nitem->setLogPic();
    nitem->setMusicAuthor("RADWIMPS");
    nitem->setMusicAlbum("FOREVER DAZE");
    nitem->setMusicTimer("05:31");
    ui->listAll->setItemWidget(item,nitem);

    QListWidgetItem *item2 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem2 = new NewCourierItem();
    nitem2->setNum(02); //设置编号
    nitem2->setPicture(":/images/NewMusic/18.png");
    nitem2->setMusicName("Chopstick");
    nitem2->setLogPic();
    nitem2->setMusicAuthor("Niziu");
    nitem2->setMusicAlbum("Chopstick");
    nitem2->setMusicTimer("02:57");
    ui->listAll->setItemWidget(item2,nitem2);

    QListWidgetItem *item3 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem3 = new NewCourierItem();
    nitem3->setNum(03); //设置编号
    nitem3->setPicture(":/images/NewMusic/19.png");
    nitem3->setMusicName("ラストシーン");
    nitem3->setLogPic();
    nitem3->setMusicAuthor("菅田将暉");
    nitem3->setMusicAlbum("ラストシーン");
    nitem3->setMusicTimer("04:29");
    ui->listAll->setItemWidget(item3,nitem3);

    QListWidgetItem *item4 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem4 = new NewCourierItem();
    nitem4->setNum(04); //设置编号
    nitem4->setPicture(":/images/NewMusic/20.png");
    nitem4->setMusicName("starting over");
    nitem4->setLogPic();
    nitem4->setMusicAuthor("三代目");
    nitem4->setMusicAlbum("BEST BROTHERS");
    nitem4->setMusicTimer("04:20");
    ui->listAll->setItemWidget(item4,nitem4);

    QListWidgetItem *item5 = new QListWidgetItem(ui->listAll);
    NewCourierItem * nitem5 = new NewCourierItem();
    nitem5->setNum(05); //设置编号
    nitem5->setPicture(":/images/NewMusic/21.png");
    nitem5->setMusicName("Ito");
    nitem5->setLogPic();
    nitem5->setMusicAuthor("TOMORROW X");
    nitem5->setMusicAlbum("Chaotic");
    nitem5->setMusicTimer("04:30");
    ui->listAll->setItemWidget(item5,nitem5);
}
