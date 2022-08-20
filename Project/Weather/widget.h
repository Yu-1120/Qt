#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonParseError>
#include <QTime>
#include <QTimer>

#include <QDebug>
#include <QMouseEvent>

#include <QPoint>
#include <QTime>

#include <QPropertyAnimation>


#include <QGraphicsDropShadowEffect>
#include <QSequentialAnimationGroup>

#include <QPushButton>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

QLabel * label_temp;
QLabel * label_curr_weather;
QPushButton* btn_fold;
    QNetworkAccessManager *manager;
    QNetworkRequest request;






void msleep(int msec);
void set_weather_pic(QString weather);

void up();
void down();
public slots:
    void doProcessfinished(QNetworkReply *reply);

private:
    Ui::Widget *ui;


protected:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *);
private slots:




    void slot_up();

private:
    QPoint m_mousePoint;
    QPoint movePoint;
    bool mousePress;

};

#endif // WIDGET_H
