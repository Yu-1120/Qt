#include "mytext.h"
#include "ui_mytext.h"
#include <QDebug>

MyText::MyText(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyText)
{
    ui->setupUi(this);
}

MyText::~MyText()
{
    delete ui;
}

//点击菜单槽函数 ----- 新建
void MyText::on_action_new_triggered()
{
    qDebug()<<"on_action_new_triggered";
}

void MyText::on_action_open_triggered()
{

}

void MyText::on_action_save_triggered()
{

}

void MyText::on_action_saveas_triggered()
{

}

void MyText::on_action_exit_triggered()
{

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

}

void MyText::on_action_replay_triggered()
{

}

//全选
void MyText::on_action_all_triggered()
{
    ui->textEdit->selectAll();
}

//字体
void MyText::on_action_font_triggered()
{

}

void MyText::on_action_redo_triggered()
{

}
