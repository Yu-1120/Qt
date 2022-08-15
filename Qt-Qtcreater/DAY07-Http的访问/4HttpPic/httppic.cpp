#include "httppic.h"
#include "ui_httppic.h"

HttpPic::HttpPic(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HttpPic)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);
    //连接请求返回的信号和槽
    QObject::connect(manager,&QNetworkAccessManager::finished,this,[&](QNetworkReply *replay){
        //获取请求返回的数据
        QByteArray arr = replay->readAll();
        //将图片数据放入QPixmap
        QPixmap map;
        map.loadFromData(arr);
        //显示图片
        map = map.scaled(ui->label->size());
        ui->label->setPixmap(map);
    });
}

HttpPic::~HttpPic()
{
    delete ui;
}


void HttpPic::on_pushButton_clicked()
{
    //获取url
    QUrl url(ui->lineEdit->text());
    //创建http请求
    QNetworkRequest request(url);

    //发送请求
    manager->get(request);
}
