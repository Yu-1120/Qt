#ifndef STUDB_H
#define STUDB_H

#include <QWidget>
#include "sqlite3.h"

QT_BEGIN_NAMESPACE
namespace Ui { class StuDB; }
QT_END_NAMESPACE

class StuDB : public QWidget
{
    Q_OBJECT

public:
    StuDB(QWidget *parent = nullptr);
    ~StuDB();

private slots:
    void on_pushButton_create_clicked();


    void on_pushButton_insert_clicked();


private:
    Ui::StuDB *ui;
    //sqlite3句柄
    sqlite3 *pDb;
};
#endif // STUDB_H
