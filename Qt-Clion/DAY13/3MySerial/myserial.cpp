#include "myserial.h"
#include "ui_myserial.h"
#include <QDebug>
#include <QMessageBox>

MySerial::MySerial(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MySerial)
{
    ui->setupUi(this);

    //获取系统的有效串口
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts()){
        qDebug()<<info.portName()<<info.description();
        //ui->comboBox_port->addItem(info.portName());
        //测试串口是否空闲
        QSerialPort serial(info);
        if(serial.open(QIODevice::ReadWrite)){//空闲
            ui->comboBox_port->addItem(info.portName());
            //关闭串口
            serial.close();
        }
        else{//被占用
            ui->comboBox_port->addItem(info.portName()+"(被占用)");
        }
    }
}

MySerial::~MySerial()
{
    delete ui;
}

//打开串口
void MySerial::on_pushButton_open_clicked()
{
    if(ui->pushButton_open->text()=="打 开 串 口"){
        ser = new QSerialPort(ui->comboBox_port->currentText());
        //打开串口
        if(!ser->open(QIODevice::ReadWrite)){
            QMessageBox::warning(this,"提示","打开串口失败!");
            ser->deleteLater();
            return;
        }

        //设置波特率
        switch(ui->comboBox_baudrate->currentIndex()){
            case 0:
                ser->setBaudRate(QSerialPort::Baud115200);
                break;
            case 1:
                ser->setBaudRate(QSerialPort::Baud2400);
                break;
            case 2:
                ser->setBaudRate(QSerialPort::Baud4800);
                break;
            case 3:
                ser->setBaudRate(QSerialPort::Baud9600);
                break;
            case 4:
                ser->setBaudRate(QSerialPort::Baud38400);
                break;
        }

        //设置数据位位数
        switch(ui->comboBox_databits->currentIndex()){
            case 0:
                ser->setDataBits(QSerialPort::Data8);
                break;
            case 1:
                ser->setDataBits(QSerialPort::Data5);
                break;
            case 2:
                ser->setDataBits(QSerialPort::Data6);
                break;
            case 3:
                ser->setDataBits(QSerialPort::Data7);
                break;
        }

        //设置校验方式
        switch(ui->comboBox_parity->currentIndex()){
            case 0:
                ser->setParity(QSerialPort::NoParity);
                break;
            case 1:
                ser->setParity(QSerialPort::OddParity);
                break;
            case 2:
                ser->setParity(QSerialPort::EvenParity);
                break;
        }

        //设置停止位位数
        switch(ui->comboBox_stopbits->currentIndex()){
            case 0:
                ser->setStopBits(QSerialPort::OneStop);
                break;
            case 1:
                ser->setStopBits(QSerialPort::OneAndHalfStop);
                break;
            case 2:
                ser->setStopBits(QSerialPort::TwoStop);
                break;
        }

        //关闭流控
        ser->setFlowControl(QSerialPort::NoFlowControl);

        //禁止和使能控件
        ui->comboBox_port->setEnabled(false);
        ui->comboBox_baudrate->setEnabled(false);
        ui->comboBox_databits->setEnabled(false);
        ui->comboBox_parity->setEnabled(false);
        ui->comboBox_stopbits->setEnabled(false);
        ui->pushButton_send->setEnabled(true);

        //连接收到数据的信号和槽
        QObject::connect(ser,&QSerialPort::readyRead,this,[&](){
            //接收所有数据并显示
            QByteArray arr = ser->readAll();

            if(!arr.isEmpty())
                ui->textBrowser->append(arr);
        });

        //修改按键显示
        ui->pushButton_open->setText("关 闭 串 口");
    }
    else{//关闭串口
        ser->clear();
        ser->close();
        ser->deleteLater();

        //禁止和使能控件
        ui->comboBox_port->setEnabled(true);
        ui->comboBox_baudrate->setEnabled(true);
        ui->comboBox_databits->setEnabled(true);
        ui->comboBox_parity->setEnabled(true);
        ui->comboBox_stopbits->setEnabled(true);
        ui->pushButton_send->setEnabled(false);

        //修改按键显示
        ui->pushButton_open->setText("打 开 串 口");
    }
}

void MySerial::on_pushButton_send_clicked()
{
    //获取要发送的数据
    QByteArray arr = ui->textEdit->toPlainText().toUtf8();
    //发送
    ser->write(arr);
}
