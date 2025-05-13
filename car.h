#ifndef CAR_H
#define CAR_H

#include <QWidget>
#include<QMediaPlayer>
#include<QVideoWidget>
#include<QCamera>
#include<QMediaCaptureSession>
#include<QFileDialog>
#include<QThread>
#include<QTimer>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/opencv.hpp>
#include"platerecognize.h"
#include<QMessageBox>
#include"mysql.h"
#include<QSqlQuery>
#include<QPieSeries>
#include<QChartView>
#include<QChart>
#include<QMediaDevices>
#include<QImageCapture>
#include"updatepie.h"
using namespace cv;
namespace Ui {
class car;
}
class car : public QWidget
{
    Q_OBJECT

public:
    explicit car(QWidget *parent = nullptr);
    ~car();
    bool checkPlateNumber(QString license_plate);
    int fee_charge(QDateTime oldDateTime, QDateTime currentDateTime,QString license_plate);
    void print_widget(QSqlQuery q,int i);
signals:
    void plate_start(QImage Img);
    void now_count_acc_signal();
    void now_count_dec_signal();
    void updatepiedata(QString m_Park_Name,int m_Reserve,int m_Now_Count);
private slots:
    void get_Duration();   //获取视频总长度
    void slider_Changed();  //根据扭头调成视频播放位置
    void On_position_Changed(qint64 position);
    void on_fileopen_clicked();

    void on_video_pause_clicked();

    void on_video_start_clicked();

    void on_camera_take_clicked();

    void on_camera_button_clicked();

    void on_submitcar_clicked();

    void on_deletecar_clicked();

    void on_pictureopen_clicked();
    void on_PieSliceHight(bool show);

    void on_messageButton_clicked();

    void on_carcheck_clicked();

    void on_cardelete_clicked();

private:
    void video_Init();
    void camera_Init();
    Ui::car *ui;
    int pos;
    QString filename;
    QMediaPlayer*player;
    QVideoWidget*videowidget;
    QVideoWidget *viewfinder;
    QCamera*camera;
    QVideoSink* videoSink;
    QImageCapture *imageCapture;
    QMediaCaptureSession mediaCaptureSession;
    bool cameraPaused;
    PlateRecognize* rec;
    UpdatePie* updatepie;
    mysql&mysqlc=mysql::getInstance();
    QSqlQuery q;
    void park_num();
    void createPie(int reserve);
    QPieSeries*series;
    QChart*chart;
    QChartView*chartview;
    QPieSlice*slice;
    QThread*t1;
    QThread*t2;
};

#endif // CAR_H
