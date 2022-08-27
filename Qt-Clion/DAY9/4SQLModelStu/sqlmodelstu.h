#ifndef SQLMODELSTU_H
#define SQLMODELSTU_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class SQLModelStu; }
QT_END_NAMESPACE

class SQLModelStu : public QWidget
{
    Q_OBJECT

public:
    SQLModelStu(QWidget *parent = nullptr);
    ~SQLModelStu();

private slots:
    void on_pushButton_create_clicked();

    void on_pushButton_insert_clicked();

    void on_pushButton_select_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_update_clicked();

private:
    Ui::SQLModelStu *ui;
    QSqlTableModel *model;//数据库数据模型

    QSqlDatabase db;
};
#endif // SQLMODELSTU_H
