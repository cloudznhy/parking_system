#ifndef INITFILE_H
#define INITFILE_H

#include <QWidget>
#include"mysql.h"
#include"mysqlinit.h"
#include<QJsonObject>
#include<QJsonDocument>
namespace Ui {
class initfile;
}

class initfile : public QWidget
{
    Q_OBJECT

public:
    explicit initfile(QWidget *parent = nullptr);
    ~initfile();
    struct filemysqlInitList
    {
        QString ip;
        int port;
        QString databasename;
        QString account;
        QString password;
        QString parkname;
        int p_fee;
        int count;
    };
    void parking_init();
signals:
    void starting(mysql *mysql_c);
public slots:
    void json_save(filemysqlInitList*list);
    bool file_mysqlinit();
private slots:
    void on_submit_clicked();
    void on_cancel_clicked();

private:
    Ui::initfile *ui;
    filemysqlInitList *list;
    mysql*mysqlc;
    MYSQLINIT* mysqlinit;
};

#endif // INITFILE_H
