#ifndef TCPCILENT_H
#define TCPCILENT_H

#include <QWidget>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
namespace Ui { class TcpCilent; }
QT_END_NAMESPACE

class TcpCilent : public QWidget
{
    Q_OBJECT

public:
    TcpCilent(QWidget *parent = nullptr);
    ~TcpCilent();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_send_clicked();

private:
    Ui::TcpCilent *ui;
    //TCP客户端
    QTcpSocket *mSocket;
};
#endif // TCPCILENT_H
