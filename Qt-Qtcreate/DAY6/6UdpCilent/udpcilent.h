#ifndef UDPCILENT_H
#define UDPCILENT_H

#include <QWidget>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
namespace Ui { class UdpCilent; }
QT_END_NAMESPACE

class UdpCilent : public QWidget
{
    Q_OBJECT

public:
    UdpCilent(QWidget *parent = nullptr);
    ~UdpCilent();

private slots:
    void on_pushButton_send_clicked();

private:
    Ui::UdpCilent *ui;
    //UDP客户端
    QUdpSocket *mSocket;
};
#endif // UDPCILENT_H
