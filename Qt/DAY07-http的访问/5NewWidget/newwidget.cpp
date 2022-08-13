#include "newwidget.h"
#include "ui_newwidget.h"

NewWidget::NewWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NewWidget)
{
    ui->setupUi(this);
}

NewWidget::~NewWidget()
{
    delete ui;
}

