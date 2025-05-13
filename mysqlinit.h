#ifndef MYSQLINIT_H
#define MYSQLINIT_H

#include <QObject>
#include"mysql.h"
#include<QSqlQuery>
#include<QJsonObject>
#include<QJsonDocument>
#include<QApplication>
#include<iostream>
class MYSQLINIT : public QObject
{
    Q_OBJECT
public:
    explicit MYSQLINIT(QObject *parent = nullptr);

    ~MYSQLINIT();
    void create_user();//新建用户信息表
    void create_car();//新建车辆信息表
    void create_parking();//新建停车场表
    void parking_init(QString parking_name);//初始化停车库数据
    void parking_reserve();
signals:

public slots:

private:
    mysql& mysqlc=mysql::getInstance();
};

#endif // MYSQLINIT_H
