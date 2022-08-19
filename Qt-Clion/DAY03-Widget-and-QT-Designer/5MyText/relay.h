#ifndef RELAY_H
#define RELAY_H

#include <QDialog>

namespace Ui {
class Relay;
}

class Relay : public QDialog
{
    Q_OBJECT

public:
    explicit Relay(QWidget *parent = nullptr);
    ~Relay();

signals://定义一个槽函数
    //传递查找的内容，大小写和方向
    void relay_str(const QString s);

private slots:
    void on_ensure_clicked();

    void on_canel_clicked();


private:
    Ui::Relay *ui;
};

#endif // RELAY_H
