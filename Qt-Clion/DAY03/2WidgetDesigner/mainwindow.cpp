#include "widgetdesigner.h"
#include "ui_widgetdesigner.h"
#include <QDebug>

WidgetDesigner::WidgetDesigner(QWidget *parent)
        : QWidget(parent), ui(new Ui::WidgetDesigner) {
    ui->setupUi(this);
}

WidgetDesigner::~WidgetDesigner() {
    delete ui;
}

//槽函数
void WidgetDesigner::on_pushButton_clicked() {
    qDebug() << "on_pushButton_clicked";
    //访问ui中的部件
    ui->label->setText("xxxxx");
}

void WidgetDesigner::on_horizontalSlider_sliderMoved(int position) {
    qDebug() << position;
}
