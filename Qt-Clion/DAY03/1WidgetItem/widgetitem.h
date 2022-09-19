#ifndef WIDGETITEM_H
#define WIDGETITEM_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QSpinBox>
#include <QRadioButton>
#include <QSlider>
#include <QProgressBar>
#include <QListWidget>
#include <QComboBox>

class WidgetItem : public QWidget {
Q_OBJECT

public:
    WidgetItem(QWidget *parent = nullptr);

    ~WidgetItem();

private:
    QLabel *lab;
    QCheckBox *cbox;//复选框
    QSpinBox *sbox;//自旋框
    QRadioButton *manbtn;//单选按钮
    QRadioButton *womanbtn;
    QSlider *sld;//滑动条
    QProgressBar *pbar;//进度条
    QListWidget *lw;//列表部件框
    QComboBox *cb;//下拉列表框

    QPushButton *btn;
    QVBoxLayout *lyt;

/*
signals:
    //信号可以重载，连接时需要指定
    void send();
    void send(int n);
    void send(double n);
*/
};

#endif // WIDGETITEM_H
