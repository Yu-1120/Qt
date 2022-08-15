#ifndef GETAPPDATA_H
#define GETAPPDATA_H

#include <QWidget>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

QT_BEGIN_NAMESPACE
namespace Ui { class GetAppdata; }
QT_END_NAMESPACE

class GetAppdata : public QWidget
{
    Q_OBJECT

public:
    GetAppdata(QWidget *parent = nullptr);
    ~GetAppdata();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GetAppdata *ui;
    //http管理对象
    QNetworkAccessManager *manager;
};
#endif // GETAPPDATA_H
