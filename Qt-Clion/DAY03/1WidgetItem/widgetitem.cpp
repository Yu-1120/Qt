#include "widgetitem.h"
#include <QDebug>
#include <QTextCodec>

WidgetItem::WidgetItem(QWidget *parent)
        : QWidget(parent) {
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

    lab = new QLabel(QString::fromLocal8Bit("你好年后"));
    btn = new QPushButton(QString::fromLocal8Bit("点击"), this);
    //**************************复选框:可以打勾的******************************
    cbox = new QCheckBox(QString::fromLocal8Bit("大小写"), this);
    //**********************************************************************
    //**************************//设置自旋框范围*******************************
    sbox = new QSpinBox(this);
    sbox->setRange(1, 1000);
    sbox->setValue(200);
    //**********************************************************************
    manbtn = new QRadioButton(QString::fromLocal8Bit("男"), this);
    womanbtn = new QRadioButton(QString::fromLocal8Bit("女"), this);
    sld = new QSlider(this);
    //******************设置滑动条范围和默认值,竖直的******************************
    sld->setRange(0, 100);
    sld->setValue(50);
    //**********************设置进度条的范围和默认值*******************************
    pbar = new QProgressBar(this);
    pbar->setRange(0, 100);
    pbar->setValue(50);
    //**********************************************************************
    lw = new QListWidget(this);
    lw->addItem(QString::fromLocal8Bit("一月-January"));
    lw->addItem(QString::fromLocal8Bit("四月-April"));
    lw->addItem(QString::fromLocal8Bit("八月-August"));
    //**********************************************************************
    cb = new QComboBox(this);
    cb->addItem(QString::fromLocal8Bit("VIP1"));
    cb->addItem(QString::fromLocal8Bit("VIP4"));
    cb->addItem(QString::fromLocal8Bit("VIP8"));
    cb->addItem(QString::fromLocal8Bit("洗脚城终极VIP"));
    //**********************************************************************
    lyt = new QVBoxLayout;//水平
    lyt->addWidget(lab);
    lyt->addWidget(btn);
    lyt->addWidget(cbox);
    lyt->addWidget(sbox);
    lyt->addWidget(manbtn);
    lyt->addWidget(womanbtn);
    lyt->addWidget(sld);
    lyt->addWidget(pbar);
    lyt->addWidget(lw);
    lyt->addWidget(cb);
//********************************************************
    QObject::connect(btn, &QPushButton::clicked, this, [&]() {
//        if (cbox->isChecked()) {
//            qDebug() << "choice";
//        } else {
//            qDebug() << "no choice";
//        }
//
//
//        if (manbtn->isChecked()) { //判断那个男的按钮有没有被按下
//            qDebug() << "choice ";
//        } else {
//            qDebug() << "no choice";
//        }
        QList<QListWidgetItem *> lt = lw->selectedItems();
        for (auto x: lt) {
            qDebug() << x->text();//这里用clion控制台会乱码
        }
        //-------------
        qDebug() << cb->currentText();
    });

    //-----------------------------------------------------------
    //QCheckBox信号
    QObject::connect(cbox, &QCheckBox::stateChanged, this, [&](int n) {
        qDebug() << n;
        //为什么输出2
    });
    //********************************************************

    //-----------------------------------------------------------
    //QSpinBox信号 ------ valueChanged在子类中被重写，必须指定那个int参数的信号
    //父类也有这样的方法，适所以需要重写
    QObject::connect(sbox, QOverload<int>::of(&QSpinBox::valueChanged), this, [&](int n) {
        qDebug() << n;
    });
    //********************************************************

    //-----------------------------------------------------------
    //QRadioButton信号
    QObject::connect(manbtn, &QRadioButton::toggled, this, [&](bool c) {
        //toggled 翻转
        qDebug() << c;
    });
    //********************************************************

    //-----------------------------------------------------------
    //QSlider信号
    QObject::connect(sld, QOverload<int>::of(&QSlider::valueChanged), this, [&](int n) {
        qDebug() << n;
        //设置进度条
        pbar->setValue(n);
    });


    //-----------------------------------------------------------
    //QListWidget信号
    QObject::connect(lw, &QListWidget::itemDoubleClicked, this, [&](QListWidgetItem *item) {
        qDebug() << item->text();
    });


    //-----------------------------------------------------------
    //QComboBox信号
    QObject::connect(cb, &QComboBox::currentTextChanged, this, [&](const QString &s) {
        qDebug() << s;
    });

    this->setLayout(lyt);
}

WidgetItem::~WidgetItem() {
}

