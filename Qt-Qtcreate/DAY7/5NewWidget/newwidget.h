#ifndef NEWWIDGET_H
#define NEWWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class NewWidget; }
QT_END_NAMESPACE

class NewWidget : public QWidget
{
    Q_OBJECT

public:
    NewWidget(QWidget *parent = nullptr);
    ~NewWidget();

private:
    Ui::NewWidget *ui;
};
#endif // NEWWIDGET_H
