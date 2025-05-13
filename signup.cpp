#include "signup.h"
#include "ui_signup.h"
#include"mainwindow.h"
signup::signup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::signup)
{
    ui->setupUi(this);
    QPixmap pix=*new QPixmap(":/images/welcome.png");
    QSize sz=ui->imglabel->size();
    ui->imglabel->setPixmap(pix.scaled(sz));
    connect(ui->signup_password2,&QLineEdit::returnPressed,ui->confirm,&QPushButton::click);
}

signup::~signup()
{
    delete ui;
}

void signup::on_return_2_clicked()
{
    MainWindow *w=new MainWindow;
    w->show();
    this->close();
    w->setAttribute(Qt::WA_DeleteOnClose);
}


void signup::on_confirm_clicked()
{
    QString account=ui->account->text();
    QString password=ui->signup_password->text();
    QString password2=ui->signup_password2->text();
    if(account.isEmpty()||password.isEmpty()){
        QMessageBox::warning(this,"注册警告","账号和密码不能为空");
        return;
    }
    if(password==password2){
        QString sql=QStringLiteral("insert into user(username,password) values('%1','%2') ").arg(account,password);
        if(!mysqlc.bool_execute(sql)){
            qDebug()<<"insert user error";
        }else {
            QMessageBox::information(this,"注册成功","注册成功");
            MainWindow *w=new MainWindow;
            w->show();
            this->close();
        }
    }else{
        QMessageBox::information(this,"注册","两次密码不一致");
    }
}

