#ifndef CHANGELAB_H
#define CHANGELAB_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ChangeLab; }
QT_END_NAMESPACE

class ChangeLab : public QWidget
{
    Q_OBJECT

public:
    ChangeLab(QWidget *parent = nullptr);
    ~ChangeLab();

private slots:
    void on_pushButton_setText_clicked();

    void on_pushButton_setColor_clicked();

    void on_pushButton_setFont_clicked();

private:
    Ui::ChangeLab *ui;
};
#endif // CHANGELAB_H
