#include "smartsqlstu.h"
#include "ui_smartsqlstu.h"
#include <QMessageBox>
#include <QSqlError>

SmartSQLStu::SmartSQLStu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SmartSQLStu)
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

SmartSQLStu::~SmartSQLStu()
{
    db.close();
    delete ui;
}

//建表
void SmartSQLStu::on_pushButton_create_clicked()
{
    QString sql = QString("create table if not exists %1(id int unique,name ntext,age int)").
                    arg(ui->lineEdit_tablename->text());
    //执行sql ------ QSqlQuery对象在要执行时创建
    QSqlQuery query;
    if(!query.exec(sql)){
        QMessageBox::warning(this,"提示","建表失败!");
        return;
    }

    model->setTable(ui->lineEdit_tablename->text());
    //设置提交后生效
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //显示
    model->select();

    //禁止表名输入框和建表按钮
    ui->lineEdit_tablename->setEnabled(false);
    ui->pushButton_create->setEnabled(false);
}

//添加
void SmartSQLStu::on_pushButton_insert_clicked()
{
    //获取当前行数
    int row = model->rowCount();
    model->insertRow(row);//最后一行后插入
    int id = 100;
    model->setData(model->index(row,0),id);

    //提交
    model->submitAll();
}

//保存
void SmartSQLStu::on_pushButton_save_clicked()
{
    model->submitAll();
}

//撤销
void SmartSQLStu::on_pushButton_revert_clicked()
{
    model->revertAll();
}

//删除
void SmartSQLStu::on_pushButton_delete_clicked()
{
    //从表格中获取要删除的行
    int delrow = ui->tableView->currentIndex().row();
    //删除改行
    model->removeRow(delrow);

    //询问询问用户是否真的删除
    if(QMessageBox::Yes==QMessageBox::warning(this,"删除","确定删除本行吗?",QMessageBox::Yes|QMessageBox::No)){
        model->submitAll();
    }
    else{
        //撤销
        model->revert();
    }
}

void SmartSQLStu::on_pushButton_select_clicked()
{
    model->setTable(ui->lineEdit_tablename->text());
    model->select();
}
