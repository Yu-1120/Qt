#ifndef MYCALCULATE_H
#define MYCALCULATE_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MyCalculate; }
QT_END_NAMESPACE

class MyCalculate : public QDialog
{
    Q_OBJECT

public:
    MyCalculate(QWidget *parent = nullptr);
    ~MyCalculate();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_exit_clicked();

    void on_lineEdit_password_returnPressed();

private:
    Ui::MyCalculate *ui;
};
#endif // MYCALCULATE_H
