#ifndef MYPROCESS_H
#define MYPROCESS_H

#include <QWidget>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class MyProcess; }
QT_END_NAMESPACE

class MyProcess : public QWidget
{
    Q_OBJECT

public:
    MyProcess(QWidget *parent = nullptr);
    ~MyProcess();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

private:
    Ui::MyProcess *ui;
    QProcess *pro;
};
#endif // MYPROCESS_H
