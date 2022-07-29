#ifndef SHOWPIC_H
#define SHOWPIC_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ShowPic; }
QT_END_NAMESPACE

class ShowPic : public QWidget
{
    Q_OBJECT

public:
    ShowPic(QWidget *parent = nullptr);
    ~ShowPic();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::ShowPic *ui;
};
#endif // SHOWPIC_H
