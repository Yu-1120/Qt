#ifndef MYSERIAL_H
#define MYSERIAL_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MySerial; }
QT_END_NAMESPACE

class MySerial : public QWidget
{
    Q_OBJECT

public:
    MySerial(QWidget *parent = nullptr);
    ~MySerial();

private slots:
    void on_pushButton_open_clicked();

    void on_pushButton_send_clicked();

private:
    Ui::MySerial *ui;
    //串口对象
    QSerialPort *ser;
};
#endif // MYSERIAL_H
