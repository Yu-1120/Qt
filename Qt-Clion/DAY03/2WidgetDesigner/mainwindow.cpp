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

//�ۺ���
void WidgetDesigner::on_pushButton_clicked() {
    qDebug() << "on_pushButton_clicked";
    //����ui�еĲ���
    ui->label->setText("xxxxx");
}

void WidgetDesigner::on_horizontalSlider_sliderMoved(int position) {
    qDebug() << position;
}
