#ifndef REPLACE_H
#define REPLACE_H

#include <QDialog>

namespace Ui {
class Replace;
}

class Replace : public QDialog
{
    Q_OBJECT

public:
    explicit Replace(QString s,QWidget *parent = nullptr);
    ~Replace();

signals:
    //传递查找和替换的内容，大小写和方向
    void replace_str(const QString src,const QString dest,bool cast,bool dierction);

private slots:
    void on_pushButton_find_clicked();

    void on_pushButton_cancel_clicked();

    void on_lineEdit_find_textEdited(const QString &arg1);

private:
    Ui::Replace *ui;
};

#endif // REPLACE_H
