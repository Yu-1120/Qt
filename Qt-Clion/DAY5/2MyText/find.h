#ifndef FIND_H
#define FIND_H

#include <QDialog>

namespace Ui {
class Find;
}

class Find : public QDialog
{
    Q_OBJECT

public:
    explicit Find(QString s,QWidget *parent = nullptr);
    ~Find();

signals:
    //传递查找的内容，大小写和方向
    void find_str(const QString s,bool cast,bool dierction);

private slots:
    void on_pushButton_find_clicked();

    void on_pushButton_cancel_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::Find *ui;
};

#endif // FIND_H
