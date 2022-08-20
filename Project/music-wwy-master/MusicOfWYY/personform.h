#ifndef PERSONFORM_H
#define PERSONFORM_H

#include <QWidget>

namespace Ui {
class personForm;
}

class personForm : public QWidget
{
    Q_OBJECT
protected:
    void leaveEvent(QEvent *event);
public:
    explicit personForm(QWidget *parent = nullptr);
    ~personForm();

private slots:
    void on_pushButton_dynamic_clicked();

    void on_pushButton_attention_clicked();

    void on_pushButton_fans_clicked();

    void on_pushButton_sign_clicked();

    void on_pushButton_Center_clicked();

    void on_pushButton_Class_clicked();

    void on_pushButton_store_clicked();

    void on_pushButton_person_mess_clicked();

    void on_pushButton_binding_clicked();

    void on_pushButton_myservice_clicked();

    void on_pushButton_myquit_clicked();

private:
    Ui::personForm *ui;
};

#endif // PERSONFORM_H
