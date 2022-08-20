#ifndef GETWEATHER_H
#define GETWEATHER_H

#include <QWidget>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

QT_BEGIN_NAMESPACE
namespace Ui { class GetWeather; }
QT_END_NAMESPACE

class GetWeather : public QWidget
{
    Q_OBJECT

public:
    GetWeather(QWidget *parent = nullptr);
    ~GetWeather();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GetWeather *ui;
    //http管理对象
    QNetworkAccessManager *manager;
};
#endif // GETWEATHER_H
