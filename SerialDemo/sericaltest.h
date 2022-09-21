#ifndef SERICALTEST_H
#define SERICALTEST_H

#include <QDialog>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QCheckBox>
#include <QComboBox>
#include <qtextedit.h>

namespace Ui {
class SericalTest;
}

class SericalTest : public QDialog
{
    Q_OBJECT

public:
    explicit SericalTest(QWidget *parent = nullptr);
    ~SericalTest();




private slots:
    void ReadData();
    void on_btn_Clear_clicked();
    void on_cb_SendEnterSuffix_stateChanged(int arg1);

    void on_cb_SendSpaceSuffix_stateChanged(int arg1);

    void on_cb_SendSuffix_stateChanged(int arg1);

    void on_cb_ReadEnterSuffix_stateChanged(int arg1);

    void on_cb_ReadSpaceSuffix_stateChanged(int arg1);

    void on_cb_ReadSuffix_stateChanged(int arg1);

    void on_btn_OpenSerialPort_clicked();

    void on_btn_Send_clicked();

private:
    Ui::SericalTest *ui;  //界面
    QSerialPort *serial;  //定义串口类
    void serial_Read();//串口数据读取显示
    void initSerial(); //串口初始化
    void getWidget();  //获取控件
    void initWidget(); //控件初始化

    QPushButton *btn_OpenSerialPort;  //打开串口按钮
    QPushButton *btn_Send;            //发送按钮
    QPushButton *btn_Clear;           //清空按钮

    QTextEdit *te_Read;               //接收text
    QTextEdit *te_Send;               //发送text


    QComboBox *cbx_SerialName;   //串口名
    QComboBox *cbx_Baud;         //波特率
    QComboBox *cbx_DataBit;      //数据位
    QComboBox *cbx_Parity;       //奇偶校验
    QComboBox *cbx_StopBit;      //停止位

    QCheckBox *cb_SendSuffix;
    QCheckBox *cb_SendEnterSuffix;
    QCheckBox *cb_SendSpaceSuffix;
    QCheckBox *cb_SendEncoding;
    QComboBox *cbx_SendEncoding;
    QLineEdit *le_SendSuffix;


    QCheckBox *cb_ReadSuffix;
    QCheckBox *cb_ReadEnterSuffix;
    QCheckBox *cb_ReadSpaceSuffix;
    QCheckBox *cb_ReadEncoding;
    QComboBox *cbx_ReadEncoding;
    QLineEdit *le_ReadSuffix;
};

#endif // SERICALTEST_H
