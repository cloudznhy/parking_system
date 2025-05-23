#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<mysql.h>
#include"signup.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_register_2_clicked();

    void on_login_clicked();

private:
    Ui::MainWindow *ui;
    mysql& mysqlc=mysql::getInstance();
};
#endif // MAINWINDOW_H
