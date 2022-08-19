#ifndef WIDGETDESIGNER_H
#define WIDGETDESIGNER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class WidgetDesigner; }
QT_END_NAMESPACE

class WidgetDesigner : public QWidget {
Q_OBJECT

public:
    WidgetDesigner(QWidget *parent = nullptr);

    ~WidgetDesigner();

private slots:

    void on_pushButton_clicked();

    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::WidgetDesigner *ui;
};

#endif // WIDGETDESIGNER_H
