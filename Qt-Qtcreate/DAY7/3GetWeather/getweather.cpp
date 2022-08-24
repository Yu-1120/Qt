#include "getweather.h"
#include "ui_getweather.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QMessageBox>
#include <QDebug>

GetWeather::GetWeather(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GetWeather)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);
    //连接请求返回的信号和槽
    QObject::connect(manager,&QNetworkAccessManager::finished,this,[&](QNetworkReply *replay){
        //获取请求返回的数据
        QByteArray arr = replay->readAll();
        //显示
        ui->textBrowser->setText(arr);

        //解析json字符串
        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(arr,&err);
        //判断是否出错
        if(err.error!=QJsonParseError::NoError){
            QMessageBox::warning(this,"错误","Json字符串格式错误!");
            return;
        }

        //将文本对象转换成json对象
        QJsonObject obj = doc.object();
        //在json对象中根据key获取value
        qDebug()<<obj.value("success").toString();//1

        QJsonObject result_obj = obj.value("result").toObject();
//         qDebug()<<result_obj;//
        ///*************************************************
        qDebug()<<result_obj.value("weaid").toString();
        qDebug()<<result_obj.value("cityid").toString();
        qDebug()<<result_obj.value("area_1").toString();
         qDebug()<<result_obj.value("area_2").toString();
        ///*************************************************这样写能解析出卡嵌套但是不美观
         QJsonObject result_obj_realTime = obj.value("result").toObject().value("realTime").toObject();
      ///*************************************************
        qDebug()<<result_obj_realTime.value("wtNm").toString();
        qDebug()<<result_obj_realTime.value("wtTemp").toString();
//        QString str = QString("%1 %2 %3").arg(result_obj.value("citynm").toString())
//                                         .arg(result_obj.value("weather").toString())
//                                         .arg(result_obj.value("temperature").toString());
//        //显示
//        ui->label->setText(str);
    });
}

GetWeather::~GetWeather()
{
    delete ui;
}

/*
http://api.k780.com/?app=weather.realtime&weaid=182&ag=today,futureDay,lifeIndex,futureHour&appkey=67002&sign=fd63a1a2aba2463a46eb07d5217482f2&format=json
*/
    void GetWeather::on_pushButton_clicked()
{
  /*
    (推荐) 通过weaId查询，例: 1
    城市列表城市列表中weaId
    (参数weaId,cityId,cityNm,cityIp,wgs84ll中取1个作为查询条件)

  *///***********************https://www.nowapi.com/*************************/
    QString urlapi ="http://api.k780.com/?app=weather.realtime&cityId=101281901&ag=today,futureDay,lifeIndex,futureHour&appkey=67002&sign=fd63a1a2aba2463a46eb07d5217482f2&format=json";
    //获取url
    QUrl url(urlapi);
//    QUrl url(ui->lineEdit->text());//输入
    //创建http请求
    QNetworkRequest request(url);

    //发送请求
    manager->get(request);
}
