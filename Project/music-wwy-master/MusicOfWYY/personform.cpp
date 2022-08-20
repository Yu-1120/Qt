#include "personform.h"
#include "ui_personform.h"

//鼠标离开
void personForm::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    this->close();
}

personForm::personForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::personForm)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground); //设置样式表
}

personForm::~personForm()
{
    delete ui;
}

void personForm::on_pushButton_dynamic_clicked()
{

}

void personForm::on_pushButton_attention_clicked()
{

}

void personForm::on_pushButton_fans_clicked()
{

}

void personForm::on_pushButton_sign_clicked()
{

}

void personForm::on_pushButton_Center_clicked()
{

}

void personForm::on_pushButton_Class_clicked()
{

}

void personForm::on_pushButton_store_clicked()
{

}

void personForm::on_pushButton_person_mess_clicked()
{

}

void personForm::on_pushButton_binding_clicked()
{

}

void personForm::on_pushButton_myservice_clicked()
{

}

void personForm::on_pushButton_myquit_clicked()
{

}
