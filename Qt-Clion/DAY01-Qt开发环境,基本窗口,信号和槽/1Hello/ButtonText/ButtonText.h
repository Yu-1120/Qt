#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>

class ButtonText : public QWidget
{
    Q_OBJECT

public:
    ButtonText(QWidget *parent = nullptr);
    ~ButtonText();

private:
    QPushButton *btn;

//信号
signals:
    void send_sig(int num);//无需实现

//槽函数
private slots:
    //格式要和信号完全一致
    void btn_clicked();
};
#endif // ButtonText
