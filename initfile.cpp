#include "initfile.h"
#include "ui_initfile.h"
#include<QMessageBox>
#include<QTextEdit>
#include<QSqlDatabase>
#include"mainwindow.h"
initfile::initfile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::initfile)
{
    ui->setupUi(this);
    qDebug()<<QSqlDatabase::drivers();
}

initfile::~initfile()
{
    delete ui;
    delete mysqlinit;
    delete list;
}

void initfile::parking_init()
{
    if(mysqlc->Parking_is_null(list->parkname)){
        qDebug()<<"parking is null,creating";
        QString name=list->parkname;
        int all_count=list->count;
        int now_count=0;
        int reserve=0;
        int p_fee=list->p_fee;
        QSqlQuery query;
        query.prepare("insert into parking(P_name,P_reserve_count,P_now_count,P_all_count,P_fee) values(:name,:reserve,:now_count,:all_count,:p_fee);");
        query.bindValue(":name",name);
        query.bindValue(":reserve",reserve);
        query.bindValue(":now_count",now_count);
        query.bindValue(":all_count",all_count);
        query.bindValue(":p_fee",p_fee);
        if(query.exec())
        {
            qDebug()<<"Parking Initative successful";
        }
        else {
            qDebug()<<name<<all_count<<now_count<<p_fee;
            qDebug()<<"Parking Initative Error";
            qDebug()<<query.lastError().text();
        }
    }
}



void initfile::on_cancel_clicked()
{
    QMessageBox::Button btn=QMessageBox::question(this,"关闭窗口","确定要关闭窗口吗");
    if(btn==QMessageBox::Yes){
        this->close();
    }else {

    }
}

void initfile::json_save(filemysqlInitList *list)
{
    QString filepath=QApplication::applicationDirPath()+"/parkingsystem.json";
    QFile file(filepath);
    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QJsonObject jsonobj;
        jsonobj.insert("IP",list->ip);
        jsonobj.insert("port",list->port);
        jsonobj.insert("databasename",list->databasename);
        jsonobj.insert("account",list->account);
        jsonobj.insert("password",list->password);
        jsonobj.insert("park_name",list->parkname);
        jsonobj.insert("p_fee",list->p_fee);
        jsonobj.insert("p_count",list->count);
        //写入
        QJsonDocument jsondoc(jsonobj);
        QString jsonString=jsondoc.toJson(QJsonDocument::Indented);
        file.write(jsonString.toUtf8());
        file.close();

        if(file_mysqlinit()){
            MainWindow w;
            w.show();
            this->close();
        }else {
            QMessageBox::information(this,"初始化失败","请检查你的初始化信息并重新输入");
            QFile::remove(filepath);
        }
    }
}

bool initfile::file_mysqlinit()
{
    mysqlc = &mysql::getInstance();
    if(mysqlc->is_Connection()){
        qDebug()<<"数据库连接成功";
    }else {
        qDebug()<<"数据库连接失败";
    }
    mysqlinit=new MYSQLINIT;
    QTextEdit*edit=new QTextEdit(this);
    edit->setAlignment(Qt::AlignCenter);
    edit->setTextColor(Qt::yellow);
    edit->setTextBackgroundColor(Qt::transparent);
    edit->show();
    edit->append("初始化ing");
    mysqlinit->create_car();
    edit->append("初始化车辆信息表");
    mysqlinit->create_user();
    edit->append("初始化用户表完成");
    mysqlinit->create_parking();
    parking_init();
    edit->append("初始化停车场表完成");
    mysqlinit->parking_reserve();
    edit->append("初始化预定车辆表完成");
    edit->close();
    delete edit;
    return mysqlc->bool_execute("select * from user");
}

void initfile::on_submit_clicked()
{
    list=new filemysqlInitList;
    list->ip=ui->ip->text();
    list->port=ui->port->text().toInt();
    list->databasename=ui->databasename->text();
    list->account=ui->account->text();
    list->password=ui->password->text();
    list->parkname=ui->parkingname->text();
    list->count=ui->allcount->text().toInt();
    list->p_fee=ui->fee->text().toInt();
    qDebug()<<list->ip<<list->port<<list->databasename<<list->account<<list->password<<list->parkname<<list->p_fee;
    json_save(list);

}

