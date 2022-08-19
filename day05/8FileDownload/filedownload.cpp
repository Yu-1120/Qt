#include "filedownload.h"
#include "ui_filedownload.h"
#include <QMessageBox>

FileDownload::FileDownload(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FileDownload)
{
    ui->setupUi(this);

    thread = new FileDownloadThread(this);

    //连接信号和槽
    QObject::connect(thread,&FileDownloadThread::updateDownload,ui->progressBar,&QProgressBar::setValue);
    QObject::connect(this,&FileDownload::set_flag,thread,&FileDownloadThread::set_flag);
    QObject::connect(thread,&FileDownloadThread::DownloadReady,this,[&](){
        QMessageBox::information(this,"提示","下载完成!");
    });

    //启动线程
    thread->start();
}

FileDownload::~FileDownload()
{
    thread->terminate();

    delete ui;
}


void FileDownload::on_pushButton_start_clicked()
{
    emit set_flag(true);
}

void FileDownload::on_pushButton_stop_clicked()
{
    emit set_flag(false);
}
