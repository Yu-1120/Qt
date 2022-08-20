#include "musicform.h"
#include "ui_musicform.h"

MusicForm::MusicForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicForm)
{
    ui->setupUi(this);
}

MusicForm::~MusicForm()
{
    delete ui;
}

void MusicForm::setMusicName(QString musicName)
{
    ui->labMName->setText(musicName);
}

void MusicForm::setMusicAuthor(QString musicAuther)
{
    ui->labMuAuthor->setText(musicAuther);
}

void MusicForm::setMusicPicture(QString url)
{
    QString str = "QPushButton{border-image:url("+url+");}";
    ui->ptnGetMusic->setStyleSheet(str);
    ui->pushButton->setStyleSheet("QPushButton{border-image:url(./images/Messageform/like.png);}");
}
