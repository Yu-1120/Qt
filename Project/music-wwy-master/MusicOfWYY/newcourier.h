#ifndef NEWCOURIER_H
#define NEWCOURIER_H

#include <QWidget>
#include <QListWidgetItem>
namespace Ui {
class NewCourier;
}

class NewCourier : public QWidget
{
    Q_OBJECT

public:
    explicit NewCourier(QWidget *parent = nullptr);
    ~NewCourier();
    //设置对应数据
    void setInitData();
    void setChose(int id);
    void setChinese(); //设置中文
    void setEurope();//设置欧美
    void setKorea(); //设置韩国
    void setJapan(); //设置日文


private:
    Ui::NewCourier *ui;
};

#endif // NEWCOURIER_H
