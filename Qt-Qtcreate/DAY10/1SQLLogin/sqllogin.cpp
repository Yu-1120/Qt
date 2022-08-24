#include "sqllogin.h"
#include "ui_sqllogin.h"
#include <QMessageBox>
#include <QCryptographicHash>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlError>

SQLLogin::SQLLogin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SQLLogin)
{
    ui->setupUi(this);

    //添加数据库驱动
    db = QSqlDatabase::addDatabase("QSQLITE");
    //指定数据库文件路径
    db.setDatabaseName("user.db");
    //打开数据库
    if(!db.open()){
        QMessageBox::warning(this,"提示","打开数据库失败");
    }

    //创建表格，主键为id自动增长，用户名和密码不允许为空，用户名不允许重复
    QString sql("create table if not exists user(id integer primary key autoincrement,username text unique not NULL,password text not NULL)");

    //执行sql语句
    QSqlQuery query;
    if(!query.exec(sql)){
        QMessageBox::warning(this,"提示","建表失败!");
    }

    model = new QSqlTableModel(this);
    //模型绑定表
    model->setTable("user");
}

SQLLogin::~SQLLogin()
{
    db.close();
    delete ui;
}

//注册
void SQLLogin::on_pushButton_reg_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    //对密码进行Md5的加密
    //1.创建QCryptographicHash加密对象
    QCryptographicHash hash(QCryptographicHash::Md5);
    //2.放入要加密的数据
    hash.addData(password.toUtf8());
    //3.取出加密结果
    QByteArray arr = hash.result();
    password = arr.toHex();
    qDebug()<<password;

    //获取空记录
    QSqlRecord record = model->record();
    //设置记录中字段的值
    record.setValue("username",username);
    record.setValue("password",password);

    //插入
    if(!model->insertRecord(-1,record)){
        QMessageBox::warning(this,"提示",QString("注册失败:%1").arg(model->lastError().text()));
        return;
    }

    //提交
    model->submitAll();

    //提示注册成功
    QMessageBox::information(this,"提示","注册成功!");

    ui->lineEdit_username->clear();
    ui->lineEdit_password->clear();
}

//登录
void SQLLogin::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    //对密码进行Md5的加密
    //1.创建QCryptographicHash加密对象
    QCryptographicHash hash(QCryptographicHash::Md5);
    //2.放入要加密的数据
    hash.addData(password.toUtf8());
    //3.取出加密结果
    QByteArray arr = hash.result();
    password = arr.toHex();
    qDebug()<<password;

    //设置过滤器
    model->setFilter(QString("username='%1' and password='%2'").arg(username).arg(password));
    model->select();

    if(model->rowCount()==1){
        QMessageBox::information(this,"提示","登录成功!");
    }
    else{
        QMessageBox::warning(this,"提示","用户名或密码错误!");
    }

    ui->lineEdit_username->clear();
    ui->lineEdit_password->clear();
}

//注销
void SQLLogin::on_pushButton_unreg_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    //对密码进行Md5的加密
    //1.创建QCryptographicHash加密对象
    QCryptographicHash hash(QCryptographicHash::Md5);
    //2.放入要加密的数据
    hash.addData(password.toUtf8());
    //3.取出加密结果
    QByteArray arr = hash.result();
    password = arr.toHex();
    qDebug()<<password;

    //设置过滤器
    model->setFilter(QString("username='%1' and password='%2'").arg(username).arg(password));
    model->select();

    if(model->rowCount()==1){
        model->removeRow(0);
        model->submitAll();

        QMessageBox::information(this,"提示","注销成功!");
    }
    else{
        QMessageBox::warning(this,"提示","用户名或密码错误!");
    }

    ui->lineEdit_username->clear();
    ui->lineEdit_password->clear();
}
