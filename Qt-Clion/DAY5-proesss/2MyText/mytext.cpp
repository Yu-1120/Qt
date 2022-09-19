#include "mytext.h"
#include "ui_mytext.h"
#include "find.h"
#include "replace.h"
#include <QDebug>
#include <QFontDialog>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QColorDialog>

MyText::MyText(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyText)
{
    ui->setupUi(this);

    oper_lab = new QLabel(this);
    pos_lab = new QLabel(this);

    //添加到状态栏
    ui->statusbar->addWidget(oper_lab);
    ui->statusbar->addWidget(pos_lab);

    filepath = "~.txt";
    open_flag = false;//默认没有打开文件
    //设置窗口标题
    this->setWindowTitle(filepath);
}

MyText::~MyText()
{
    delete ui;
}

//保存内容到指定文件
bool MyText::save_file(QString &filename)
{
    //打开文件
    QFile file(filename);
    if(!file.open(QFile::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,"提示","保存的文件打开失败!");
        return false;
    }

    //使用文本流对象写文件
    QTextStream out(&file);
    out<<ui->textEdit->toPlainText();

    //关闭文件
    file.close();
    //设置标志和记录文件路径
    open_flag = true;
    filepath = filename;
    //将当前文件名设置为窗口标题
    this->setWindowTitle(filepath);

    return true;
}

//是否有内容需要保存
void MyText::is_saveornot()
{
    //查看QTextEdit是否有新修改的内容
    if(ui->textEdit->document()->isModified()){//有
        if(QMessageBox::Yes==QMessageBox::information(this,"提示","修改的内容未保存,是否需要保存?",QMessageBox::Yes|QMessageBox::No)){
            //保存
            on_action_save_triggered();
        }
    }
}

//点击菜单槽函数 ----- 新建
void MyText::on_action_new_triggered()
{
    //检查是否有内容需要保存
    is_saveornot();

    //设置为初始状态
    filepath = "~.txt";
    open_flag = false;
    //设置窗口标题
    this->setWindowTitle(filepath);

    //内容清空
    ui->textEdit->clear();

    oper_lab->setText("新建成功");
}

void MyText::on_action_open_triggered()
{
    //检查是否有内容需要保存
    is_saveornot();

    //弹出文件对话框得到打开文件的路径
    QString name = QFileDialog::getOpenFileName(this,"打开","D:\\GZFX2108\\01-Qt\\day04");

    if(!name.isEmpty()){
        //用QFile打开文件
        QFile file(name);
        if(!file.open(QFile::ReadOnly|QFile::Text)){
            //弹框提示
            QMessageBox::warning(this,"提示","打开文件失败!");
            return;
        }

        //读出文件内容显示到QTextEdit
        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());

        //关闭文件
        file.close();
        //设置文件名和标题
        filepath = name;
        open_flag = true;
        this->setWindowTitle(filepath);

        oper_lab->setText("打开成功");
    }


}

//保存
void MyText::on_action_save_triggered()
{
    //查看当前是否打开了文件
    if(open_flag){
        //将内容写入文件
        if(save_file(filepath)){
            //更新编辑器的状态 ----- 无新修改的内容
            ui->textEdit->document()->setModified(false);
        }
    }
    else{//另存为
        on_action_saveas_triggered();
    }
}

void MyText::on_action_saveas_triggered()
{
    //弹出文件对话框得到保存文件的路径
    QString name = QFileDialog::getSaveFileName(this,"保存","D:\\GZFX2108\\01-Qt\\day04");

    if(!name.isEmpty()){
        //将内容写入文件
        if(save_file(name)){
            //更新编辑器的状态 ----- 无新修改的内容
            ui->textEdit->document()->setModified(false);
        }
    }
}

//退出
void MyText::on_action_exit_triggered()
{
    //检查是否有内容需要保存
    is_saveornot();

    //关闭窗口
    //this->close();
    //直接退出程序
    qApp->exit();
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

//查找
void MyText::on_action_find_triggered()
{
    //获取光标选中的内容
    QString str = ui->textEdit->textCursor().selectedText();

    //显示查找界面
    Find fd(str);//参数是大传小的快捷键的

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

//替换
void MyText::on_action_replay_triggered()
{
    //获取光标选中的内容
    QString str = ui->textEdit->textCursor().selectedText();

    //显示查找界面
    Replace rp(str);

    //连接信号和槽
    QObject::connect(&rp,&Replace::replace_str,this,[&](const QString src,const QString dest,bool cs,bool dir){
        //如果光标选中内容和替换内容相同，替换
        if(ui->textEdit->textCursor().selectedText()==src){
            ui->textEdit->textCursor().removeSelectedText();//删除
            ui->textEdit->textCursor().insertText(dest);//插入
        }
        else{
            if(cs){//区分大小写
                if(dir){//向下
                    //调用文本编辑器的查找方法
                    if(!ui->textEdit->find(src,QTextDocument::FindCaseSensitively)){//区分大小写
                        //没找到,弹框提示
                        QMessageBox::warning(this,"提示","找不到该内容!");
                    }
                    else{
                        ui->textEdit->textCursor().removeSelectedText();//删除
                        ui->textEdit->textCursor().insertText(dest);//插入
                    }
                }
                else{//向上
                    if(!ui->textEdit->find(src,QTextDocument::FindCaseSensitively|QTextDocument::FindBackward)){//区分大小写
                        //没找到,弹框提示
                        QMessageBox::warning(this,"提示","找不到该内容!");
                    }
                    else{
                        ui->textEdit->textCursor().removeSelectedText();//删除
                        ui->textEdit->textCursor().insertText(dest);//插入
                    }
                }
            }
            else{//不区分大小写
                if(dir){//向下
                    //调用文本编辑器的查找方法
                    if(!ui->textEdit->find(src)){//区分大小写
                        //没找到,弹框提示
                        QMessageBox::warning(this,"提示","找不到该内容!");
                    }
                    else{
                        ui->textEdit->textCursor().removeSelectedText();//删除
                        ui->textEdit->textCursor().insertText(dest);//插入
                    }
                }
                else{//向上
                    if(!ui->textEdit->find(src,QTextDocument::FindBackward)){//区分大小写
                        //没找到,弹框提示
                        QMessageBox::warning(this,"提示","找不到该内容!");
                    }
                    else{
                        ui->textEdit->textCursor().removeSelectedText();//删除
                        ui->textEdit->textCursor().insertText(dest);//插入
                    }
                }
            }
        }
    });

    rp.exec();
}

//全选
void MyText::on_action_all_triggered()
{
    ui->textEdit->selectAll();
}

//字体
void MyText::on_action_font_triggered()
{
    bool flag = true;
    QFont f = QFontDialog::getFont(&flag,this);

    ui->textEdit->setFont(f);
}

void MyText::on_action_redo_triggered()
{
    ui->textEdit->redo();
}

//光标位置改变信号
void MyText::on_textEdit_cursorPositionChanged()
{
    QString str = QString("第%1行,第%2列").
            arg(ui->textEdit->textCursor().blockNumber()+1).
            arg(ui->textEdit->textCursor().columnNumber()+1);

    //显示到状态栏
    pos_lab->setText(str);
}

//修改颜色
void MyText::on_action_color_triggered()
{
    QColor c = QColorDialog::getColor(Qt::black,this,"设置颜色");

    ui->textEdit->setTextColor(c);
}
