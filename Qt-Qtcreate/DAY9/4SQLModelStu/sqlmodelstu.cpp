#include "sqlmodelstu.h"
#include "ui_sqlmodelstu.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlError>

SQLModelStu::SQLModelStu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SQLModelStu)
{
    ui->setupUi(this);

    //添加数据库驱动
    db = QSqlDatabase::addDatabase("QSQLITE");
    //指定数据库文件路径
    db.setDatabaseName("stu.db");
    //打开数据库
    if(!db.open()){
        QMessageBox::warning(this,"提示","打开数据库失败");
    }

    //初始化模型
    model = new QSqlTableModel(this);
    //绑定模型和表格界面
    ui->tableView->setModel(model);
}

SQLModelStu::~SQLModelStu()
{
    db.close();
    delete ui;
}

//建表
void SQLModelStu::on_pushButton_create_clicked()
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
void SQLModelStu::on_pushButton_insert_clicked()
{
    //模型标定数据库表
    model->setTable(ui->lineEdit_tablename->text());

    //获取一条空记录
    QSqlRecord record = model->record();
    //设置记录中字段的值
    record.setValue("id",ui->spinBox_insertid->value());
    record.setValue("name",ui->lineEdit_insertname->text());
    record.setValue("age",ui->spinBox_insertage->value());
    //将记录插入到模型末尾
    if(!model->insertRecord(-1,record)){
        QMessageBox::warning(this,"提示",model->lastError().text());
    }

    //提交数据库
    model->submitAll();

    //刷新显示
    on_pushButton_select_clicked();
}

//查询
void SQLModelStu::on_pushButton_select_clicked()
{
    //模型标定数据库表
    model->setTable(ui->lineEdit_tablename->text());
    //设置过滤器
    //model->setFilter("id=1001 or name='白骨精'");
    //设置排序方法
    //model->setSort(2,Qt::DescendingOrder);//按年龄降序
    //查询
    model->select();
}

//删除
void SQLModelStu::on_pushButton_delete_clicked()
{
    //先找到,再删除
    model->setTable(ui->lineEdit_tablename->text());
    //使用过滤器
    model->setFilter(QString("id=%1").arg(ui->spinBox_deleteid->value()));
    //查询
    model->select();

    //找到后删除
    if(model->rowCount()==1){
        //删除第一条
        model->removeRow(0);
        //提交数据库
        model->submitAll();
    }

    //刷新显示
    on_pushButton_select_clicked();
}

//修改
void SQLModelStu::on_pushButton_update_clicked()
{
    //先找出来修改完再写回
    model->setTable(ui->lineEdit_tablename->text());
    //使用过滤器
    model->setFilter(QString("id=%1").arg(ui->spinBox_updateid->value()));
    //查询
    model->select();

    if(model->rowCount()==1 && ui->radioButton_newid->isChecked()){//修改id
        //获取找到的记录
        QSqlRecord record = model->record(0);
        //修改记录
        record.setValue("id",ui->spinBox_newid->value());
        //写回到模型
        model->setRecord(0,record);
    }
    else if(model->rowCount()==1 && ui->radioButton_newname->isChecked()){//修改name
        //获取找到的记录
        QSqlRecord record = model->record(0);
        //修改记录
        record.setValue("name",ui->lineEdit_newname->text());
        //写回到模型
        model->setRecord(0,record);
    }
    else if(model->rowCount()==1 && ui->radioButton_newage->isChecked()){//修改id
        //获取找到的记录
        QSqlRecord record = model->record(0);
        //修改记录
        record.setValue("age",ui->spinBox_newage->value());
        //写回到模型
        model->setRecord(0,record);
    }

    //提交数据库
    model->submitAll();

    //刷新显示
    on_pushButton_select_clicked();
}
