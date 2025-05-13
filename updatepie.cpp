#include "updatepie.h"

UpdatePie::UpdatePie(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &UpdatePie::checkMysqlData);
}

void UpdatePie::checkPie(QString m_Park_Name, int m_Reserve, int m_Now_Count)
{
    park_Name=m_Park_Name;
    reserve=m_Reserve;
    now_Count=m_Now_Count;
    while(update){
        checkMysqlData();
        QThread::sleep(1000);//休眠一秒钟
    }
}

void UpdatePie::checkMysqlData()
{
    QString parkname=park_Name;
    q.prepare("SELECT P_now_count,  P_reserve_count FROM parking WHERE P_name = :park_name;");
    q.bindValue(":park_name", parkname);
    q.exec();
    q.next();
    int reserve_count=q.value(1).toInt();
    qDebug()<<reserve_count;
    if(reserve_count!=reserve){
        reserve=reserve_count;
        emit pieChanged(reserve);
    }
}
