#include "widgetitem.h"
#include <QDebug>

WidgetItem::WidgetItem(QWidget *parent)
    : QWidget(parent)
{
    lab = new QLabel("你好年后");
    btn = new QPushButton("点击",this);
    cbox = new QCheckBox("大小写",this);
    sbox = new QSpinBox(this);
    //设置自旋框范围
    sbox->setRange(1,1000);
    sbox->setValue(200);
    rbtn1 = new QRadioButton("男",this);
    rbtn2 = new QRadioButton("女",this);
    sld = new QSlider(this);
    //设置滑动条范围和默认值
    sld->setRange(0,100);
    sld->setValue(50);
    pbar = new QProgressBar(this);
    //设置进度条的范围和默认值
    pbar->setRange(0,100);
    pbar->setValue(50);
    lw = new QListWidget(this);
    lw->addItem("一月");
    lw->addItem("四月");
    lw->addItem("八月");
    cb = new QComboBox(this);
    cb->addItem("VIP1");
    cb->addItem("VIP4");
    cb->addItem("VIP8");

    lyt = new QVBoxLayout;
    lyt->addWidget(lab);
    lyt->addWidget(btn);
    lyt->addWidget(cbox);
    lyt->addWidget(sbox);
    lyt->addWidget(rbtn1);
    lyt->addWidget(rbtn2);
    lyt->addWidget(sld);
    lyt->addWidget(pbar);
    lyt->addWidget(lw);
    lyt->addWidget(cb);

    QObject::connect(btn,&QPushButton::clicked,this,[&](){
        /*if(cbox->isChecked()){
            qDebug()<<"选中";
        }
        else{
            qDebug()<<"未选中";
        }


        if(rbtn1->isChecked()){
            qDebug()<<"选中";
        }
        else{
            qDebug()<<"未选中";
        }


        QList<QListWidgetItem *> lt = lw->selectedItems();
        for(auto x:lt){
            qDebug()<<x->text();
        }
        */

        qDebug()<<cb->currentText();
    });

    //QCheckBox信号
    QObject::connect(cbox,&QCheckBox::stateChanged,this,[&](int n){
        qDebug()<<n;
    });
    //QSpinBox信号 ------ valueChanged在子类中被重写，必须指定那个int参数的信号
    QObject::connect(sbox,QOverload<int>::of(&QSpinBox::valueChanged),this,[&](int n){
        qDebug()<<n;
    });
    //QRadioButton信号
    QObject::connect(rbtn1,&QRadioButton::toggled,this,[&](bool c){
        qDebug()<<c;
    });
    //QSlider信号
    QObject::connect(sld,QOverload<int>::of(&QSlider::valueChanged),this,[&](int n){
        qDebug()<<n;
        //设置进度条
        pbar->setValue(n);
    });
    //QListWidget信号
    QObject::connect(lw,&QListWidget::itemDoubleClicked,this,[&](QListWidgetItem *item){
        qDebug()<<item->text();
    });
    //QComboBox信号
    QObject::connect(cb,&QComboBox::currentTextChanged,this,[&](const QString &s){
        qDebug()<<s;
    });

    this->setLayout(lyt);
}

WidgetItem::~WidgetItem()
{
}

