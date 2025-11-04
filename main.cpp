#include "mainwindow.h"
#include <QApplication>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<QDebug>
#include<QCoreApplication>
#include"initfile.h"
int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    qputenv("QT_SCALE_FACTOR", "1.3");
    //QCoreApplication ca(argc, argv);
    QApplication a(argc, argv);
    QString filePath =QApplication::applicationDirPath() + "/parkingsystem.json";
    QFile file(filePath);
    //如果文件不能打开不存在
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"文件不存在，初始化!";
        initfile*initmysql_file = new initfile;
        initmysql_file->show();
        file.close();
    }
    else
    {
        //文件存在启动主程序
        MainWindow *w = new MainWindow;
        w->show();
        file.close();
        w->setAttribute(Qt::WA_DeleteOnClose);

    }
    return a.exec();
}
