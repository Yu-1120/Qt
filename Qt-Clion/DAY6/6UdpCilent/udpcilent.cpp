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
         //重构:QIODevice:: bytesAvailable()常量。

//        返回等待读取的传入字节数。
        //接收数据
        mSocket->readDatagram(arr.data(),arr.size(),&addr,&port);
        /*
         * qint64 QUdpSocket::readDatagram(char *data, qint64 maxSize, QHostAddress *address = nullptr, quint16 *port = nullptr)
         *
            接收不大于maxSize字节的数据报，并将其存储在数据中。
            发送方的主机地址和端口存储在*address和*port中(除非指针是0)。

            成功返回数据报的大小;否则返回1。

            如果maxSize太小，则数据报的其余部分将丢失。为了避免数据丢失，在试图读取挂起的数据报之前，调用pendingDatagramSize()来确定它的大小。

           如果maxSize为0，则数据报将被丢弃。
        */
        //显示
        ui->textBrowser->insertPlainText(addr.toString()+":"+QString(arr)+"\n");
    });

    ui->setupUi(this);

    //连接回车发送的信号和槽
    QObject::connect(ui->lineEdit_send,&QLineEdit::returnPressed,this,&UdpCilent::on_pushButton_send_clicked);
    //不能写在ui上面的
    //udp不基于连接,但是它是带地址的通讯协议

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
