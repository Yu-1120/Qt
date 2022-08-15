#include "udpcilent.h"
#include "ui_udpcilent.h"

UdpCilent::UdpCilent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UdpCilent)
{
    //1.创建QUdpSocket
    mSocket = new QUdpSocket(this);
    //2.通信(接收)
    QObject::connect(mSocket,&QUdpSocket::readyRead,this,[&](){
        QHostAddress addr;
        quint16 port;

        //数据缓冲区
        QByteArray arr;
        //调整缓冲区的大小和收到的数据大小一致
        arr.resize(mSocket->bytesAvailable());

        //接收数据
        mSocket->readDatagram(arr.data(),arr.size(),&addr,&port);
        //显示
        ui->textBrowser->insertPlainText(addr.toString()+":"+QString(arr)+"\n");
    });

    ui->setupUi(this);

    //连接回车发送的信号和槽
    QObject::connect(ui->lineEdit_send,&QLineEdit::returnPressed,this,&UdpCilent::on_pushButton_send_clicked);

}

UdpCilent::~UdpCilent()
{
    delete ui;
}

//发送
void UdpCilent::on_pushButton_send_clicked()
{
    //获取发送的数据
    QByteArray arr = ui->lineEdit_send->text().toUtf8();

    //发送
    mSocket->writeDatagram(arr,QHostAddress(ui->lineEdit_ip->text()),ui->spinBox->value());
    //显示发送的内容
    ui->textBrowser->insertPlainText("send:"+QString(arr)+"\n");
    //情况lineEdit
    ui->lineEdit_send->clear();
}
