#include "sqllogin.h"
#include "ui_sqllogin.h"
#include <QMessageBox>
#include <QCryptographicHash>
#include <QDebug>

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
}

SQLLogin::~SQLLogin()
{
    db.close();
    delete ui;
}

//注册 ------- 插入
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

    //构造sql语句
    QString sql = QString("insert into user(username,password) values('%1','%2')").arg(username).arg(password);

    //执行sql语句
    QSqlQuery query;
    if(!query.exec(sql)){
        QMessageBox::warning(this,"提示","注册失败!");
    }
    else{
        QMessageBox::information(this,"提示","注册成功!");
    }
}

//登录 ------ 查询
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

    //构造sql语句
    QString sql = QString("select * from user where username='%1' and password='%2'").arg(username).arg(password);

    //执行sql语句
    QSqlQuery query;
    if(!query.exec(sql)){
        QMessageBox::warning(this,"提示","查询失败!");
        return;
    }


    //查看有没有结果返回
    if(query.next()){
        QMessageBox::information(this,"提示","登录成功!");
    }
    else{
        QMessageBox::warning(this,"提示","用户名或密码错误!");
    }
}

//退出
void SQLLogin::on_pushButton_exit_clicked()
{
    this->close();
}

//回车
void SQLLogin::on_lineEdit_password_returnPressed()
{
    on_pushButton_login_clicked();
}
