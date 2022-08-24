#include "myspeech.h"
#include "ui_myspeech.h"

MySpeech::MySpeech(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MySpeech)
{
    ui->setupUi(this);

    tts = new QTextToSpeech(this);
}

MySpeech::~MySpeech()
{
    delete ui;
}


void MySpeech::on_pushButton_clicked()
{
    //文字转语音
    tts->say(ui->lineEdit->text());
}
