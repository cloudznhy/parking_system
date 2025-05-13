#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include<mysql.h>
#include<QMessageBox>
namespace Ui {
class signup;
}

class signup : public QWidget
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_return_2_clicked();

    void on_confirm_clicked();

private:
    Ui::signup *ui;
    mysql&mysqlc=mysql::getInstance();
};

#endif // SIGNUP_H
