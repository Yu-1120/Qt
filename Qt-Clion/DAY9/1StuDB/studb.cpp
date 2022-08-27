#include "studb.h"
#include "ui_studb.h"
#include <QDebug>
#include <QMessageBox>

StuDB::StuDB(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StuDB)
{
    ui->setupUi(this);

    //初始化模型
    model = new QStandardItemModel(this);
    model->setHorizontalHeaderItem(0,new QStandardItem("id"));
    model->setHorizontalHeaderItem(1,new QStandardItem("name"));
    model->setHorizontalHeaderItem(2,new QStandardItem("age"));
    //绑定模型和表格
    ui->tableView->setModel(model);

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

    //禁止表名输入框和建表按钮
    ui->lineEdit_tablename->setEnabled(false);
    ui->pushButton_create->setEnabled(false);

    ui->pushButton_insert->setEnabled(true);
    ui->pushButton_select->setEnabled(true);
    ui->pushButton_delete->setEnabled(true);
    ui->pushButton_update->setEnabled(true);
}

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
    on_pushButton_select_clicked();
}

//回调函数
static int stu_callback(void *arg,int col,char **str,char **name)
//101行用到
{
    //恢复对象  //强转类型
    StuDB *db = static_cast<StuDB *>(arg);

    for(int i=0;i<col;i++){
        //qDebug()<<name[i]<<":"<<str[i];
        //将查询结果显示到model上
                /*
        void QStandardItemModel::setItem(int row, int column, QStandardItem *item)

        将给定行和列的项设置为项。模型获得该项的所有权。如果需要，行数和列数将增加以适应该项。在给定位置(如果有)的前一项将被删除。

        这个函数是在Qt 4.2中引入的。
        */
        db->model->setItem(db->count,i,new QStandardItem(str[i]));
    }
    db->count++;

    return SQLITE_OK;
}

//查询
void StuDB::on_pushButton_select_clicked()
{
    QString sql = QString("select * from %1;").arg(ui->lineEdit_tablename->text());

    count = 0;

    //删除所有行
    model->removeRows(0,model->rowCount());

    //执行sql ----- 将本窗口对象传递给回调函数
    int res = sqlite3_exec(pDb,sql.toStdString().c_str(),stu_callback,this,NULL);
    if(res!=SQLITE_OK){
        QMessageBox::warning(this,"提示","查询失败!");
    }
}

//删除
void StuDB::on_pushButton_delete_clicked()
{
    QString sql = QString("delete from %1 where id=%2;").
                    arg(ui->lineEdit_tablename->text()).arg(ui->spinBox_deleteid->value());
    qDebug()<<sql;
    //执行sql
    int res = sqlite3_exec(pDb,sql.toStdString().c_str(),NULL,NULL,NULL);
    if(res!=SQLITE_OK){
        QMessageBox::warning(this,"提示","删除失败!");
        return;
    }

    //刷新显示
    on_pushButton_select_clicked();
}

//更新
void StuDB::on_pushButton_update_clicked()
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
    int res = sqlite3_exec(pDb,sql.toStdString().c_str(),NULL,NULL,NULL);
    if(res!=SQLITE_OK){
        QMessageBox::warning(this,"提示","更新失败!");
        return;
    }

    //刷新显示
    on_pushButton_select_clicked();
}
