#ifndef MYPIC_H
#define MYPIC_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MyPic; }
QT_END_NAMESPACE

class MyPic : public QWidget
{
    Q_OBJECT

public:
    MyPic(QWidget *parent = nullptr);
    ~MyPic();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MyPic *ui;
};
#endif // MYPIC_H
