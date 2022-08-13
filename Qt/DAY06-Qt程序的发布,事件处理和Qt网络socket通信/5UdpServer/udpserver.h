#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QWidget>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
namespace Ui { class UdpServer; }
QT_END_NAMESPACE

class UdpServer : public QWidget
{
    Q_OBJECT

public:
    UdpServer(QWidget *parent = nullptr);
    ~UdpServer();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_send_clicked();

private:
    Ui::UdpServer *ui;
    //Udp服务器
    QUdpSocket *mSocket;
    //通信的ip和端口
    QHostAddress addr;
    quint16 port;
};
#endif // UDPSERVER_H
