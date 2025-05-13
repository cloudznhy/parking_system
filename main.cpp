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
    // qDebug()<<"加载断点";
    // // 1. 加载车牌识别模型
    // CPlateRecognize pr;
    // pr.LoadSVM("D://qtfile//parking_system//model//svm_hist.xml");
    // qDebug()<<"AVM";
    // pr.LoadANN("D://qtfile//parking_system//model//ann.xml");
    // qDebug()<<"ANN";
    // pr.LoadChineseANN("D://qtfile//parking_system//model//ann_chinese.xml");
    // qDebug()<<"ChineseANN";

    // // new in v1.6
    // pr.LoadGrayChANN("D://qtfile//parking_system//model//annCh.xml");
    // pr.LoadChineseMapping("D://qtfile//parking_system//model//province_mapping");
    // // 2. 读入待识别的车牌图片
    // cv::Mat src = cv::imread("D:/qtfile/parking_system/car.jpg");

    // // 3. 车牌识别
    // std::vector<CPlate> plates;

    // pr.plateRecognize(src, plates);

    // // 4. 输出识别结果
    // for (auto plate : plates) {
    //     std::cout << "plate: " << plate.getPlateStr() << std::endl;
    // }
    // initfile file;
    // file.show();
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
