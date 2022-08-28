#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget) {
    ui->setupUi(this);


    /*设置去掉窗口边框*/
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    /*设置全局文字字体颜色*/
    this->setStyleSheet("QLabel{color:#292929}");

    /*颜色画笔*/
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::white);

    /*当前温度文字字体样式*/
    label_temp = new QLabel(this);
    QFont ft_temp("Arial", 50, 75);
    label_temp->setFont(ft_temp);

    /*当前天气文字字体样式*/
    label_curr_weather = new QLabel(this);
    QFont ft_weather("Arial", 20, 75);
    label_curr_weather->setFont(ft_weather);
    label_curr_weather->setStyleSheet("color:#ffffff");

    /*当前城市和日期文字的字体颜色*/
    ui->label_curr_city->setStyleSheet("color:#ffffff");
    ui->label_curr_date->setStyleSheet("color:#ffffff");

    /*当前温度和天气状况文字的初始位置*/
    label_temp->move(180, 80);
    label_curr_weather->move(220, 200);

    /*折叠按钮的样式*/
    btn_fold = new QPushButton(this);
    btn_fold->setFixedSize(50, 50);
    btn_fold->setText("折叠");
    btn_fold->setStyleSheet(
            "QPushButton{font:Arial;color:#ffffff;font-size:20px;background-color:rgba(0,0,0,0);border:none}"
            "QPushButton:hover{font-size:22px;}");
    connect(btn_fold, SIGNAL(clicked(bool)), this, SLOT(slot_up()));
    btn_fold->move(380, 0);

    /*关闭按钮的样式*/
    QPushButton *btn_close = new QPushButton(this);
    btn_close->setFixedSize(50, 50);
    btn_close->setText("关闭");
    btn_close->setStyleSheet(
            "QPushButton{font:Arial;color:#ffffff;font-size:20px;background-color:rgba(0,0,0,0);border:none}"
            "QPushButton:hover{font-size:22px;}");
    btn_close->move(440, 0);
    connect(btn_close, SIGNAL(clicked(bool)), this, SLOT(close()));


    /*获取天气API*/
    QString str = "http://wthrcdn.etouch.cn/weather_mini?city=深圳";
    QUrl url(str);
    manager = new QNetworkAccessManager(this);
    request.setUrl(url);
    manager->get(request);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(doProcessfinished(QNetworkReply * )));


    /*获取当前日期时间*/
    QDateTime dt;
    QDate date;
    dt.setDate(date.currentDate());
    QString currentDate = dt.toString("MM-dd ddd");
    ui->label_curr_date->setText(currentDate);

}

void Widget::doProcessfinished(QNetworkReply *reply) {
    QByteArray arry = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(arry);
    if (doc.isNull())//为空，直接返回
        return;

    QJsonObject obj = doc.object();//将获取的数据转换为Json格式
    if (false == obj.contains("data"))//判断是否有包含“data”的对象，为空，直接返回
        return;

    QJsonValue val = obj.value("data");//获取“data”对象的
    if (!val.isObject())//为空，直接返回
        return;

    QJsonObject jsonDate = val.toObject();
    QString curr_temp = jsonDate.value("wendu").toString();//获取当前温度
    QString city = jsonDate.value("city").toString();//获取当前城市

    QJsonValue fore = jsonDate.value("forecast");
    if (fore.isArray()) {
        QJsonArray Jsonarry = fore.toArray();
        for (int i = 0; i < 4; i++) {
            QJsonObject weaobj = Jsonarry.at(i).toObject();//遍历获取

            QString high = weaobj.value("high").toString().mid(3);//最高温度
            QString low = weaobj.value("low").toString().mid(3, 2);//最低温度
            QString Week = weaobj.value("date").toString().mid(3);//星期
            QString weather = weaobj.value("type").toString();//天气

            if (i == 0) {//0为当天的天气情况
                /*当前温度赋值*/

                label_temp->setText(curr_temp + "℃");
                label_temp->adjustSize();
                /*当前天气状况赋值*/
                label_curr_weather->setText(weather);
                label_curr_weather->adjustSize();
                /*当前城市赋值*/
                ui->label_curr_city->setText(city);
                ui->label_curr_city->adjustSize();
                /*根据天气状况设置背景图*/
                set_weather_pic(weather);

            }
            if (i == 1) {
                /*设置未来第一天的信息*/
                ui->label_future_day_1->setText(Week);
                ui->label_future_weather_1->setText(weather);
                ui->label_future_temp_1->setText(low + "/" + high);
            }
            if (i == 2) {
                /*设置未来第二天的信息*/
                ui->label_future_day_2->setText(Week);
                ui->label_future_weather_2->setText(weather);
                ui->label_future_temp_2->setText(low + "/" + high);
            }
            if (i == 3) {
                /*设置未来第三天的信息*/
                ui->label_future_day_3->setText(Week);
                ui->label_future_weather_3->setText(weather);
                ui->label_future_temp_3->setText(low + "/" + high);
            }
        }

    }

}

void Widget::set_weather_pic(QString weather) {
    qDebug() << weather;
    QString Path;
    /*
     * libpng warning: iCCP: known incorrect sRGB profile
     *   QImage img; img.load("icon.png"); img.save("icon.png");
     *   ubuntu: convert infile.png outfile.png
     * */
    if (true == weather.contains("雨")) {
        Path = ":/res/pic/day-rain.png";
        QImage img;
        img.load(Path);
        img.save(Path);
        label_temp->setStyleSheet("color:#ffffff");
    } else if (true == weather.contains("晴")) {
        Path = ":/res/pic/day-sun.png";
        QImage img;
        img.load(Path);
        img.save(Path);
        label_temp->setStyleSheet("color:#ffffff");
    } else if (true == weather.contains("雪")) {
        Path = ":/res/pic/day-snow.png";
        QImage img;
        img.load(Path);
        img.save(Path);
        label_temp->setStyleSheet("color:#ffffff");
    } else if (true == weather.contains("多云")) {
        Path = ":/res/pic/cloudy.png";
        QImage img;
        img.load(Path);
        img.save(Path);
        label_temp->setStyleSheet("color:#ffffff");
    } else {
        Path = ":/res/pic/all.png";
        QImage img;
        img.load(Path);
        img.save(Path);
        label_temp->setStyleSheet("color:#ffffff");
    }

    //设置背景图片
    ui->frame_pic->setAutoFillBackground(true);
    QPalette palette = ui->frame_pic->palette();
    palette.setBrush(QPalette::Window,
                     QBrush(QPixmap(Path).scaled(// 缩放背景图.
                             ui->frame_pic->size(),
                             Qt::IgnoreAspectRatio,
                             Qt::SmoothTransformation)));// 使用平滑的缩放方式
    ui->frame_pic->setPalette(palette);

}


//重写鼠标事件,实现除去标题栏后任然能实现窗口移动
void Widget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        mousePress = true;
    }
    //窗口移动距离
    movePoint = event->globalPos() - pos();
}

void Widget::mouseReleaseEvent(QMouseEvent *event) {
    Q_UNUSED(event)
    mousePress = false;
}

void Widget::mouseMoveEvent(QMouseEvent *event) {
    if (mousePress) {
        QPoint movePos = event->globalPos();//窗口初始位置
        move(movePos - movePoint);
    }
}


void Widget::slot_up() {
    static bool status = true;
    if (status) {
        up();
    } else {
        down();
    }
    status = !status;

}

//当上升和下降同时点击的时候,会出现bug,所有加个锁上就可以了

/*实现折叠功能*/
void Widget::up() {

    btn_fold->setText("展开");
    //上升

    /*当前温度文字的移动动画*/
    QPropertyAnimation *animation_text_temp_left = new QPropertyAnimation(label_temp, "pos");
    animation_text_temp_left->setStartValue(label_temp->pos());
    animation_text_temp_left->setEndValue(QPoint(ui->frame_pic->pos().x() + 70, label_temp->pos().y() - 80));
    animation_text_temp_left->setDirection(QAbstractAnimation::Direction::Forward);
    animation_text_temp_left->setDuration(500);

    /*当前天气状况文字的移动动画*/
    QPropertyAnimation *animation_text_weather_left = new QPropertyAnimation(label_curr_weather, "pos");
    animation_text_weather_left->setStartValue(label_curr_weather->pos());
    animation_text_weather_left->setEndValue(
            QPoint(ui->frame_pic->pos().x() + 70, label_curr_weather->pos().y() - 100));
    animation_text_weather_left->setDirection(QAbstractAnimation::Direction::Forward);
    animation_text_weather_left->setDuration(500);


    /*背景图移动动画*/
    QPropertyAnimation *animation_future_up_1 = new QPropertyAnimation(ui->frame_future, "pos");
    animation_future_up_1->setStartValue(QPoint(ui->frame_future->pos().x(), ui->frame_future->pos().y()));
    animation_future_up_1->setEndValue(
            QPoint(ui->frame_future->pos().x(), ui->frame_future->pos().y() - ui->frame_future->height() - 400));
    animation_future_up_1->setDirection(QAbstractAnimation::Direction::Forward);
    animation_future_up_1->setDuration(300);

    /*未来天气背景框移动动画*/
    QPropertyAnimation *animation_pic_up = new QPropertyAnimation(ui->frame_pic, "pos");
    animation_pic_up->setStartValue(QPoint(ui->frame_pic->pos().x(), ui->frame_pic->pos().y()));
    animation_pic_up->setEndValue(QPoint(ui->frame_pic->pos().x(), ui->frame_pic->pos().y() - 400));
    animation_pic_up->setDirection(QAbstractAnimation::Direction::Forward);
    animation_pic_up->setDuration(300);



    /*设置动画组，按照顺序执行动画*/
    QSequentialAnimationGroup *pPosGroup = new QSequentialAnimationGroup(this);
    pPosGroup->addAnimation(animation_text_temp_left);
    pPosGroup->addAnimation(animation_text_weather_left);
    pPosGroup->addAnimation(animation_future_up_1);
    pPosGroup->addAnimation(animation_pic_up);
    pPosGroup->start(QAbstractAnimation::DeleteWhenStopped);


}

/*实现展开功能*/
void Widget::down() {


    btn_fold->setText("折叠");
    //下降
    /*背景图移动动画*/
    QPropertyAnimation *animation_pic_down = new QPropertyAnimation(ui->frame_pic, "pos");
    animation_pic_down->setDuration(300);
    animation_pic_down->setStartValue(QPoint(ui->frame_pic->pos().x(), ui->frame_pic->pos().y()));
    animation_pic_down->setEndValue(QPoint(ui->frame_pic->pos().x(), ui->frame_pic->pos().y() + 400));
    animation_pic_down->setDirection(QAbstractAnimation::Direction::Forward);

    /*未来天气背景框移动动画*/
    QPropertyAnimation *animation_future_down = new QPropertyAnimation(ui->frame_future, "pos");
    animation_future_down->setStartValue(QPoint(ui->frame_future->pos().x(), ui->frame_future->pos().y()));
    animation_future_down->setEndValue(
            QPoint(ui->frame_future->pos().x(), ui->frame_future->pos().y() + ui->frame_future->height() + 400));
    animation_future_down->setDirection(QAbstractAnimation::Direction::Forward);
//    animation_future_up_1->setEasingCurve(QEasingCurve::OutBounce);  // 缓和曲线风格
    animation_future_down->setDuration(500);

//----------------------------------------------------
    //opacity
    /*未来第一天天气文字渐变动画*/
    QGraphicsOpacityEffect *pButtonOpacity_1 = new QGraphicsOpacityEffect(this);
    pButtonOpacity_1->setOpacity(0);
    ui->frame_weather_1->setGraphicsEffect(pButtonOpacity_1);
    QPropertyAnimation *pOpacityAnimation_1 = new QPropertyAnimation(pButtonOpacity_1, "opacity");
    pOpacityAnimation_1->setDuration(300);
    pOpacityAnimation_1->setStartValue(0);
    pOpacityAnimation_1->setEndValue(1);


    /*未来第二天天气文字渐变动画*/
    QGraphicsOpacityEffect *pButtonOpacity_2 = new QGraphicsOpacityEffect(this);
    pButtonOpacity_2->setOpacity(0);
    ui->frame_weather_2->setGraphicsEffect(pButtonOpacity_2);
    QPropertyAnimation *pOpacityAnimation_2 = new QPropertyAnimation(pButtonOpacity_2, "opacity");
    pOpacityAnimation_2->setDuration(300);
    pOpacityAnimation_2->setStartValue(0);
    pOpacityAnimation_2->setEndValue(1);

    /*未来第三天天气文字渐变动画*/
    QGraphicsOpacityEffect *pButtonOpacity_3 = new QGraphicsOpacityEffect(this);
    pButtonOpacity_3->setOpacity(0);
    ui->frame_weather_3->setGraphicsEffect(pButtonOpacity_3);
    QPropertyAnimation *pOpacityAnimation_3 = new QPropertyAnimation(pButtonOpacity_3, "opacity");
    pOpacityAnimation_3->setDuration(300);
    pOpacityAnimation_3->setStartValue(0);
    pOpacityAnimation_3->setEndValue(1);

    /*当前温度文字的移动动画*/
    QPropertyAnimation *animation_text_temp_right = new QPropertyAnimation(label_temp, "pos");
    animation_text_temp_right->setStartValue(label_temp->pos());
    animation_text_temp_right->setEndValue(QPoint(180, 80));
    animation_text_temp_right->setDirection(QAbstractAnimation::Direction::Forward);
    animation_text_temp_right->setDuration(500);

    /*当前天气状况文字的移动动画*/
    QPropertyAnimation *animation_text_weather_right = new QPropertyAnimation(label_curr_weather, "pos");
    animation_text_weather_right->setStartValue(label_curr_weather->pos());
    animation_text_weather_right->setEndValue(QPoint(220, 200));
    animation_text_weather_right->setDirection(QAbstractAnimation::Direction::Forward);
    animation_text_weather_right->setDuration(500);


    /*设置动画组，按照顺序执行动画*/
    QSequentialAnimationGroup *pPosGroup = new QSequentialAnimationGroup(this);
    pPosGroup->addAnimation(animation_pic_down);
    pPosGroup->addAnimation(animation_future_down);
    pPosGroup->addAnimation(pOpacityAnimation_1);
    pPosGroup->addAnimation(pOpacityAnimation_2);
    pPosGroup->addAnimation(pOpacityAnimation_3);

    pPosGroup->addAnimation(animation_text_temp_right);
    pPosGroup->addAnimation(animation_text_weather_right);
    pPosGroup->start(QAbstractAnimation::DeleteWhenStopped);


}


/**
 * @brief 软件延时
 * @param msec:需要延时的时间，单位毫秒
 */
void Widget::msleep(int msec) {
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 200);
}


Widget::~Widget() {
    delete ui;
}
