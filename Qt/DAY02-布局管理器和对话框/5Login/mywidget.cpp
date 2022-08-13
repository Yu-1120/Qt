#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    lab = new QLabel("Welcome",this);
    lab->move(400,240);
}

MyWidget::~MyWidget()
{

}
