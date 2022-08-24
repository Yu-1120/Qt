#include "getappdata.h"
#include "ui_getappdata.h"
#include <QUrl>

GetAppdata::GetAppdata(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GetAppdata)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);
    //连接请求返回的信号和槽
    QObject::connect(manager,&QNetworkAccessManager::finished,this,[&](QNetworkReply *replay){
        //获取请求返回的数据
        QByteArray arr = replay->readAll();
        //显示
        ui->textBrowser->setText(arr);
    });
}

GetAppdata::~GetAppdata()
{
    delete ui;
}

//发送请求
void GetAppdata::on_pushButton_clicked()
{
    //获取url
    QUrl url(ui->lineEdit->text());
    //创建http请求
    QNetworkRequest request(url);
    /*
     http://api.k780.com/?app=weather.realtime&weaId=1&ag=today,futureDay,lifeIndex,futureHour&appkey=10003&sign=b59bc3ef6191eb9f747dd4e83c99f2a4&format=jso

    */
    //发送请求
    manager->get(request);
}
