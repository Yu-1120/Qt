#ifndef WIDGETITEM_H
#define WIDGETITEM_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>

class WidgetItem : public QWidget
{
    Q_OBJECT

public:
    WidgetItem(QWidget *parent = nullptr);
    ~WidgetItem();

private:
    QLabel *lab;
    QLineEdit *edit;
    QVBoxLayout *lyt;
};
#endif // WIDGETITEM_H
