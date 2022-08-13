#include "udpserver.h"
#include "ui_udpserver.h"

UdpServer::UdpServer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UdpServer)
{
    ui->setupUi(this);
}

UdpServer::~UdpServer()
{
    delete ui;
}

//启动
void UdpServer::on_pushButton_start_clicked()
{
    //1.创建QUdpSocket对象
    mSocket = new QUdpSocket(this);

    //2.连接接收数据信号和槽
    QObject::connect(mSocket,&QUdpSocket::readyRead,this,[&](){
        //数据缓冲区
        QByteArray arr;
        //调整缓冲区的大小和收到的数据大小一致
        arr.resize(mSocket->bytesAvailable());

        //接收数据
        mSocket->readDatagram(arr.data(),arr.size(),&addr,&port);
        //显示
        ui->textBrowser->insertPlainText(addr.toString()+":"+QString(arr)+"\n");

        //使能发送按钮和编辑框
        ui->lineEdit->setEnabled(true);
        ui->pushButton_send->setEnabled(true);
    });

    //3.绑定
    mSocket->bind(QHostAddress::Any,ui->spinBox->value());

    //连接回车发送的信号和槽
    QObject::connect(ui->lineEdit,&QLineEdit::returnPressed,this,&UdpServer::on_pushButton_send_clicked);

    //禁止端口号和启动按钮
    ui->spinBox->setEnabled(false);
    ui->pushButton_start->setEnabled(false);
}

void UdpServer::on_pushButton_send_clicked()
{
    //获取发送的数据
    QByteArray arr = ui->lineEdit->text().toUtf8();

    //发送
    mSocket->writeDatagram(arr,addr,port);
    //显示发送的内容
    ui->textBrowser->insertPlainText("send:"+QString(arr)+"\n");
    //情况lineEdit
    ui->lineEdit->clear();
}
