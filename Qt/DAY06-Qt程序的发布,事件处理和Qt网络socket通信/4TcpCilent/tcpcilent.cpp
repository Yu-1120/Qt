#include "tcpcilent.h"
#include "ui_tcpcilent.h"

TcpCilent::TcpCilent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpCilent)
{
    ui->setupUi(this);
}

TcpCilent::~TcpCilent()
{
    delete ui;
}

//连接服务器
void TcpCilent::on_pushButton_start_clicked()
{
    //1.创建QTcpSocket对象
    mSocket = new QTcpSocket(this);
    //2.连接连接成功的信号和槽
    QObject::connect(mSocket,&QTcpSocket::connected,this,[&](){
        //使能发送按钮和发送输入框
        ui->lineEdit_send->setEnabled(true);
        ui->pushButton_send->setEnabled(true);

        //禁止ip 端口号和连接按钮
        ui->lineEdit_ip->setEnabled(false);
        ui->spinBox->setEnabled(false);
        ui->pushButton_start->setEnabled(false);


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


    //3.连接服务器
    QString ip = ui->lineEdit_ip->text();
    quint16 port = ui->spinBox->value();
    mSocket->connectToHost(ip,port);

    //连接回车发送的信号和槽
    QObject::connect(ui->lineEdit_send,&QLineEdit::returnPressed,this,&TcpCilent::on_pushButton_send_clicked);
}

//发送
void TcpCilent::on_pushButton_send_clicked()
{
    //获取发送的数据
    QString str = ui->lineEdit_send->text();
    //转换成QByteArray
    QByteArray arr;
    arr.append(str);

    //发送
    mSocket->write(arr);
    //显示发送的内容
    ui->textBrowser->insertPlainText("send:"+str+"\n");
    //情况lineEdit
    ui->lineEdit_send->clear();
}
