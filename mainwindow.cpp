#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"initfile.h"
#include<QGraphicsDropShadowEffect>
#include<QMessageBox>
#include"car.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("登录");



    //创建登陆界面左边背景图
    // 创建QPixmap对象，加载png图像存储到pix变量中，使用new关键字分配堆内存来储存该对象
    QPixmap *pix=new QPixmap(":/images/welcome.png");
    QSize size=ui->imglabel->size();
    ui->imglabel->setPixmap(pix->scaled(size));

    //设置图片阴影效果
    //QGraphicsDropShadowEffect对象添加阴影效果，
    QGraphicsDropShadowEffect *shadow=new QGraphicsDropShadowEffect(this);
    //设置阴影效果的偏移量，并不在垂直方向发生任何偏移
    shadow->setOffset(-3,0);
     //设置阴影的颜色
    QColor color(227,180,184);
    shadow->setColor(color);
    // 设置模糊半径，数值越大，阴影边缘越模糊
    shadow->setBlurRadius(30);
    ui->imglabel->setGraphicsEffect(shadow);

    connect(ui->account,&QLineEdit::returnPressed,ui->login,&QPushButton::click);//输入密码时点回车 登录
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_register_2_clicked()
{
    this->close();
    signup*s=new signup;
    s->show();
    s->setAttribute(Qt::WA_DeleteOnClose);
}


void MainWindow::on_login_clicked()
{
    QString account=ui->account->text();
    QString password=ui->password->text();
    if(account.isEmpty()||password.isEmpty()){
        QMessageBox msgbox;
        msgbox.setIcon(QMessageBox::Critical);
        msgbox.setText("账号和密码不能为空");
        msgbox.setWindowTitle("登录");
        msgbox.setStyleSheet("background-color:white;color:red;");
        msgbox.exec();
        return;
    }
    QString sql=QStringLiteral("select * from user where username='%1' and password = '%2'").arg(account,password);
    QSqlQuery query=mysqlc.execute(sql);
    if(query.next()){
        qDebug()<<"login success";
        car*c=new car;
        c->show();
        this->close();
    }else {
        QMessageBox::information(this,"登陆失败","账号或密码错误");
    }
}

