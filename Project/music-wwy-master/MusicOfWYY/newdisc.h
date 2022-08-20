#ifndef NEWDISC_H
#define NEWDISC_H

#include <QWidget>

namespace Ui {
class NewDisc;
}

class NewDisc : public QWidget
{
    Q_OBJECT

public:
    explicit NewDisc(QWidget *parent = nullptr);
    ~NewDisc();
    void setInitData();
    void setChose(int id);
    void setChinese(); //设置中文
    void setEurope();//设置欧美
    void setKorea(); //设置韩国
    void setJapan(); //设置日文

private:
    Ui::NewDisc *ui;
};

#endif // NEWDISC_H
