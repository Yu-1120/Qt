#include "widgetitem.h"
#include <QDebug>
#include <QTextCodec>

WidgetItem::WidgetItem(QWidget *parent)
        : QWidget(parent) {
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

    lab = new QLabel(QString::fromLocal8Bit("������"));
    btn = new QPushButton(QString::fromLocal8Bit("���"), this);
    //**************************��ѡ��:���Դ򹴵�******************************
    cbox = new QCheckBox(QString::fromLocal8Bit("��Сд"), this);
    //**********************************************************************
    //**************************//����������Χ*******************************
    sbox = new QSpinBox(this);
    sbox->setRange(1, 1000);
    sbox->setValue(200);
    //**********************************************************************
    manbtn = new QRadioButton(QString::fromLocal8Bit("��"), this);
    womanbtn = new QRadioButton(QString::fromLocal8Bit("Ů"), this);
    sld = new QSlider(this);
    //******************���û�������Χ��Ĭ��ֵ,��ֱ��******************************
    sld->setRange(0, 100);
    sld->setValue(50);
    //**********************���ý������ķ�Χ��Ĭ��ֵ*******************************
    pbar = new QProgressBar(this);
    pbar->setRange(0, 100);
    pbar->setValue(50);
    //**********************************************************************
    lw = new QListWidget(this);
    lw->addItem(QString::fromLocal8Bit("һ��-January"));
    lw->addItem(QString::fromLocal8Bit("����-April"));
    lw->addItem(QString::fromLocal8Bit("����-August"));
    //**********************************************************************
    cb = new QComboBox(this);
    cb->addItem(QString::fromLocal8Bit("VIP1"));
    cb->addItem(QString::fromLocal8Bit("VIP4"));
    cb->addItem(QString::fromLocal8Bit("VIP8"));
    cb->addItem(QString::fromLocal8Bit("ϴ�ų��ռ�VIP"));
    //**********************************************************************
    lyt = new QVBoxLayout;//ˮƽ
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
//        if (manbtn->isChecked()) { //�ж��Ǹ��еİ�ť��û�б�����
//            qDebug() << "choice ";
//        } else {
//            qDebug() << "no choice";
//        }
        QList<QListWidgetItem *> lt = lw->selectedItems();
        for (auto x: lt) {
            qDebug() << x->text();//������clion����̨������
        }
        //-------------
        qDebug() << cb->currentText();
    });

    //-----------------------------------------------------------
    //QCheckBox�ź�
    QObject::connect(cbox, &QCheckBox::stateChanged, this, [&](int n) {
        qDebug() << n;
        //Ϊʲô���2
    });
    //********************************************************

    //-----------------------------------------------------------
    //QSpinBox�ź� ------ valueChanged�������б���д������ָ���Ǹ�int�������ź�
    //����Ҳ�������ķ�������������Ҫ��д
    QObject::connect(sbox, QOverload<int>::of(&QSpinBox::valueChanged), this, [&](int n) {
        qDebug() << n;
    });
    //********************************************************

    //-----------------------------------------------------------
    //QRadioButton�ź�
    QObject::connect(manbtn, &QRadioButton::toggled, this, [&](bool c) {
        //toggled ��ת
        qDebug() << c;
    });
    //********************************************************

    //-----------------------------------------------------------
    //QSlider�ź�
    QObject::connect(sld, QOverload<int>::of(&QSlider::valueChanged), this, [&](int n) {
        qDebug() << n;
        //���ý�����
        pbar->setValue(n);
    });


    //-----------------------------------------------------------
    //QListWidget�ź�
    QObject::connect(lw, &QListWidget::itemDoubleClicked, this, [&](QListWidgetItem *item) {
        qDebug() << item->text();
    });


    //-----------------------------------------------------------
    //QComboBox�ź�
    QObject::connect(cb, &QComboBox::currentTextChanged, this, [&](const QString &s) {
        qDebug() << s;
    });

    this->setLayout(lyt);
}

WidgetItem::~WidgetItem() {
}

