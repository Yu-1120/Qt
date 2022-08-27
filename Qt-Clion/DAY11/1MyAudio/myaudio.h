#ifndef MYAUDIO_H
#define MYAUDIO_H

#include <QWidget>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class MyAudio; }
QT_END_NAMESPACE

class MyAudio : public QWidget
{
    Q_OBJECT

public:
    MyAudio(QWidget *parent = nullptr);
    ~MyAudio();

private slots:
    void on_pushButton_record_clicked();

    void on_pushButton_play_clicked();

private:
    Ui::MyAudio *ui;
    QProcess *p;
};
#endif // MYAUDIO_H
