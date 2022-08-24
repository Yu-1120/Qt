#ifndef MYRFID_H
#define MYRFID_H

#include <QWidget>
#include "rfidthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyRfid; }
QT_END_NAMESPACE

class MyRfid : public QWidget
{
    Q_OBJECT

public:
    MyRfid(QWidget *parent = nullptr);
    ~MyRfid();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

private:
    Ui::MyRfid *ui;
    RfidThread *thread;
    bool flag;
};
#endif // MYRFID_H
