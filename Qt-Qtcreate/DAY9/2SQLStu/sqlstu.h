#ifndef SQLSTU_H
#define SQLSTU_H

#include <QWidget>
#include <QStandardItemModel>
#include <QSqlDatabase>//数据库驱动类
#include <QSqlQuery>//执行SQL语句类

QT_BEGIN_NAMESPACE
namespace Ui { class SQLStu; }
QT_END_NAMESPACE

class SQLStu : public QWidget
{
    Q_OBJECT

public:
    SQLStu(QWidget *parent = nullptr);
    ~SQLStu();

private slots:
    void on_pushButton_create_clicked();

    void on_pushButton_insert_clicked();

    void on_pushButton_select_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_update_clicked();

private:
    Ui::SQLStu *ui;
    QStandardItemModel *model;

    QSqlDatabase db;
};
#endif // SQLSTU_H
