#ifndef SQLLOGIN_H
#define SQLLOGIN_H

#include <QWidget>
#include <QSqlDatabase>//数据库驱动类
#include <QSqlQuery>//执行SQL语句类
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class SQLLogin; }
QT_END_NAMESPACE

class SQLLogin : public QWidget
{
    Q_OBJECT

public:
    SQLLogin(QWidget *parent = nullptr);
    ~SQLLogin();

private slots:
    void on_pushButton_reg_clicked();

    void on_pushButton_login_clicked();

    void on_pushButton_unreg_clicked();

private:
    Ui::SQLLogin *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
};
#endif // SQLLOGIN_H
