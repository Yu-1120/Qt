#include "sqlstu.h"
#include "ui_sqlstu.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlTableModel>

SQLStu::SQLStu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SQLStu)
{
    ui->setupUi(this);

    //初始化模型
    model = new QStandardItemModel(this);
    model->setHorizontalHeaderItem(0,new QStandardItem("id"));
    model->setHorizontalHeaderItem(1,new QStandardItem("name"));
    model->setHorizontalHeaderItem(2,new QStandardItem("age"));
    //绑定模型和表格
    ui->tableView->setModel(model);

    //添加数据库驱动
    db = QSqlDatabase::addDatabase("QSQLITE");
    //指定数据库文件路径
    db.setDatabaseName("stu.db");
    //打开数据库
    if(!db.open()){
        QMessageBox::warning(this,"提示","打开数据库失败");
    }
}

SQLStu::~SQLStu()
{
    db.close();//关闭数据库
    delete ui;
}

//建表
void SQLStu::on_pushButton_create_clicked()
{
    QString sql = QString("create table if not exists %1(id int unique,name ntext,age int)").
                    arg(ui->lineEdit_tablename->text());
    //执行sql ------ QSqlQuery对象在要执行时创建
    QSqlQuery query;
    if(!query.exec(sql)){
        QMessageBox::warning(this,"提示","建表失败!");
        return;
    }

    //禁止表名输入框和建表按钮
    ui->lineEdit_tablename->setEnabled(false);
    ui->pushButton_create->setEnabled(false);

    ui->pushButton_insert->setEnabled(true);
    ui->pushButton_select->setEnabled(true);
    ui->pushButton_delete->setEnabled(true);
    ui->pushButton_update->setEnabled(true);
}

//插入
void SQLStu::on_pushButton_insert_clicked()
{
    QString sql = QString("insert into %1 values(%2,'%3',%4)").
                    arg(ui->lineEdit_tablename->text()).arg(ui->spinBox_insertid->value()).
                    arg(ui->lineEdit_insertname->text()).arg(ui->spinBox_insertage->value());
    qDebug()<<sql;
    //执行sql
    QSqlQuery query;
    if(!query.exec(sql)){
        QMessageBox::warning(this,"提示","插入失败!");
        return;
    }

    //刷新显示
    on_pushButton_select_clicked();
}

//查询
void SQLStu::on_pushButton_select_clicked()
{
    QString sql = QString("select * from %1").arg(ui->lineEdit_tablename->text());

    quint16 count = 0;

    //删除所有行
    model->removeRows(0,model->rowCount());

    //执行sql ----- 将本窗口对象传递给回调函数
    QSqlQuery query;
    if(!query.exec(sql)){
        QMessageBox::warning(this,"提示","查询失败!");
        return;
    }

    //获取查询结果 ----- next()
    while(query.next()){
        model->setItem(count,0,new QStandardItem(query.value(0).toString()));
        model->setItem(count,1,new QStandardItem(query.value(1).toString()));
        model->setItem(count,2,new QStandardItem(query.value(2).toString()));
        count++;
    }
}

//删除
void SQLStu::on_pushButton_delete_clicked()
{
    QString sql = QString("delete from %1 where id=%2;").
                    arg(ui->lineEdit_tablename->text()).arg(ui->spinBox_deleteid->value());
    qDebug()<<sql;
    //执行sql
    QSqlQuery query;
    if(!query.exec(sql)){
        QMessageBox::warning(this,"提示","查询失败!");
        return;
    }

    //刷新显示
    on_pushButton_select_clicked();
}

//更新
void SQLStu::on_pushButton_update_clicked()
{
    QString sql;

    if(ui->radioButton_newid->isChecked()){//改id
        sql = QString("update %1 set id=%2 where id=%3;").
                arg(ui->lineEdit_tablename->text()).arg(ui->spinBox_newid->value()).
                arg(ui->spinBox_updateid->value());
    }
    else if(ui->radioButton_newname->isChecked()){//改name
        sql = QString("update %1 set name='%2' where id=%3;").
                arg(ui->lineEdit_tablename->text()).arg(ui->lineEdit_newname->text()).
                arg(ui->spinBox_updateid->value());
    }
    else if(ui->radioButton_newage->isChecked()){//改age
        sql = QString("update %1 set age=%2 where id=%3;").
                arg(ui->lineEdit_tablename->text()).arg(ui->spinBox_newage->value()).
                arg(ui->spinBox_updateid->value());
    }

    qDebug()<<sql;
    //执行sql
    QSqlQuery query;
    if(!query.exec(sql)){
        QMessageBox::warning(this,"提示","查询失败!");
        return;
    }

    //刷新显示
    on_pushButton_select_clicked();
}
