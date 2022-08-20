#ifndef CALCULATE_H
#define CALCULATE_H

#include <QWidget>

//使用枚举表示运算类型
enum oper{
    oper_add,
    oper_sub,
    oper_mul,
    oper_div,
};

QT_BEGIN_NAMESPACE
namespace Ui { class Calculate; }
QT_END_NAMESPACE

class Calculate : public QWidget
{
    Q_OBJECT

public:
    Calculate(QWidget *parent = nullptr);
    ~Calculate();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_sub_clicked();

    void on_pushButton_mul_clicked();

    void on_pushButton_div_clicked();

    void on_pushButton_equ_clicked();

private:
    Ui::Calculate *ui;
    //记录当前值
    int num;
    //上一个操作数
    int temp;
    //记录当前运算
    oper op;
};
#endif // CALCULATE_H
