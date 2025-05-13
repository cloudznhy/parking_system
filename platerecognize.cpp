#include "platerecognize.h"
#include<QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QByteArray>
#include <QBuffer>
#include <iostream>
#include<QUrlQuery>
#include<QEventLoop>
#include<QSslSocket>
#include<QNetworkRequest>
#include<QJsonArray>
#include<QLabel>
PlateRecognize::PlateRecognize(QObject *parent)
    : QObject{parent}
{
    qRegisterMetaType<Mat>("Mat");
    qDebug() << "OpenSSL support:" << QSslSocket::supportsSsl();
    qDebug() << "OpenSSL version (used):" << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << "OpenSSL version (linked):" << QSslSocket::sslLibraryVersionString();
    manager=new QNetworkAccessManager(this);
    qDebug()<<manager->supportedSchemes();
    // pr.LoadSVM("D://qtfile//parking_system//model//svm_hist.xml");
    // pr.LoadANN("D://qtfile//parking_system//model//ann.xml");
    // pr.LoadChineseANN("D://qtfile//parking_system//model//ann_chinese.xml");
    // // new in v1.6
    // pr.LoadGrayChANN("D://qtfile//parking_system//model//annCh.xml");
    // pr.LoadChineseMapping("D://qtfile//parking_system//model//province_mapping");

   // manager = new QNetworkAccessManager(this);
    //connect(manager, &QNetworkAccessManager::finished, this, &PlateRecognize::handleNetworkReply);

}

void PlateRecognize::Recognize(QImage Img)
{
    // Mat localImg=rgbImg.clone();
    // std::vector<easypr::CPlate> plates;
    // m_plateRecognize.plateRecognize(localImg,plates,0);
    // for (auto plate:plates) {
    //     std::cout<<plate.getPlateStr()<<endl;
    // }
    // qDebug()<<"内部子线程输出，线程id:"<<pthread_self();
    // if(plates.size()>0){
    //     CPlate plate=plates[0];
    //     Mat plateImg=plate.getPlateMat();
    //     QString plateStr=QString::fromLocal8Bit(plate.getPlateStr().c_str());
    //     qDebug()<<plateStr;
    //     QStringList list = plateStr.split(":");
    //     if (list.size() >= 2) {
    //         plateStr = list[1].trimmed();
    //     }
    //     qDebug()<<plateStr;
    //     emit Recogned(plateImg,plateStr); //传出图片和识别的字符串
    // }
    // if (rgbImg.empty() || rgbImg.channels() != 3) {
    //     qDebug() << "输入图像为空或格式不正确";
    //     emit Recogned(Mat(), QString());
    //     return;
    // }
    //imshow("1", rgbImg);
    //waitKey(0);
    // 1. 车牌检测
    // QImage plateImg = detectPlate(rgbImg);
    // if (plateImg.isNull()) {
    //     qDebug() << "No plate detected.";
    //     return;
    // }
    //ocrPlate(plateImg);
    //QImage img=matToImage(rgbImg);
    Mat src=QImageToMat(Img);
    Mat image,gray;
    Mat sobel_x,abs_x;
    vector<vector<Point>>contours;
    vector<Vec4i>hierarchy;
    //高斯模糊
    GaussianBlur(src,image,Size(3,3),0);
    imshow("gauss",image);
    //转灰度图
    cvtColor(image,gray,COLOR_BGR2GRAY);
    imshow("gray",gray);
    //sobel算子进行边缘检测
    Sobel(gray,sobel_x,CV_16S,1,0);
    convertScaleAbs(sobel_x,abs_x);
    imshow("sobel",abs_x);
    image=abs_x;
    //自适应阈值处理
    threshold(image,image,0,255,THRESH_OTSU);
    imshow("threash",image);
    //闭运算
    Mat kernelx=getStructuringElement(MORPH_RECT,Size(17,5));
    morphologyEx(image,image,MORPH_CLOSE,kernelx,Point(-1,-1),1);
    imshow("close",image);
    Mat kernelX=getStructuringElement(MORPH_RECT,Size(20,1));
    Mat kernelY=getStructuringElement(MORPH_RECT,Size(1,19));
    //腐蚀膨胀
    dilate(image,image,kernelX);
    erode(image,image,kernelX);
    dilate(image,image,kernelY);
    erode(image,image,kernelY);
    imshow("dilate erode",image);
    //中值滤波
    medianBlur(image,image,15);
    imshow("mediablur",image);
    //寻找轮廓
    findContours(image,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    Mat image1=src.clone();
    drawContours(image1,contours,-1, Scalar(255, 0, 255), 5);
    imshow("contours",image1);
    for (auto i:contours) {
        Rect rect=boundingRect(i);
        int x=rect.x;
        int y = rect.y;
        int width = rect.width;
        int height = rect.height;
        if (width > (height * 1.8) && width < (height * 4)) {
            // 提取车牌区域
            Mat image2 = src(Rect(x, y, width, height));
            imshow("image2", image2);
            waitKey(0);
        }
    }
    ocrPlate(Img);
}

QImage PlateRecognize::matToImage(const Mat &mat)
{
    if (mat.empty()) {
        qDebug() << "Mat is empty!";
        return QImage();
    }

    switch (mat.type()) {
    case CV_8UC1: { // 灰度图像
        return QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Grayscale8).copy();
    }
    case CV_8UC3: { // BGR 图像
        cv::Mat rgb;
        cv::cvtColor(mat, rgb, cv::COLOR_BGR2RGB); // 转换为 RGB 格式
        return QImage(rgb.data, rgb.cols, rgb.rows, rgb.step, QImage::Format_RGB888).copy();
    }
    case CV_8UC4: { // BGRA 图像
        cv::Mat rgba;
        cv::cvtColor(mat, rgba, cv::COLOR_BGRA2RGBA); // 转换为 RGBA 格式
        return QImage(rgba.data, rgba.cols, rgba.rows, rgba.step, QImage::Format_RGBA8888).copy();
    }
    default:
        qDebug() << "Unsupported cv::Mat type:" << mat.type();
        return QImage();
    }
}

void PlateRecognize::ocrPlate(const QImage plateImage)
{
    // 确保有有效的Access Token
    if (accesstoken.isEmpty()) {
        fetchAccessTokenSync();
    }
    // 转换为Base64
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    plateImage.save(&buffer, "PNG");
    QString base64Image = QString::fromLatin1(byteArray.toBase64());

    // 构造请求
    QNetworkRequest request(QUrl("https://aip.baidubce.com/rest/2.0/ocr/v1/license_plate?access_token=" + accesstoken));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QByteArray postData = "image=" + QUrl::toPercentEncoding(base64Image);
    QNetworkReply* reply = manager->post(request, postData);

    // 处理响应
    connect(reply, &QNetworkReply::finished, [=]() {
        QByteArray response = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(response);

        qDebug().noquote() << doc.toJson(QJsonDocument::Indented);
        // Token失效处理
        if (doc.object()["error_code"].toInt() == 110) {
            fetchAccessTokenSync();
            ocrPlate(plateImage); // 重试识别
            return;
        }

        if (doc.object().contains("words_result")) {
            QString plateNumber = doc.object()["words_result"].toObject()["number"].toString();
            qDebug()<<plateNumber;
            QJsonObject rootObj = doc.object();
            QJsonObject wordsResult = rootObj["words_result"].toObject();
            QJsonArray vertexes = wordsResult["vertexes_location"].toArray();

            QVector<QPoint> points;
            for (const QJsonValue &val : vertexes) {
                QJsonObject pointObj = val.toObject();
                int x = pointObj["x"].toInt();
                int y = pointObj["y"].toInt();
                points.append(QPoint(x, y));
            }

            // 示例：打印这些点
            for (const QPoint &pt : points) {
                qDebug() << "x:" << pt.x() << ", y:" << pt.y();
            }
            QImage result = cropPlateFromImage(plateImage, points);
            emit Recogned(result, plateNumber);
        } else {
            emit Recogned(QImage(), "识别失败");
        }
        reply->deleteLater();
    });
}

void PlateRecognize::fetchAccessTokenSync()
{
    // 确保 manager 已初始化
    if (!manager)
        manager = new QNetworkAccessManager(this);

    QEventLoop loop;
    QString url = QString("https://aip.baidubce.com/oauth/2.0/token?"
                          "grant_type=client_credentials&"
                          "client_id=%1&"
                          "client_secret=%2")
                      .arg("rCJLCrKNAirO3eOqngxXRTu5", "PYXnV92CWWV40fB6gOWKKbzoaz05CMvN");

    QNetworkRequest request;
    request.setUrl(QUrl(url));
    QNetworkReply* reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    if (doc.object().contains("access_token")) {
        accesstoken = doc.object()["access_token"].toString();
        qDebug() << "Token更新成功：" << accesstoken;
    } else {
        qWarning() << "Token获取失败：" << doc.toJson();
    }
    reply->deleteLater();
}

Mat PlateRecognize::QImageToMat(const QImage &image)
{
    switch (image.format()) {
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32:
    case QImage::Format_ARGB32_Premultiplied:
        return cv::Mat(image.height(), image.width(), CV_8UC4,
                       const_cast<uchar *>(image.bits()), image.bytesPerLine()).clone();
    case QImage::Format_RGB888:
        return cv::Mat(image.height(), image.width(), CV_8UC3,
                       const_cast<uchar *>(image.bits()), image.bytesPerLine()).clone();
    case QImage::Format_Grayscale8:
        return cv::Mat(image.height(), image.width(), CV_8UC1,
                       const_cast<uchar *>(image.bits()), image.bytesPerLine()).clone();
    default:
        qDebug() << "Unsupported QImage format!";
        return cv::Mat();
    }
}

QImage PlateRecognize::cropPlateFromImage(const QImage plateImage, const QVector<QPoint> &points)
{
    if (points.size() != 4) return QImage();

    // 转成 cv::Mat
    cv::Mat src = QImageToMat(plateImage);
    cv::cvtColor(src, src, cv::COLOR_RGBA2BGR);  // 转成 BGR 模式（OpenCV 标准）

    // 原始四个角点（顶点）
    std::vector<cv::Point2f> srcPts = {
        cv::Point2f(points[0].x(), points[0].y()),
        cv::Point2f(points[1].x(), points[1].y()),
        cv::Point2f(points[2].x(), points[2].y()),
        cv::Point2f(points[3].x(), points[3].y())
    };

    // 目标宽高（你可以根据实际车牌比例调整）
    float width = 200.0f;
    float height = 60.0f;

    std::vector<cv::Point2f> dstPts = {
        cv::Point2f(0, 0),
        cv::Point2f(width - 1, 0),
        cv::Point2f(width - 1, height - 1),
        cv::Point2f(0, height - 1)
    };

    // 计算透视变换矩阵
    cv::Mat M = cv::getPerspectiveTransform(srcPts, dstPts);

    // 透视变换
    cv::Mat warped;
    cv::warpPerspective(src, warped, M, cv::Size(width, height));

    // 转回 QImage
    cv::cvtColor(warped, warped, cv::COLOR_BGR2RGB);
    return matToImage(warped);
}

