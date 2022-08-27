#ifndef FILEDOWNLOAD_H
#define FILEDOWNLOAD_H

#include <QWidget>
#include "filedownloadthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FileDownload; }
QT_END_NAMESPACE

class FileDownload : public QWidget
{
    Q_OBJECT

public:
    FileDownload(QWidget *parent = nullptr);
    ~FileDownload();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

private:
    Ui::FileDownload *ui;
    //下载线程
    FileDownloadThread *thread;

signals:
    //开始/停止下载
    void set_flag(bool fg);
};
#endif // FILEDOWNLOAD_H
