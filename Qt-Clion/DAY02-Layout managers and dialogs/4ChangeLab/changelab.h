#ifndef CHANGELAB_H
#define CHANGELAB_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLayout>

class ChangeLab : public QWidget
{
    Q_OBJECT

public:
    ChangeLab(QWidget *parent = nullptr);
    ~ChangeLab();

private:
    QLabel *lab;
    QPushButton *text_btn;
    QPushButton *color_btn;

    bool text_flag;
    bool color_flag;

    QHBoxLayout *hlyt;
    QVBoxLayout *lyt;
};
#endif // CHANGELAB_H
