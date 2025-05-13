#ifndef UPDATEPIE_H
#define UPDATEPIE_H

#include <QObject>
#include"mysql.h"
#include<QSqlQuery>
#include<QThread>
#include<QTimer>
class UpdatePie : public QObject
{
    Q_OBJECT
public:
    explicit UpdatePie(QObject *parent = nullptr);
    void checkPie(QString m_Park_Name,int m_Reserve,int m_Now_Count);
signals:
    void pieChanged(int reserve);
private:
    void checkMysqlData();
    mysql&mysqlc=mysql::getInstance();
    QSqlQuery q;
    QString park_Name;
    bool update=true;   //用户在主页，就更新
    int reserve;
    int now_Count;
    QTimer*timer;
};

#endif // UPDATEPIE_H
