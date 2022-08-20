#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>//行编辑器
#include <QGridLayout>

class Login : public QDialog
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private:
    QLabel *username_lab;
    QLabel *password_lab;
    QPushButton *login_btn;
    QPushButton *exit_btn;
    QLineEdit *username_edit;
    QLineEdit *password_edit;

    QGridLayout *lyt;
};
#endif // LOGIN_H
