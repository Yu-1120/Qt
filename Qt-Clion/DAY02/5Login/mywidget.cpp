#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent) {
    lab = new QLabel(QString::fromLocal8Bit("ÄãÕâ¸öÀÏ6"), this);
    lab->move(400, 240);
}

MyWidget::~MyWidget() {

}
