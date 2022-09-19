#ifndef OTHERDIALOG_H
#define OTHERDIALOG_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class OtherDialog : public QWidget
{
    Q_OBJECT

public:
    OtherDialog(QWidget *parent = nullptr);
    ~OtherDialog();

private:
    QLabel *lab;

     QPushButton *btn;
      QPushButton *btn1;
       QPushButton *btn2;
};
#endif // OTHERDIALOG_H
