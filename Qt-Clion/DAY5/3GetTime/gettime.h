#ifndef GETTIME_H
#define GETTIME_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class GetTime; }
QT_END_NAMESPACE

class GetTime : public QWidget
{
    Q_OBJECT

public:
    GetTime(QWidget *parent = nullptr);
    ~GetTime();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GetTime *ui;
};
#endif // GETTIME_H
