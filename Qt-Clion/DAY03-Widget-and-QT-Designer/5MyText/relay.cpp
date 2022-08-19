#include "relay.h"
#include "ui_relay.h"

Relay::Relay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Relay)
{
    ui->setupUi(this);


}

Relay::~Relay()
{
    delete ui;
}


void Relay::on_ensure_clicked()
{

}

void Relay::on_canel_clicked()
{
this->done(0);
}

void Relay::on_realay_before_edit_textChanged()
{

}

void Relay::on_relay_later_edit_textChanged()
{

}
