#ifndef ENTERFORM_H
#define ENTERFORM_H

#include <QDialog>

namespace Ui {
class EnterForm;
}

class EnterForm : public QDialog
{
    Q_OBJECT

public:
    explicit EnterForm(QWidget *parent = nullptr);
    ~EnterForm();

private slots:
    void on_btn_Serial_clicked();

private:
    Ui::EnterForm *ui;
};

#endif // ENTERFORM_H
