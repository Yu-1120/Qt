#include "mytext.h"
#include "find.h"
#include "relay.h"
#include "ui_mytext.h"
#include <QDebug>
#include <QFileDialog>//文件对话框
#include <QFontDialog>//字体对话框
#include <QColorDialog>//颜色对话框
#include <QDateTime>
#include <QFile>
#include <QDir>
#include <QString>
#include <QMessageBox>
MyText::MyText(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyText)
{
    ui->setupUi(this);

}

QString   createMultipleFolders(const QString path);             // 创建文件夹
QString   createFile(const QString path,const QString suffix);
MyText::~MyText()
{
    delete ui;
}
//点击菜单槽函数 ----- 新建
void MyText::on_action_new_triggered()
{

    QString path = "E:";

    QString createTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH-mm-ss");//文件名不能用“:”命名
       QString fileName = path + "\\" + createTime + ".txt";
       QFile file(fileName);

       if(file.exists())
       {
             qDebug()<<"文件存在";
             //这里可以数设置弹窗
       }
       else
       {
           // 如果没有此文件，就创建
           file.open(QFile::WriteOnly|QFile::Text|QIODevice::Append);
           if(file.exists())
           {
               qDebug()<<"创建";

               //弹框提示
               QMessageBox box;
               //标题
               box.setWindowTitle("提示");
               //文字信息
               box.setText("创建文件成功");
               //图标
               box.setIcon(QMessageBox::Information);
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

           }
       }



}

void MyText::on_action_open_triggered()//点击事件
//triggered--触发
{
    QString path = QFileDialog::getOpenFileName(this, "打开文件", "E:\\");
       QFile file(path);
       if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
       {
           return;
       }

       QByteArray allArray = file.readAll();
       QString allStr = QString(allArray);
        qDebug()<<allStr;//读取文件里的数字
//         allStr = textEdit;
       file.close();

}
/*
QT控件之（TextEdit）的值的获取

 QString str = ui->textEdit->toPlainText();
    qDebug()<<"str=="<<str;


*/
void MyText::on_action_save_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, "保存", "E:\\", "*.txt");
    qDebug()<<path;//读取文件里的数字
}

void MyText::on_action_saveas_triggered()
{

    QString path = QFileDialog::getSaveFileName(this, "保存"
                                                  , "E:\\", "*.txt");
      QFile file(path);
      file.open(QIODevice::WriteOnly | QIODevice::Text);
      QTextStream out(&file);
      QString str = ui->textEdit->toPlainText();
      out << str;
      file.close();
}

void MyText::on_action_exit_triggered()
{
        QMainWindow::close();//调用本窗口的关闭
}

//撤销
void MyText::on_action_undo_triggered()
{
    ui->textEdit->undo();
}

void MyText::on_action_cut_triggered()
{
    ui->textEdit->cut();
}

void MyText::on_action_copy_triggered()
{
    ui->textEdit->copy();
}

void MyText::on_action_paste_triggered()
{
    ui->textEdit->paste();
}

void MyText::on_action_del_triggered()
{
    //删除光标选中的内容
    ui->textEdit->textCursor().removeSelectedText();
}

void MyText::on_action_find_triggered()
{

//  Find fd; //类名那里不能传，无参构造
//  fd.exec();
    //获取光标选中的内容
    QString str = ui->textEdit->textCursor().selectedText();

    //显示查找界面
    Find fd(str);

    //连接信号和槽
    QObject::connect(&fd,&Find::find_str,this,[&](const QString s,bool cs,bool dir){
        if(cs){//区分大小写
            if(dir){//向下
                //调用文本编辑器的查找方法
                if(!ui->textEdit->find(s,QTextDocument::FindCaseSensitively)){//区分大小写
                    //没找到,弹框提示
                    QMessageBox::warning(this,"提示","找不到该内容!");
                }
            }
            else{//向上
                if(!ui->textEdit->find(s,QTextDocument::FindCaseSensitively|QTextDocument::FindBackward)){//区分大小写
                    //没找到,弹框提示
                    QMessageBox::warning(this,"提示","找不到该内容!");
                }
            }
        }
        else{//不区分大小写
            if(dir){//向下
                //调用文本编辑器的查找方法
                if(!ui->textEdit->find(s)){//区分大小写
                    //没找到,弹框提示
                    QMessageBox::warning(this,"提示","找不到该内容!");
                }
            }
            else{//向上
                if(!ui->textEdit->find(s,QTextDocument::FindBackward)){//区分大小写
                    //没找到,弹框提示
                    QMessageBox::warning(this,"提示","找不到该内容!");
                }
            }
        }
    });

    fd.exec();
}

void MyText::on_action_replay_triggered()
{

    Relay ry;



    ry.exec();


}
//全选
void MyText::on_action_all_triggered()
{
    ui->textEdit->selectAll();
}

//字体
void MyText::on_action_font_triggered()
{

    bool flag = true;//这个方法要传个真给他
    QFont f = QFontDialog::getFont(&flag,this);
    ui->textEdit->setFont(f);
}

void MyText::on_action_redo_triggered()
{
ui->textEdit->redo();
}


