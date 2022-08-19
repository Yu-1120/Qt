#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1280,800);

    //设置背景墙
    this->setStyleSheet("#MainWindow{background-image:url(:/res/pic/background1.jpg)}");

    //定时器动态增加时速
    myTimer = new QTimer(this);
    connect(myTimer,SIGNAL(timeout()),this,SLOT(slot_speed_changed()));

}


void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    int width=this->width();
    int height=this->height() - 100;//移动仪表盘的高度
    int radius=((width>height)?height:width)/2.0;//仪表盘的中心位置
    //移动画笔到中下方
    painter.translate(width/2,height*0.6);
    //启用反锯齿
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    //设置画刷颜色
    painter.setBrush(QColor(138,43,226));
    DrawSmallScale(painter,radius-60);//刻度线
    DrawDigital(painter,radius-90);//刻度数字
    /*所有形状绘画*/
//    DrawCircle_bom(painter,radius-40);  //扇形大圆
    DrawCircle(painter,radius-35);      //渐变发光外扇形
    DrawCircle_arc(painter,radius - 40);//动态扇形环
    DrawPointer(painter,radius-130);//指针
    DrawCircle_line(painter,radius-35); //最外细圆线
    DrawCircle_bom_big(painter,radius-150);//中间大圆
    DrawCircle_bom_shine(painter,radius - 230);//渐变发光内圈
    DrawCircle_bom_small(painter,radius - 200);//中间小圆

    DrawUnit(painter,radius - 390);//单位
    DrawNum(painter,radius-300);//时速
}
//绘制外圈点
void MainWindow::DrawPoint(QPainter& painter,int radius)
{
    //组装点的路径图
    QPainterPath pointPath;
    pointPath.moveTo(-2,-2);
    pointPath.lineTo(2,-2);
    pointPath.lineTo(2,2);
    pointPath.lineTo(0,4);
    pointPath.lineTo(-2,2);
    //绘制13个小点
    for(int i=0;i<13;++i){
        QPointF point(0,0);
        painter.save();
        painter.setBrush(QColor(250,252,78));
        //计算并移动绘图对象中心点
        point.setX(radius*qCos(((210-i*20)*M_PI)/180));
        point.setY(radius*qSin(((210-i*20)*M_PI)/180));
        //计算并移动绘图对象的中心点
        painter.translate(point.x(),-point.y());
        //计算并选择绘图对象坐标
        painter.rotate(-120+i*20);
        //绘制路径
        painter.drawPath(pointPath);
        painter.restore();
    }
}

void MainWindow::DrawDigital(QPainter& painter,int radius)
{
    //设置画笔，画笔默认NOPEN
    painter.setPen(QColor(255,255,255));
    QFont font;
    font.setFamily("Arial");
    font.setPointSize(15);
    font.setBold(true);
    painter.setFont(font);
    for(int i=0;i<13;++i){
        QPointF point(0,0);
        painter.save();
        point.setX(radius*qCos(((210-i*20)*M_PI)/180));
        point.setY(radius*qSin(((210-i*20)*M_PI)/180));
        painter.translate(point.x(),-point.y());
        painter.rotate(-120+i*20);
        painter.drawText(-25, 0, 50, 20,Qt::AlignCenter,QString::number(i*20));
        painter.restore();
    }
    //还原画笔
    painter.setPen(Qt::NoPen);
}


void MainWindow::DrawCircle_bom(QPainter& painter,int radius)
{
    //保存绘图对象
    painter.save();
    //计算大小圆路径
    QPainterPath outRing;
    outRing.moveTo(0,0);
    outRing.arcTo(-radius,-radius, 2*radius,2*radius,-30,240);
    outRing.closeSubpath();
    //设置画刷
    painter.setBrush(QColor(14,15,33));

    painter.drawPath(outRing);
    painter.restore();
}

void  MainWindow::DrawCircle_bom_shine(QPainter& painter,int radius)
{
    painter.save();
    QRadialGradient radialGradient(0,0,radius,0,0);
//    radialGradient.setColorAt(0.5,QColor(8,77,197));
        radialGradient.setColorAt(0.5,QColor(10,68,185,150));
    radialGradient.setColorAt(1.0,Qt::transparent);
    painter.setBrush(QBrush(radialGradient));
    painter.drawRect(-radius,-radius,2*(radius),2*(radius));
    painter.restore();

}


void  MainWindow::DrawCircle_bom_big(QPainter& painter,int radius)
{
    //保存绘图对象
    painter.save();
    //计算大小圆路径
    QPainterPath inRing;
    inRing.moveTo(0,0);
    inRing.addEllipse(-radius+50,-radius + 50,2*(radius-50),2*(radius-50));
    //设置画刷
    painter.setBrush(QColor(10,20,30));
    painter.drawPath(inRing);
    painter.restore();
}


void  MainWindow::DrawCircle_bom_small(QPainter& painter,int radius)
{
    //保存绘图对象
    painter.save();
    //计算大小圆路径
    QPainterPath inRing;
    inRing.moveTo(0,0);
    inRing.addEllipse(-radius+50,-radius + 50,2*(radius-50),2*(radius-50));
    //设置画刷
    painter.setBrush(QColor(10,20,30));
    painter.drawPath(inRing);

    painter.restore();
}

void MainWindow::DrawCircle_arc(QPainter& painter,int radius)
{

    QRect rect(-radius,-radius,2*radius,2*radius);
    QConicalGradient Conical(0,0,-70);

    Conical.setColorAt(0.1,QColor(255,88,127,200));//红色
    Conical.setColorAt(0.5,QColor(53,179,251,150));//蓝色
    painter.setBrush(Conical);
    painter.drawPie(rect,210*16,-(degRotate)*16);
}



void MainWindow::DrawCircle(QPainter& painter,int radius)
{
    //保存绘图对象
    painter.save();
    //计算大小圆路径
    QPainterPath outRing;
    QPainterPath inRing;
    outRing.moveTo(0,0);
    inRing.moveTo(0,0);
    outRing.arcTo(-radius,-radius, 2*radius,2*radius,-30,240);
    inRing.addEllipse(-radius+50,-radius + 50,2*(radius-50),2*(radius-50));
    outRing.closeSubpath();
    //设置渐变色k
    QRadialGradient radialGradient(0,0,radius,0,0);
    radialGradient.setColorAt(1,QColor(0,82,199));
    radialGradient.setColorAt(0.92,Qt::transparent);
    //设置画刷
    painter.setBrush(radialGradient);
    //大圆减小圆
    painter.drawPath(outRing.subtracted(inRing));
    painter.restore();
}


void MainWindow::DrawCircle_line(QPainter& painter,int radius)
{
    //保存绘图对象
    painter.save();
    //计算大小圆路径
    QPainterPath outRing;
    QPainterPath inRing;
    outRing.moveTo(0,0);
    inRing.moveTo(0,0);
    outRing.arcTo(-radius,-radius, 2*radius,2*radius,-30,240);
    inRing.addEllipse(-radius+2,-radius+2,2*(radius-2),2*(radius-2));
    outRing.closeSubpath();

    //设置画刷
    painter.setBrush(QColor(5,228,255));
    //大圆减小圆
    painter.drawPath(outRing.subtracted(inRing));
    painter.restore();
}


//绘制刻度
void MainWindow::DrawSmallScale(QPainter& painter,int radius)
{
    //组装点的路径图
    QPainterPath pointPath_small;
    pointPath_small.moveTo(-2,-2);
    pointPath_small.lineTo(2,-2);
    pointPath_small.lineTo(2,8);
    pointPath_small.lineTo(-2,8);


    QPainterPath pointPath_big;
    pointPath_big.moveTo(-2,-2);
    pointPath_big.lineTo(2,-2);
    pointPath_big.lineTo(2,20);
    pointPath_big.lineTo(-2,20);

    //绘制121个小点
    for(int i=0;i<121;i+=2){
        QPointF point(0,0);
        painter.save();
        point.setX(radius*qCos(((210-i*2)*M_PI)/180));
        point.setY(radius*qSin(((210-i*2)*M_PI)/180));
        painter.translate(point.x(),-point.y());
        painter.rotate(-120+i*2);

        if(i<80)
        {
          painter.setBrush(QColor(255,255,255));
        }
        if(i>=80)
        {
          painter.setBrush(QColor(235,70,70));
        }

        if(i%5 == 0)
        {
            painter.drawPath(pointPath_big);//绘画大刻度
        }else
        {
            painter.drawPath(pointPath_small);//绘画小刻度
        }
        painter.restore();
    }
}

//绘制文字
void MainWindow::DrawUnit(QPainter& painter,int radius)
{
    painter.save();
    painter.setPen(QColor(255,255,255));
    QFont font;
    font.setFamily("Arial");
    font.setPointSize(16);
    font.setBold(true);
    painter.setFont(font);
    painter.drawText(-50, -radius, 100, 20,Qt::AlignCenter,QString("km/h"));
    painter.drawText(-60, -radius + 130, 120, 40,Qt::AlignCenter,QString("当前车速"));

    painter.setPen(QColor(255,255,255,50));
    painter.drawText(-120, -radius + 280, 250, 40,Qt::AlignCenter,QString("-请按space键加速-"));
    painter.restore();
}

//绘制实时时速数字
void MainWindow::DrawNum(QPainter& painter,int radius)
{
    painter.save();
    painter.setPen(QColor(255,255,255));
    QFont font;
    font.setFamily("Arial");
    font.setPointSize(45);
    painter.setFont(font);
    painter.drawText(-75, -radius - 20, 150, 100,Qt::AlignCenter,QString::number(degRotate));
    painter.restore();
}

//绘制指针
void MainWindow::DrawPointer(QPainter& painter,int radius)
{
    //组装点的路径图
    QPainterPath pointPath;
    pointPath.moveTo(10,0);
    pointPath.lineTo(1,-radius);
    pointPath.lineTo(-1,-radius);
    pointPath.lineTo(-10,0);
    pointPath.arcTo(-10,0,20,20,180,180);
    QPainterPath inRing;
    inRing.addEllipse(-5,-5,10,10);
    painter.save();

    //计算并选择绘图对象坐标
    painter.rotate(degRotate - 120);
    painter.setBrush(QColor(255,255,255));
    painter.drawPath(pointPath.subtracted(inRing));
    painter.restore();
}


//动态增加时速画面效果
void MainWindow::slot_speed_changed()
{
    if(direction == 1)//加速
    {
      degRotate++;
      if(degRotate > 240)
          degRotate = 240;
    }
    else if(direction == 0)//减速
    {
        degRotate--;
        if(degRotate < 0)
        {
           degRotate = 0;
            myTimer->stop();
        }
    }
    update();//刷新画面。很重要！
}

//按键按下事件
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {
        if(direction == 0)
        {
          myTimer->start(1);
          direction = 1;
        }

    }
}
//按键释放事件
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {
        direction = 0;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

