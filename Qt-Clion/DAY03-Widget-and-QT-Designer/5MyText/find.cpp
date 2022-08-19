#include "find.h"
#include "ui_find.h"
//����
Find::Find(QString s,QWidget *parent) :
//Find::Find(QWidget *parent) :
//    �������ﲻ�ܴ����޲ι���
    QDialog(parent),
    ui(new Ui::Find)
{
    ui->setupUi(this);

    //�����ݹ������ַ�����ʾ��lineEdit  /�ѹ��캯�����string����ȥ
    ui->lineEdit->setText(s);
    //����ַ���Ϊ�գ���ֹ���Ұ�ť
    if(s.isEmpty()){
        ui->pushButton_find->setEnabled(false);
    }
}


Find::~Find()
{
    delete ui;
}

//����
void Find::on_pushButton_find_clicked()
{
    //ȡ�����ҵ��ַ���
    QString str = ui->lineEdit->text();

    if(ui->checkBox->isChecked()){//���ִ�Сд true
        if(ui->radioButton_down->isChecked()){//���� true
            emit find_str(str,true,true);
        }
        else{
            emit find_str(str,true,false);
        }
    }
    else{//�����ִ�Сд
        if(ui->radioButton_down->isChecked()){//���� true
            emit find_str(str,false,true);
        }
        else{
            emit find_str(str,false,false);
        }
    }
}

void Find::on_pushButton_cancel_clicked()
{
    this->done(0);
}

//�����˱༭����
void Find::on_lineEdit_textEdited(const QString &arg1)
{
    if(arg1.isEmpty()){
        ui->pushButton_find->setEnabled(false);
    }
    else{
        ui->pushButton_find->setEnabled(true);
    }
}
