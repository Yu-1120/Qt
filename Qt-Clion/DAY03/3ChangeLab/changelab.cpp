#include "changelab.h"
#include "ui_changelab.h"
#include <QInputDialog>
#include <QColorDialog>
#include <QFontDialog>

ChangeLab::ChangeLab(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChangeLab)
{
    ui->setupUi(this);
}

ChangeLab::~ChangeLab()
{
    delete ui;
}


void ChangeLab::on_pushButton_setText_clicked()
{
    QString str = QInputDialog::getText(this,"输入内容","请输入文本信息");
    ui->label->setText(str);
}

void ChangeLab::on_pushButton_setColor_clicked()
{
    QColor c = QColorDialog::getColor(Qt::black,this,"选择颜色");
    QPalette p;
    p.setColor(QPalette::WindowText,c);
    ui->label->setPalette(p);
}

void ChangeLab::on_pushButton_setFont_clicked()
{
    bool flag = true;
   QFont f = QFontDialog::getFont(&flag,this);
   ui->label->setFont(f);
}
