#include "studb.h"
#include "ui_studb.h"
#include <QDebug>
#include <QMessageBox>

StuDB::StuDB(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StuDB)
{
    ui->setupUi(this);

    //打开数据库
    int res = sqlite3_open("./first.db",&pDb);
    if(res!=SQLITE_OK){
        QMessageBox::warning(this,"提示","打开数据库失败!");
    }
}

StuDB::~StuDB()
{
    delete ui;
    //关闭数据库
    sqlite3_close(pDb);
}

//建表
void StuDB::on_pushButton_create_clicked()
{
    QString sql = QString("create table if not exists %1(id int unique,name ntext,age int);").
                    arg(ui->lineEdit_tablename->text());
    //执行sql
    int res = sqlite3_exec(pDb,sql.toStdString().c_str(),NULL,NULL,NULL);
    if(res!=SQLITE_OK){
        QMessageBox::warning(this,"提示","建表失败!");
        return;
    }
    qDebug()<<sql;
    //禁止表名输入框和建表按钮
    ui->lineEdit_tablename->setEnabled(false);
    ui->pushButton_create->setEnabled(false);
}
//************************添加部分-WORK******************************
//插入
void StuDB::on_pushButton_insert_clicked()
{
    QString sql = QString("insert into %1 values(%2,'%3',%4);").
                        arg(ui->lineEdit_tablename->text()).arg(ui->spinBox_insertid->value()).
                        arg(ui->lineEdit_insertname->text()).arg(ui->spinBox_insertage->value());
        qDebug()<<sql;
        //执行sql
        int res = sqlite3_exec(pDb,sql.toStdString().c_str(),NULL,NULL,NULL);
        if(res!=SQLITE_OK){
            QMessageBox::warning(this,"提示","插入失败!");
            return;
        }
       //刷新显示
//         on_pushButton_select_clicked();
//************************添加部分-WORK******************************
}

