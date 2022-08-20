#include "login.h"
#include <QDebug>
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QDialog(parent)
{
    //修改标题
    this->setWindowTitle("王者荣耀");

    username_lab = new QLabel("username:",this);
    password_lab = new QLabel("password",this);
    username_edit = new QLineEdit(this);
    password_edit = new QLineEdit(this);
    login_btn = new QPushButton("登录",this);
    exit_btn = new QPushButton("退出",this);

    //设置QLineEdit的显示方式
    password_edit->setEchoMode(QLineEdit::Password);

    lyt = new QGridLayout;
    lyt->addWidget(username_lab,0,0);
    lyt->addWidget(username_edit,0,1);
    lyt->addWidget(password_lab,1,0);
    lyt->addWidget(password_edit,1,1);
    lyt->addWidget(login_btn,2,0);
    lyt->addWidget(exit_btn,2,1);

    //设置窗口布局管理器
    this->setLayout(lyt);

    //退出按钮连接关闭窗口的槽
    QObject::connect(exit_btn,&QPushButton::clicked,this,&Login::close);
    //连接登录信号和槽
    QObject::connect(login_btn,&QPushButton::clicked,this,[&](){
        if(username_edit->text().isEmpty()||password_edit->text().isEmpty()){//用户名或密码为空
            qDebug()<<"用户名或密码为空!";
            /*
            //弹框提示
            QMessageBox box;
            //标题
            box.setWindowTitle("提示");
            //文字信息
            box.setText("用户名或密码为空");
            //图标
            box.setIcon(QMessageBox::Warning);
            //按钮
            box.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
            //显示消息对话框并等待用户操作
            int res = box.exec();
            if(QMessageBox::Ok==res){
                qDebug()<<"QMessageBox::Ok!";
            }
            else if(QMessageBox::Cancel==res){
                qDebug()<<"QMessageBox::Cancel!";
            }
            */

            if(QMessageBox::Ok==QMessageBox::warning(this,"提示","用户名或密码为空",QMessageBox::Ok|QMessageBox::Cancel)){
                qDebug()<<"QMessageBox::Ok!";
            }
            else{
                qDebug()<<"QMessageBox::Cancel!";
            }
        }
        else if(username_edit->text()=="admin"&&password_edit->text()=="12345"){
            qDebug()<<"登录成功!";
            /*
            if(QMessageBox::Ok==QMessageBox::information(this,"提示","登录成功",QMessageBox::Ok|QMessageBox::Cancel)){
                qDebug()<<"QMessageBox::Ok!";
            }
            else{
                qDebug()<<"QMessageBox::Cancel!";
            }
            */

            //返回accept，进入主界面
            this->accept();
        }
        else{
            qDebug()<<"用户名或密码错误";
            if(QMessageBox::Ok==QMessageBox::warning(this,"提示","用户名或密码错误",QMessageBox::Ok|QMessageBox::Cancel)){
                qDebug()<<"QMessageBox::Ok!";
                username_edit->clear();
                password_edit->clear();
            }
            else{
                qDebug()<<"QMessageBox::Cancel!";
            }
        }
    });
}

Login::~Login()
{
}

