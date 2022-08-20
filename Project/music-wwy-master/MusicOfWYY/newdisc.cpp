#include "newdisc.h"
#include "ui_newdisc.h"

NewDisc::NewDisc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewDisc)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setStyleSheet("QWidget{background:transparent; border-radius:8px;}"
                        "QWidget:hover{background:transparent;}");
    setInitData();
}

NewDisc::~NewDisc()
{
    delete ui;
}

void NewDisc::setInitData()
{
    ui->DiscF->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/DiscF.png);}");
    ui->Disc0->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis01.png);}");
    ui->Disc1->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis02.png);}");
    ui->Disc2->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis03.png);}");
    ui->Disc3->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis04.png);}");
    ui->Disc4->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis05.png);}");
    ui->Disc5->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis06.png);}");
    ui->Disc6->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis07.png);}");
    ui->Disc7->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis08.png);}");
    ui->Disc01->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->Disc02->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->Disc03->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->Disc04->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->labName01->setText("进击之月");
    ui->labName01->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu01->setText("赵磊");
    ui->labDiscAu01->setStyleSheet("QLabel{color:rgb(159,159,159);}");
    ui->labName02->setText("一起向未来");
    ui->labName02->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu02->setText("易烊千玺");
    ui->labDiscAu02->setStyleSheet("QLabel{color:rgb(159,159,159);}");
    ui->labName03->setText("All Too Well");
    ui->labName03->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu03->setText("Switf");
    ui->labDiscAu03->setStyleSheet("QLabel{color:rgb(159,159,159);}");
    ui->labName04->setText("B级鲨鱼");
    ui->labName04->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu04->setText("裴德");
    ui->labDiscAu04->setStyleSheet("QLabel{color:rgb(159,159,159);}");
}

void NewDisc::setChose(int id)
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

void NewDisc::setChinese()
{
    ui->DiscF->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/DiscT.png);}");
    ui->Disc0->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis01.png);}");
    ui->Disc1->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis02.png);}");
    ui->Disc2->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis04.png);}");
    ui->Disc3->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis07.png);}");
    ui->Disc4->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis08.png);}");
    ui->Disc5->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis10.png);}");
    ui->Disc6->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis11.png);}");
    ui->Disc7->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis12.png);}");
    ui->Disc01->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->Disc02->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->Disc03->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->Disc04->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->labName01->setText("进击之月");
    ui->labName01->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu01->setText("赵磊");
    ui->labDiscAu01->setStyleSheet("QLabel{color:rgb(159,159,159);}");
    ui->labName02->setText("一起向未来");
    ui->labName02->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu02->setText("易烊千玺");
    ui->labDiscAu02->setStyleSheet("QLabel{color:rgb(159,159,159);}");
    ui->labName03->setText("B级鲨鱼");
    ui->labName03->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu03->setText("裴德");
    ui->labDiscAu03->setStyleSheet("QLabel{color:rgb(159,159,159);}");
    ui->labName04->setText("云");
    ui->labName04->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu04->setText("林鹿言");
    ui->labDiscAu04->setStyleSheet("QLabel{color:rgb(159,159,159);}");
}

void NewDisc::setEurope()
{
    ui->DiscF->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/DiscT.png);}");
    ui->Disc0->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis13.png);}");
    ui->Disc1->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis14.png);}");
    ui->Disc2->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis15.png);}");
    ui->Disc3->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis16.png);}");
    ui->Disc4->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis17.png);}");
    ui->Disc5->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis18.png);}");
    ui->Disc6->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis19.png);}");
    ui->Disc7->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis20.png);}");
    ui->Disc01->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->Disc02->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->Disc03->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->Disc04->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->labName01->setText("Fay As Me");
    ui->labName01->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu01->setText("Bruno Mars");
    ui->labDiscAu01->setStyleSheet("QLabel{color:rgb(159,159,159);}");
    ui->labName02->setText("Already Dead");
    ui->labName02->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu02->setText("Juice WRLD");
    ui->labDiscAu02->setStyleSheet("QLabel{color:rgb(159,159,159);}");
    ui->labName03->setText("All Too Well");
    ui->labName03->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu03->setText("Switf");
    ui->labDiscAu03->setStyleSheet("QLabel{color:rgb(159,159,159);}");
    ui->labName04->setText("Bite Me");
    ui->labName04->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu04->setText("Avril Lavigne");
    ui->labDiscAu04->setStyleSheet("QLabel{color:rgb(159,159,159);}");
}

void NewDisc::setKorea()
{
    ui->DiscF->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/DiscT.png);}");
    ui->Disc0->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis21.png);}");
    ui->Disc1->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis22.png);}");
    ui->Disc2->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis23.png);}");
    ui->Disc3->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis24.png);}");
    ui->Disc4->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis25.png);}");
    ui->Disc5->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis26.png);}");
    ui->Disc6->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis27.png);}");
    ui->Disc7->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis06.png);}");
    ui->Disc01->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->Disc02->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->Disc03->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->Disc04->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->labName01->setText("거대한 말");
    ui->labName01->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu01->setText("B1A4");
    ui->labDiscAu01->setStyleSheet("QLabel{color:rgb(159,159,159);}");
    ui->labName02->setText("SNAPSHOT");
    ui->labName02->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu02->setText("jessica");
    ui->labDiscAu02->setStyleSheet("QLabel{color:rgb(159,159,159);}");
    ui->labName03->setText("DAYDREAM");
    ui->labName03->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu03->setText("jessica");
    ui->labDiscAu03->setStyleSheet("QLabel{color:rgb(159,159,159);}");
    ui->labName04->setText("같은 곳을 향해가");
    ui->labName04->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu04->setText("유지현 김상지");
    ui->labDiscAu04->setStyleSheet("QLabel{color:rgb(159,159,159);}");
}

void NewDisc::setJapan()
{
    ui->DiscF->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/DiscT.png);}");
    ui->Disc0->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis28.png);}");
    ui->Disc1->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis29.png);}");
    ui->Disc2->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis30.png);}");
    ui->Disc3->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis31.png);}");
    ui->Disc4->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis32.png);}");
    ui->Disc5->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis33.png);}");
    ui->Disc6->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis34.png);}");
    ui->Disc7->setStyleSheet("QWidget{border-image:url(:/images/NewMusic/Dis35.png);}");
    ui->Disc01->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->Disc02->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->Disc03->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->Disc04->setStyleSheet("QWidget{background:rgb(255,255,255);}");
    ui->labName01->setText("MAKAFUKA");
    ui->labName01->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu01->setText("RADWIMPS");
    ui->labDiscAu01->setStyleSheet("QLabel{color:rgb(159,159,159);}");
    ui->labName02->setText("Chopstick");
    ui->labName02->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu02->setText("Niziu");
    ui->labDiscAu02->setStyleSheet("QLabel{color:rgb(159,159,159);}");
    ui->labName03->setText("ラストシーン");
    ui->labName03->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu03->setText("菅田将暉");
    ui->labDiscAu03->setStyleSheet("QLabel{color:rgb(159,159,159);}");
    ui->labName04->setText("starting over");
    ui->labName04->setStyleSheet("QLabel{color:rgb(55,55,55);}");
    ui->labDiscAu04->setText("三代目");
    ui->labDiscAu04->setStyleSheet("QLabel{color:rgb(159,159,159);}");
}
