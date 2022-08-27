#ifndef SMARTSQLSTU_H
#define SMARTSQLSTU_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class SmartSQLStu; }
QT_END_NAMESPACE

class SmartSQLStu : public QWidget
{
    Q_OBJECT

public:
    SmartSQLStu(QWidget *parent = nullptr);
    ~SmartSQLStu();

private slots:
    void on_pushButton_create_clicked();

    void on_pushButton_insert_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_revert_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_select_clicked();

private:
    Ui::SmartSQLStu *ui;
    QSqlTableModel *model;//数据库数据模型

    QSqlDatabase db;
};
#endif // SMARTSQLSTU_H
