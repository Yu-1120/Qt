#ifndef MYSPEECH_H
#define MYSPEECH_H

#include <QWidget>
#include <QTextToSpeech>

QT_BEGIN_NAMESPACE
namespace Ui { class MySpeech; }
QT_END_NAMESPACE

class MySpeech : public QWidget
{
    Q_OBJECT

public:
    MySpeech(QWidget *parent = nullptr);
    ~MySpeech();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MySpeech *ui;
    QTextToSpeech *tts;
};
#endif // MYSPEECH_H
