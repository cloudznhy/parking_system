#ifndef PLATERECOGNIZE_H
#define PLATERECOGNIZE_H
#include <QObject>
#include<opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <QImage>
#include <QPixmap>
#include <QSignalMapper>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>
#include <QBuffer>
#include<QSettings>
using namespace cv;
using namespace std;
class PlateRecognize : public QObject
{
    Q_OBJECT
public:
    explicit PlateRecognize(QObject *parent = nullptr);

signals:
    void Recogned(QImage qplateImg,QString plateStr);
public slots:
    void Recognize(QImage Img);
   // void handleNetworkReply(QNetworkReply *reply);
private:
    QNetworkAccessManager *manager;
    QImage detectPlate(const Mat &img);
    QImage matToImage(const Mat&mat);
    void ocrPlate(const QImage plateImage);
    void fetchAccessTokenSync();
    Mat QImageToMat(const QImage &image);
    QImage cropPlateFromImage(const QImage plateImage, const QVector<QPoint> &points);
    double ** ColorFeture;
    double weightBlueRed;
    double weightBlueGreen;
    QString accesstoken;
};

#endif // PLATERECOGNIZE_H
