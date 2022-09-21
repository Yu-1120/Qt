#include "sericaltest.h"
#include "ui_sericaltest.h"

#include <QDateTime>
#include <QMessageBox>
#include <QTextCodec>

SericalTest::SericalTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SericalTest)
{
//    Qt::WindowFlags ture=Qt::Dialog;
//        ture |=Qt::WindowMinimizeButtonHint;
//        ture |=Qt::WindowMaximizeButtonHint;
//        ture |= Qt::WindowCloseButtonHint;
//        setWindowFlags(ture);

    ui->setupUi(this);
    getWidget();        //获取控件
    initWidget();       //控件初始化
    initSerial();       //串口初始化

}



SericalTest::~SericalTest()
{
    delete ui;
}

void SericalTest::getWidget(){   //获取控件
    btn_OpenSerialPort=ui->btn_OpenSerialPort;   //打开串口按钮
    btn_Send= ui->btn_Send;    //发送按钮
    btn_Clear=ui->btn_Clear;   //清除按钮
    te_Read=ui->te_Read;       //接收text
    te_Send=ui->te_Send;       //发送text

    cbx_Baud=ui->cbx_Baud;    //波特率
    cbx_Parity=ui->cbx_Parity;  //奇偶校验
    cbx_SerialName=ui->cbx_SerialName;  //串口名
    cbx_DataBit=ui->cbx_DataBit;   //数据位
    cbx_StopBit=ui->cbx_StopBit;   //停止位

    cb_SendSuffix =ui->GroupBox_SendSettings->findChild<QCheckBox *>("cb_SendSuffix");
    cb_SendEnterSuffix=ui->GroupBox_SendSettings->findChild<QCheckBox *>("cb_SendEnterSuffix");
    cb_SendSpaceSuffix=ui->GroupBox_SendSettings->findChild<QCheckBox *>("cb_SendSpaceSuffix");
    cb_SendEncoding=ui->GroupBox_SendSettings->findChild<QCheckBox *>("cb_SendEncoding");
    le_SendSuffix=ui->GroupBox_SendSettings->findChild<QLineEdit *>("le_SendSuffix");
    cbx_SendEncoding=ui->GroupBox_SendSettings->findChild<QComboBox *>("cbx_SendEncoding");

    cb_ReadSuffix =ui->GroupBox_ReadSettings->findChild<QCheckBox *>("cb_ReadSuffix");
    cb_ReadEnterSuffix=ui->GroupBox_ReadSettings->findChild<QCheckBox *>("cb_ReadEnterSuffix");
    cb_ReadSpaceSuffix=ui->GroupBox_ReadSettings->findChild<QCheckBox *>("cb_ReadSpaceSuffix");
    cb_ReadEncoding=ui->GroupBox_ReadSettings->findChild<QCheckBox *>("cb_ReadEncoding");
    le_ReadSuffix=ui->GroupBox_ReadSettings->findChild<QLineEdit *>("le_ReadSuffix");
    cbx_ReadEncoding=ui->GroupBox_ReadSettings->findChild<QComboBox *>("cbx_ReadEncoding");

}

void SericalTest::initWidget(){     //控件初始化
    QStringList tempList;

    tempList.append("9600");
    tempList.append("19200");
    tempList.append("28800");
    tempList.append("57600");
    tempList.append("115200");
    cbx_Baud->addItems(tempList);   //初始化波特率下拉列表
    tempList.clear();


    tempList.append("UTF-8");      //初始化编码方式
    tempList.append("GBK");
    cbx_SendEncoding->addItems(tempList);
    cbx_ReadEncoding->addItems(tempList);
    tempList.clear();

    tempList.append("无");
    tempList.append("奇校验");
    tempList.append("偶校验");
    cbx_Parity->addItems(tempList);
    tempList.clear();

    tempList.append("5");
    tempList.append("6");
    tempList.append("7");
    tempList.append("8");
    cbx_DataBit->addItems(tempList);
    tempList.clear();

    tempList.append("1");
    tempList.append("1.5");
    tempList.append("2");
    cbx_StopBit->addItems(tempList);
    tempList.clear();

}


//读取接收到的信息
void SericalTest::ReadData(){
    static QByteArray byteArray;
    QByteArray temp;
    QDateTime time = QDateTime::currentDateTime();
    QString showStr="RX->"+time.toString("hh:mm:ss")+":";
    temp=serial->readAll();
    QString readStr;

    // QString str=QTextCodec::codecForName("UTF-8")->toUnicode(temp);
    QString lineBreak=NULL;

    byteArray.append(temp);
    QString suffixStr;
    if(cb_ReadSuffix->isChecked() && !le_ReadSuffix->text().isEmpty()){
        suffixStr=le_ReadSuffix->text();
    }else {
        suffixStr="";
    }
    if(cb_ReadSpaceSuffix->isChecked()){
        suffixStr="\r";
    }else {
        suffixStr="";
    }
    if(cb_ReadEnterSuffix->isChecked()){
        if(suffixStr=="\r"){
            suffixStr+="\n";
        }else {
            suffixStr="\n";
        }
    }
    if(suffixStr.isNull() || suffixStr.isEmpty()){
        readStr=QTextCodec::codecForName(cbx_ReadEncoding->currentText().toLatin1())->toUnicode(byteArray);
        showStr+=readStr;
        te_Read->append(showStr);
        byteArray.clear();
    }
    else  if(byteArray.contains(suffixStr.toLatin1()))
    {
        if(byteArray.contains(suffixStr.toLatin1())){
            int tempcount=byteArray.indexOf(suffixStr.toLatin1());
            qDebug()<<"包含换行符"<<tempcount<<endl;
        }
        readStr=QTextCodec::codecForName(cbx_ReadEncoding->currentText().toLatin1())->toUnicode(byteArray.left(byteArray.indexOf(suffixStr.toLatin1())+suffixStr.length()));
        showStr+=readStr;
        te_Read->append(showStr);
        byteArray = byteArray.right(byteArray.length()-byteArray.indexOf(suffixStr.toLatin1())-suffixStr.length());
    }
    qDebug()<<tr("In this function");
}





void SericalTest::initSerial(){      //串口初始化
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts()){
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite)){
            cbx_SerialName->addItem(serial.portName());
            serial.close();
        }
    }
    ui->cbx_Baud->setCurrentIndex(0);
}



void SericalTest::on_cb_SendEnterSuffix_stateChanged(int arg1)      //发送带回车符checkbox槽函数
{

    if(cb_SendSpaceSuffix->isChecked()){
        qDebug()<<"Send SpaceSuffix checkBox isChecked"<<endl;
    }
    else if(arg1==0){
        cb_SendSuffix->setEnabled(true);
        le_SendSuffix->setEnabled(true);
    }else{
        cb_SendSuffix->setEnabled(false);
        le_SendSuffix->setEnabled(false);
    }
}

void SericalTest::on_cb_SendSpaceSuffix_stateChanged(int arg1)   //发送带空格符checkbox状态改变槽函数
{

    if(cb_SendEnterSuffix->isChecked()){
        qDebug()<<"Send EnterSuffix checkBox isChecked"<<endl;
    }
    else if(arg1==0){
        cb_SendSuffix->setEnabled(true);
        le_SendSuffix->setEnabled(true);
    }else{
        cb_SendSuffix->setEnabled(false);
        le_SendSuffix->setEnabled(false);
    }
}



void SericalTest::on_cb_ReadEnterSuffix_stateChanged(int arg1)   //读取时按回车后缀断行checkbox状态改变槽函数
{
    if(cb_ReadSpaceSuffix->isChecked()){
        qDebug()<<"Read SpaceSuffix checkBox isChecked"<<endl;
    }
    else if(arg1==0){
        cb_ReadSuffix->setEnabled(true);
        le_ReadSuffix->setEnabled(true);
    }else{
        cb_ReadSuffix->setEnabled(false);
        le_ReadSuffix->setEnabled(false);
    }
}

void SericalTest::on_cb_ReadSpaceSuffix_stateChanged(int arg1)  //读取时按空格后缀断行checkbox状态改变槽函数
{
    if(cb_ReadEnterSuffix->isChecked()){
        qDebug()<<"Read SpaceSuffix checkBox isChecked"<<endl;
    }
    else if(arg1==0){
        cb_ReadSuffix->setEnabled(true);
        le_ReadSuffix->setEnabled(true);
    }else{
        cb_ReadSuffix->setEnabled(false);
        le_ReadSuffix->setEnabled(false);
    }
}



void SericalTest::on_cb_SendSuffix_stateChanged(int arg1)     //自定义发送后缀checkbox状态改变槽函数
{
    if(arg1==0){
        cb_SendEnterSuffix->setEnabled(true);
        cb_SendSpaceSuffix->setEnabled(true);
    }else {
        cb_SendEnterSuffix->setEnabled(false);
        cb_SendSpaceSuffix->setEnabled(false);
    }
}
void SericalTest::on_cb_ReadSuffix_stateChanged(int arg1)  //自定义读取段行符checkbox状态改变槽函数
{
    qDebug()<<"begin arg1:"<<arg1<<endl;
    if(arg1==0){
        cb_ReadEnterSuffix->setEnabled(true);
        cb_ReadSpaceSuffix->setEnabled(true);
    }else {

        cb_ReadEnterSuffix->setEnabled(false);
        cb_ReadSpaceSuffix->setEnabled(false);
        qDebug()<<"end arg1:"<<arg1<<endl;
    }
}

void SericalTest::on_btn_OpenSerialPort_clicked()     //打开串口槽函数
{
    if(btn_OpenSerialPort->text()==tr("打开串口")){
        serial = new QSerialPort;
        //设置串口名
        serial->setPortName(cbx_SerialName->currentText());
        //打开串口
        serial->open(QIODevice::ReadWrite);
        //设置波特率
        serial->setBaudRate(cbx_Baud->currentText().toInt());
        //设置数据位
        switch(cbx_SerialName->currentText().toInt()){
        case 5:
            serial->setDataBits(QSerialPort::Data5);
            qDebug()<<"数据为5"<<endl;
            break;
        case 6:
            serial->setDataBits(QSerialPort::Data6);
            qDebug()<<"数据为6"<<endl;
            break;
        case 7:
            serial->setDataBits(QSerialPort::Data7);
            qDebug()<<"数据为7"<<endl;
            break;
        case 8:
            serial->setDataBits(QSerialPort::Data8);
            qDebug()<<"数据为8"<<endl;
            break;
        default:
            serial->setDataBits(QSerialPort::Data8);
            qDebug()<<"默认数据位"<<endl;
            break;
        }
        //设置校验位
        switch(cbx_Parity->currentIndex()){
        case 0:
            serial->setParity(QSerialPort::NoParity);
            qDebug()<<"无校验"<<endl;
            break;
        case 1:
            serial->setParity(QSerialPort::OddParity);
            qDebug()<<"奇校验"<<endl;
            break;
        case 2:
            serial->setParity(QSerialPort::EvenParity);
            qDebug()<<"偶校验"<<endl;
            break;
        default:
            break;
        }
        //设置停止位
        switch(cbx_StopBit->currentIndex()){
        case 0:
            serial->setStopBits(QSerialPort::OneStop);
            qDebug()<<"1位停止位"<<endl;
            break;
        case 1:
            serial->setStopBits(QSerialPort::OneAndHalfStop);
            qDebug()<<"1.5位停止位"<<endl;
            break;
        case 2:
            serial->setStopBits(QSerialPort::TwoStop);
            qDebug()<<"2位停止位"<<endl;
            break;
        default:
            serial->setStopBits(QSerialPort::OneStop);
            qDebug()<<"默认停止位"<<endl;
            break;
        }
        //设置流控制
        serial->setFlowControl(QSerialPort::NoFlowControl);

        //关闭流控制
        cbx_SerialName->setEnabled(false);
        cbx_Baud->setEnabled(false);
        cbx_DataBit->setEnabled(false);
        cbx_Parity->setEnabled(false);
        cbx_StopBit->setEnabled(false);
        btn_OpenSerialPort->setText(tr("关闭串口"));

        //连接信号槽
        QObject::connect(serial,&QSerialPort::readyRead,this,&SericalTest::ReadData);
    }
    else
    {
        //关闭串口
        serial->clear();
        serial->close();
        serial->deleteLater();

        //恢复设置使能
        cbx_SerialName->setEnabled(true);
        cbx_Baud->setEnabled(true);
        cbx_DataBit->setEnabled(true);
        cbx_Parity->setEnabled(true);
        cbx_StopBit->setEnabled(true);
        btn_OpenSerialPort->setText(tr("打开串口"));
    }
}

void SericalTest::on_btn_Send_clicked()    //发送按钮槽函数
{
    QString sendStr=te_Send->toPlainText();     //获取要发送的内容
    QByteArray sendByteArray;                   //字符串转换为QByteArray
    QString encodStr=cbx_SendEncoding->currentText();  //获取编码格式
    QTextCodec *qCodec;                         //编码转换实例
    qCodec=QTextCodec::codecForName(encodStr.toLatin1());  //设置编码格式
    sendByteArray=qCodec->fromUnicode(sendStr);            //转换



    if(cb_SendSuffix->isChecked()){
        sendByteArray.append(le_SendSuffix->text().toLatin1());
    }else {
        if(cb_SendSpaceSuffix->isChecked()==true){
            sendByteArray.append(0x0d);
        }
        if(cb_SendEnterSuffix->isChecked()==true){
            sendByteArray.append(0x0a);
        }
    }



    serial->write(sendByteArray);
    QString showStr="TX->"+QDateTime::currentDateTime().toString("hh:mm:ss")+":"+sendStr;
    te_Read->append(showStr);
}

void SericalTest::on_btn_Clear_clicked()   //清空发送
{
    te_Read->setText("");
}
