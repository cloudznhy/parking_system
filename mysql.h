#ifndef MYSQL_H
#define MYSQL_H
#include <QObject>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QJsonDocument>
#include<QSqlError>
#include<QApplication>
#include<QFile>
#include<QJsonObject>
#include<QDebug>
#include<QMutex>
class mysql : public QObject
{
    Q_OBJECT
public:
    explicit mysql(QObject *parent = nullptr);
    //mysql(const mysql &)=delete;//禁用复制构造函数
    static mysql& getInstance();
    mysql&operator =(const mysql&)=delete;//禁用赋值运算符
    ~mysql();
    QSqlDatabase db;
    void mysql_init();
    bool Parking_is_null(QString Parking_name);
    bool is_Connection();
    QString parkingname;//停车场名称
    int parking_count;//总停车位
    int parking_now_count;//现在有的停车位
    int reserve;//预约的停车位数
    int P_fee;//车位单价

    QSqlQuery execute(QString sql);
    bool bool_execute(QString sql);
    void mysql_close();

    void begintransaction();  //开始事务
    void committransaction();//提交事务
    void rollbacktransaction();//回滚事务
    QSqlDatabase get_db();//获取数据库链接


signals:
    void now_count_changed_signal(int parking_now_count);
public slots:
    void park_reduce();
    void park_increase();
private:
    static QMutex mutex;

};

#endif // MYSQL_H
