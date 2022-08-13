#include "tcpserver.h"
#include "ui_tcpserver.h"
#include <QDebug>

TcpServer::TcpServer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpServer)
{
    ui->setupUi(this);
}

TcpServer::~TcpServer()
{
    delete ui;
}

//启动TCP服务器
void TcpServer::on_pushButton_start_clicked()
{
    //1.构造QTcpServer对象
    mServer = new QTcpServer(this);
    //2.连接客户端连接上来的信号
    QObject::connect(mServer,&QTcpServer::newConnection,this,[&](){
        //获取客户端连接上来的套接字
        mSocket = mServer->nextPendingConnection();
        //打印客户端的地址
        QHostAddress c_addr = mSocket->peerAddress();
        qDebug()<<c_addr.toString()<<"连接上来!";

        //使能发送输入框和按钮
        ui->lineEdit->setEnabled(true);
        ui->pushButton_send->setEnabled(true);

        //连接readyRead信号和槽
        QObject::connect(mSocket,&QTcpSocket::readyRead,this,[&](){
            //接收数据
            QByteArray arr = mSocket->readAll();
            //转换成字符串
            QString str(arr);
            //显示
            ui->textBrowser->insertPlainText("rcv:"+str+"\n");
        });
    });

    //3.监听
    mServer->listen(QHostAddress::Any,ui->spinBox->value());

    //连接回车发送的信号和槽
    QObject::connect(ui->lineEdit,&QLineEdit::returnPressed,this,&TcpServer::on_pushButton_send_clicked);

    //禁止端口号和启动按钮
    ui->spinBox->setEnabled(false);
    ui->pushButton_start->setEnabled(false);
}

void TcpServer::on_pushButton_send_clicked()
{
    //获取发送的数据
    QString str = ui->lineEdit->text();
    //转换成QByteArray
    QByteArray arr;
    arr.append(str);

    //发送
    mSocket->write(arr);
    //显示发送的内容
    ui->textBrowser->insertPlainText("send:"+str+"\n");
    //情况lineEdit
    ui->lineEdit->clear();
}
