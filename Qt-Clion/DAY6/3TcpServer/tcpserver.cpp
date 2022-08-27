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
        //主逻辑
        //获取客户端连接上来的套接字
        mSocket = mServer->nextPendingConnection();
        /*
         *  nextPendingConnection()
            返回下一个挂起的连接作为已连接的QTcpSocket对象。

            套接字是作为服务器的一个子创建的，这意味着当QTcpServer对象被销毁时，它将被自动删除。在使用完对象后显式地删除它仍然是一个好主意，以避免浪费内存。

            如果在没有挂起的连接时调用此函数，则返回Nullptr。

            注意:返回的QTcpSocket对象不能从其他线程使用。如果您想使用来自另一个线程的传入连接，您需要覆盖incomingConnection()。

            参见hasPendingConnections()。
        */
        //打印客户端的地址
        QHostAddress c_addr = mSocket->peerAddress();
        /*
         mSocket->peerAddress();
        如果套接字处于ConnectedState状态，返回连接的对等体的地址;否则返回QHostAddress::零。
        */
        qDebug()<<c_addr.toString()<<"连接上来!";

        //使能发送输入框和按钮
        ui->lineEdit->setEnabled(true);
        ui->pushButton_send->setEnabled(true);

        //连接readyRead信号和槽
        QObject::connect(mSocket,&QTcpSocket::readyRead,this,[&](){
            /*
            每当可以从设备的当前读取通道读取新数据时，就会发出此信号。只有当有新的数据可用时，它才会再次发出，例如当网络数据的新负载到达您的网络套接字时，或者当一个新的数据块被附加到您的设备时。

            readyRead()不是递归触发的;如果你重新进入事件循环或在连接到readyRead()信号的槽内调用waitForReadyRead()，信号将不会重新发出(尽管waitForReadyRead()仍然可能返回true)。

            对于实现从QIODevice派生类的开发人员注意:当新数据到达时，应该总是发出readyRead()(不要仅仅因为缓冲区中还有数据有待读取而发出它)。在其他情况下不要触发readyRead()。

             */
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

    //***********************************************
    //连接回车发送的信号和槽（按键）信号连信号
    QObject::connect(ui->lineEdit,&QLineEdit::returnPressed,this,&TcpServer::on_pushButton_send_clicked);
    //***********************************************
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
    arr.append(str);//追加

    //发送
    mSocket->write(arr);
    //显示发送的内容
    ui->textBrowser->insertPlainText("send:"+str+"\n");
    //情况lineEdit
    ui->lineEdit->clear();
}
