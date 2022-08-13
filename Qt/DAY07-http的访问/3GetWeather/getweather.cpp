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
        qDebug()<<obj.value("success").toString();

        QJsonObject result_obj = obj.value("result").toObject();
        qDebug()<<result_obj.value("weather").toString();//天气
        qDebug()<<result_obj.value("temperature").toString();//温度
        QString str = QString("%1 %2 %3").arg(result_obj.value("citynm").toString())
                                         .arg(result_obj.value("weather").toString())
                                         .arg(result_obj.value("temperature").toString());
        //显示
        ui->label->setText(str);
    });
}

GetWeather::~GetWeather()
{
    delete ui;
}


void GetWeather::on_pushButton_clicked()
{
    //获取url
    QUrl url(ui->lineEdit->text());
    //创建http请求
    QNetworkRequest request(url);

    //发送请求
    manager->get(request);
}
