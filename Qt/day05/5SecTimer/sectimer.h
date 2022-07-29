#ifndef SECTIMER_H
#define SECTIMER_H

#include <QWidget>
#include <QTime>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class SecTimer; }
QT_END_NAMESPACE

class SecTimer : public QWidget
{
    Q_OBJECT

public:
    SecTimer(QWidget *parent = nullptr);
    ~SecTimer();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_gettime_clicked();

    void on_pushButton_clear_clicked();

private:
    Ui::SecTimer *ui;
    QTimer *t;
    QTime sec_time;
};
#endif // SECTIMER_H
