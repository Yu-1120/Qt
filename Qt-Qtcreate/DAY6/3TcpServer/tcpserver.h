#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QWidget>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
namespace Ui { class TcpServer; }
QT_END_NAMESPACE

class TcpServer : public QWidget
{
    Q_OBJECT

public:
    TcpServer(QWidget *parent = nullptr);
    ~TcpServer();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_send_clicked();

private:
    Ui::TcpServer *ui;
    //TCP服务器
    QTcpServer *mServer;
    QTcpSocket *mSocket;
};
#endif // TCPSERVER_H
