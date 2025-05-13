#include "mysql.h"


QMutex mysql::mutex;
mysql::mysql(QObject *parent)
    : QObject{parent}
{
    mysql_init();
}

// mysql::mysql(const mysql &)
// {
//      mysql_init();
// }

mysql &mysql::getInstance()
{
    //QMutexLocker locker(&mutex);
    static mysql instance;
    return instance;
}

mysql::~mysql()
{
    mysql_close();
}

void mysql::mysql_init()
{
    QString filepath=QApplication::applicationDirPath()+"/parkingsystem.json";
    QFile file(filepath);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QByteArray jsonData = file.readAll();
        QJsonDocument jsonDoc(QJsonDocument::fromJson(jsonData));
        QJsonObject jsonObj =jsonDoc.object();
        QString ip=jsonObj["IP"].toString();
        int port=jsonObj["port"].toInt();
        QString user=jsonObj["account"].toString();
        QString passwrod=jsonObj["password"].toString();
        QString Databasename=jsonObj["databasename"].toString();
        parkingname=jsonObj["park_name"].toString();
        P_fee=jsonObj["p_fee"].toInt();
        parking_count=jsonObj["p_count"].toInt();
        reserve=0;
        // if(QSqlDatabase::contains("qt_sql_default_connection")){
            db=QSqlDatabase::addDatabase("QMYSQL");  /*"my_connection"*/
            db.setDatabaseName(Databasename);
            db.setHostName(ip);
            db.setPort(port);
            db.setUserName(user);
            db.setPassword(passwrod);
            if (!QSqlDatabase::isDriverAvailable("QMYSQL")) {
                qDebug() << "MySQL 驱动未加载！";
                return;
            }
            bool ok=db.open();
            if (!ok)
            {
                qDebug()<<"mysql open error";
                //QMessageBox::information(this, "infor", "link success");
            }
            else
            {
                qDebug()<<"mysql connect successful";
            }
    }
}

bool mysql::Parking_is_null(QString Parking_name)
{
    QString checknullsql=QStringLiteral("select P_id from parking where P_name = '%1' ").arg(Parking_name);
    QSqlQuery query;
    query.exec(checknullsql);
    if(query.size()==0){
        return true;
    }else {
        return false;
    }
}

bool mysql::is_Connection()
{
    if(db.open()){
        return true;
    }else {
        return false;
    }
}

QSqlQuery mysql::execute(QString sql)
{
    QSqlQuery query;
    if(!query.exec(sql)){
        qDebug()<<"mysql execute error";
    }else {
        qDebug()<<"mysql execute success";
    }
    return query;
}

bool mysql::bool_execute(QString sql)
{
    QSqlQuery query;
    if(!query.exec(sql)){
        qDebug()<<"mysql execute error";
        return false;
    }else {
        qDebug()<<"mysql execute success";
        return true;
    }
}

void mysql::mysql_close()
{
    // if(QSqlDatabase::contains("my_connection")){
    //     db.close();
    // }
    db.close();
}

void mysql::begintransaction()
{
    db.transaction();
}

void mysql::committransaction()
{
    db.commit();
}

void mysql::rollbacktransaction()
{
    db.rollback();
}

QSqlDatabase mysql::get_db()
{
    return db;
}

void mysql::park_reduce()
{
    QString name=this->parkingname;
    QString sql=QStringLiteral("UPDATE parking SET P_now_count = P_now_count - 1 WHERE P_name = '%1';").arg(name);
    if(bool_execute(sql)){
        parking_now_count--;
        qDebug()<<"reduce success";
    }else {
        qDebug()<<"reduce occur error";
    }
}

void mysql::park_increase()
{
    QString name=this->parkingname;
    QString sql=QStringLiteral("UPDATE parking SET P_now_count = P_now_count + 1 WHERE P_name = '%1';").arg(name);
    if(bool_execute(sql)){
        parking_now_count++;
        qDebug()<<"reduce success";
    }else {
        qDebug()<<"reduce occur error";
    }
}


