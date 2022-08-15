#ifndef HTTPPIC_H
#define HTTPPIC_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

QT_BEGIN_NAMESPACE
namespace Ui { class HttpPic; }
QT_END_NAMESPACE

class HttpPic : public QWidget
{
    Q_OBJECT

public:
    HttpPic(QWidget *parent = nullptr);
    ~HttpPic();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HttpPic *ui;
    //http管理对象
    QNetworkAccessManager *manager;
};
#endif // HTTPPIC_H
