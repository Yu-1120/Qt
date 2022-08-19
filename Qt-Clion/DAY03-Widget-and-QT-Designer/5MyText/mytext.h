#ifndef MYTEXT_H
#define MYTEXT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MyText; }
QT_END_NAMESPACE

class MyText : public QMainWindow
{
    Q_OBJECT

public:
    MyText(QWidget *parent = nullptr);
    ~MyText();

private slots:
    void on_action_new_triggered();

    void on_action_open_triggered();

    void on_action_save_triggered();

    void on_action_saveas_triggered();

    void on_action_exit_triggered();

    void on_action_undo_triggered();

    void on_action_cut_triggered();

    void on_action_copy_triggered();

    void on_action_paste_triggered();

    void on_action_del_triggered();

    void on_action_find_triggered();

    void on_action_replay_triggered();

    void on_action_all_triggered();

    void on_action_font_triggered();

    void on_action_redo_triggered();


private:
    Ui::MyText *ui;
};
#endif // MYTEXT_H
