#include "mysqlinit.h"

MYSQLINIT::MYSQLINIT(QObject *parent)
    : QObject{parent}
{
}

MYSQLINIT::~MYSQLINIT()
{

}

void MYSQLINIT::create_user()
{
    QString sql=QString("CREATE TABLE IF NOT EXISTS USER ( "
                                 "id INT PRIMARY KEY AUTO_INCREMENT, "
                                 "username VARCHAR(255) UNIQUE NOT NULL, "
                                 "password VARCHAR(255) NOT NULL "
                                 ");");
    if(!mysqlc.execute(sql).exec()){
        qDebug()<<"create user error";
    }else {
        qDebug()<<"create user success";
    }
}

void MYSQLINIT::create_car()
{
    //创建车库的表格,ID,车牌号，入库时间，出库时间，费用，id主键，车牌号索引
    QString createsql = QString("CREATE TABLE IF NOT EXISTS CAR("
                                "id INT NOT NULL AUTO_INCREMENT,"
                                "license_plate VARCHAR(20) NOT NULL,"
                                "check_in_time DATETIME NOT NULL,"
                                "check_out_time DATETIME DEFAULT NULL,"
                                "fee DECIMAL(10, 2) DEFAULT NULL,"
                                "location VARCHAR(20) NOT NULL,"
                                "PRIMARY KEY (id),"
                                "INDEX(license_plate)"
                                ");"
                                );

    if(!mysqlc.execute(createsql).exec()) //执行创建表格语句
    {
        qDebug()<<"table CAR create error";
    }
    else
    {
        qDebug()<<"table CAR create success";
    }
}

void MYSQLINIT::create_parking()
{
    //-- 建车库表格
    // 车库id,车库名称，车库现有用量，车库总用量
    QString sql = QString("CREATE TABLE IF NOT EXISTS PARKING("
                                "P_id INT NOT NULL AUTO_INCREMENT,"
                                "P_name VARCHAR(255) NOT NULL,"
                                "P_reserve_count INT,"
                                "P_now_count INT,"
                                "P_all_count INT,"
                                "P_fee DECIMAL(10, 2),"
                                "PRIMARY KEY (P_id),"
                                "UNIQUE INDEX(P_name)"
                                ");"
                                );

    if(!mysqlc.bool_execute(sql)) //执行创建表格语句
    {
        qDebug()<<"table Parking create error";
    }
    else
    {
        qDebug()<<"table Parking create success";
    }
}

// void MYSQLINIT::parking_init(QString parking_name)
// {
//     if(mysqlc->Parking_is_null(parking_name)){
//         qDebug()<<"parking is null,creating";
//         QString name=parking_name;
//         int all_count=mysqlc->parking_count;
//         int now_count=0;
//         int reserve=0;
//         int p_fee=mysqlc->P_fee;
//         QSqlQuery query;
//         query.prepare("insert into PARKING(P_name,P_reserve_count,P_now,count,P_all_count,P-fee) values(:name,:reserve,:now_count,:all_count,p_fee);");
//         query.bindValue(":name",name);
//         query.bindValue(":reserve",reserve);
//         query.bindValue(":now_count",now_count);
//         query.bindValue(":all_count",all_count);
//         query.bindValue(":p_fee",p_fee);
//         if(query.exec())
//         {
//             qDebug()<<"Parking Initative successful";
//         }
//         else {
//             qDebug()<<name<<all_count<<now_count<<p_fee;
//             qDebug()<<"Parking Initative Error";
//         }
//     }
// }

void MYSQLINIT::parking_reserve()
{
    QString createsql_reserve = QString("CREATE TABLE IF NOT EXISTS reservations("
                                        "id INT PRIMARY KEY AUTO_INCREMENT, "
                                        " license_plate VARCHAR ( 10 ) NOT NULL, "
                                        "P_name VARCHAR ( 255 ) NOT NULL,"
                                        "created_at DATETIME DEFAULT CURRENT_TIMESTAMP,"
                                        "UNIQUE INDEX(license_plate)"
                                        ");"
                                        );

    if(!mysqlc.bool_execute(createsql_reserve)) //执行创建表格语句
    {
        qDebug()<<"table Park reserve create error";
    }
    else
    {
        qDebug()<<"table Park reserve create success";
    }
    QSqlQuery query;
    QStringList sqlStatements;
    sqlStatements<<"SET GLOBAL event_scheduler = on;";//启用MySQL事件调度器（需要SUPER权限）
    sqlStatements << "CREATE EVENT IF NOT EXISTS clean_reservations ON SCHEDULE EVERY 1 MINUTE DO DELETE FROM reservations WHERE TIMESTAMPDIFF(MINUTE, created_at, NOW()) > 30;";  //创建清理 任务每分钟执行一次的定时任务  自动删除超过30分钟的预定记录  保证预定记录的时效性
    sqlStatements << QString("CREATE TRIGGER update_reserve_count AFTER INSERT ON reservations FOR EACH ROW BEGIN UPDATE PARKING SET P_reserve_count = P_reserve_count + 1 WHERE P_name = '%1'; END;").arg(mysqlc.parkingname); //创建触发器，添加自动+1
    sqlStatements << QString("CREATE TRIGGER update_reserve_count2 AFTER DELETE ON reservations FOR EACH ROW BEGIN UPDATE PARKING SET P_reserve_count = P_reserve_count -1 where P_name = '%1' ;END;").arg(mysqlc.parkingname); //创建触发器，减小后减一
    for (QStringList::iterator it=sqlStatements.begin(); it<sqlStatements.end();it++) {
        if(!query.exec(*it)){
                qDebug() << "触发器 executing SQL statement: " << query.lastError();
        }
    }
}
