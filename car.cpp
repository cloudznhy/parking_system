#include "car.h"
#include "ui_car.h"
#include<QImageCapture>
#include<QVideoSink>
car::car(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::car)
{
    ui->setupUi(this);
    setWindowTitle("主界面");
    ui->stackedWidget->setCurrentIndex(2);
    connect(ui->mainButton,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->check_camera,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->ctrolButton,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->messageButton,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    video_Init();
    camera_Init();
    park_num();
    //ui->camera->setGeometry(10, 10, 485, 300);
    // static int CameraCount = Camera::getCameraCount();
    // if( CameraCount !=0)
    // {
    //     qDebug()<<"当前摄像头的个数"<<CameraCount;
    //     camera->start();  //让摄像头开始工作
    // }

    //connect(this,&car::now_count_dec_signal,&mysqlc,&mysql::park_reduce);
    //connect(this,&car::now_count_acc_signal,&mysqlc,&mysql::park_increase);
    t1=new QThread;
    t2=new QThread;
    //车牌识别初始化
    rec=new PlateRecognize;
    rec->moveToThread(t1);
    t1->start();

    connect(this,&car::plate_start,rec,&PlateRecognize::Recognize);
    connect(rec,&PlateRecognize::Recogned,this,[=](QImage localImg,QString platestr){
        // Mat plateImg=localImg.clone();
        // QImage screenImg(plateImg.data,plateImg.cols,plateImg.rows,static_cast<int>(plateImg.step),QImage::Format_RGB888);
        ui->screen_label->setPixmap(QPixmap::fromImage(localImg));
        ui->car_input->setText(platestr);
        ui->car_output->setText(platestr);
    });
    //更新饼图初始化
    updatepie=new UpdatePie;
    updatepie->moveToThread(t2);
    t2->start();
    connect(this,&car::updatepiedata,updatepie,&UpdatePie::checkPie);
    connect(updatepie,&UpdatePie::pieChanged,this,&car::createPie);
    emit updatepiedata(mysqlc.parkingname,mysqlc.reserve,mysqlc.parking_now_count);
}

car::~car()
{
    delete ui;
    // delete camera;
    // delete viewfinder;
    // delete player;
    // delete videowidget;
    // delete imagecapture;
    t1->quit();
    t1->wait();
    delete t1;
    t2->quit();
    t2->wait();
    delete t2;

}

bool car::checkPlateNumber(QString license_plate)
{
    //车牌位数
    if(license_plate.length()!=7&&license_plate.length()!=8){
        QMessageBox::information(this,"入场失败","车牌号位数不对");
        return false;
    }
    QString province="京津沪渝冀豫云辽黑湘皖鲁新苏浙赣鄂桂甘晋蒙陕吉闽贵粤青藏川宁琼";
    if(!province.contains(license_plate.left(1))){
        QMessageBox::information(this,"入场失败","车牌首位省份非法");
        return false;
    }
    QString letter = "ABCDEFGHJKLMNPQRSTUVWXYZ"; //序列号中的英文字母
    if(!letter.contains(license_plate.mid(1,1))){         //mid(1,1)从1索引开始提取长度为1的字符串
        QMessageBox::information(this,"入场失败","车牌第二位非法");
        return false;
    }
    return true;
}

int car::fee_charge(QDateTime oldDateTime, QDateTime currentDateTime, QString license_plate)
{
    qint64 seconds=oldDateTime.secsTo(currentDateTime);
    long hours=std::abs(seconds) / 3600LL;
    qDebug()<<seconds<<hours;
    if(hours<1){
        return 0;
    }
    QString sql_fee= QStringLiteral("SELECT parking.P_fee FROM parking JOIN car ON car.location = parking.P_name WHERE CAR.license_plate='%1';").arg(license_plate);
    QSqlQuery q=mysqlc.execute(sql_fee);
    q.next();
    int p_fee=q.value(0).toInt();
    int fee=p_fee*hours;
    return fee;
}

void car::print_widget(QSqlQuery q, int i)
{
    //每一次 行数加一
    ui->tableWidget->setRowCount(i+1);
    //第一列
    ui->tableWidget->setItem(i,0,new QTableWidgetItem(q.value(0).toString()));
    ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    //每i行的第0列为只读
    ui->tableWidget->item(i, 0)->setFlags(ui->tableWidget->item(i, 0)->flags() ^ Qt::ItemIsEditable);
    //第二列
    ui->tableWidget->setItem(i,1,new QTableWidgetItem(q.value(1).toString()));
    ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    //第三列
    QDateTimeEdit*datetimeedit=new QDateTimeEdit();
    datetimeedit->setDisplayFormat("yyyy-MM-dd hh::mm::ss");
    datetimeedit->setDateTime(q.value(2).toDateTime());
    ui->tableWidget->setCellWidget(i,2,datetimeedit);
    //第四列
    if(q.value(3).isNull()){
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(q.value(3).toString()));
        ui->tableWidget->item(i,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    }else{
        QDateTimeEdit*datetimeedit2=new QDateTimeEdit();
        datetimeedit2->setDisplayFormat("yyyy-MM-dd hh::mm::ss");
        datetimeedit2->setDateTime(q.value(3).toDateTime());
        ui->tableWidget->setCellWidget(i,3,datetimeedit2);
    }
    //第五列
    ui->tableWidget->setItem(i,4,new QTableWidgetItem(q.value(4).toString()));
    ui->tableWidget->item(i,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    //第六列
    ui->tableWidget->setItem(i,5,new QTableWidgetItem(q.value(5).toString()));
    ui->tableWidget->item(i,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    //第七列
    ui->tableWidget->setItem(i,6,new QTableWidgetItem(q.value(6).toString()));
    ui->tableWidget->item(i,6)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
}

void car::video_Init()
{
    player=new QMediaPlayer();//player=new QMediaPlayer(ui->camera);
    videoSink = new QVideoSink(this);
    player->setVideoSink(videoSink);
    // 设置视频显示在 QLabel 上（或者你 UI 里的 camera）
    connect(videoSink, &QVideoSink::videoFrameChanged, this, [=](const QVideoFrame &frame){
        if (frame.isValid()) {
            QImage img = frame.toImage();
            if (!img.isNull()) {
                ui->camera->setPixmap(QPixmap::fromImage(img).scaled(ui->camera->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            }
        }
    });
    connect(player,&QMediaPlayer::durationChanged,this,&car::get_Duration);

    connect(player,&QMediaPlayer::positionChanged,this,&car::On_position_Changed);

    connect(ui->horizontalSlider,&QSlider::valueChanged,this,&car::slider_Changed);

}

void car::camera_Init()
{
    videoSink = new QVideoSink(this);
    camera = new QCamera(QMediaDevices::defaultVideoInput(), this);
    mediaCaptureSession.setCamera(camera);
    mediaCaptureSession.setVideoOutput(videoSink);  // 不用 QVideoWidget

    connect(videoSink, &QVideoSink::videoFrameChanged, this, [=](const QVideoFrame &frame){
        if (frame.isValid()) {
            QImage img = frame.toImage();
            if (!img.isNull()) {
                ui->camera->setPixmap(QPixmap::fromImage(img).scaled(
                    ui->camera->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            }
        }
    });
    camera->start();
}

void car::park_num()
{
    QString park_name=mysqlc.parkingname;
    QString sql = QStringLiteral("SELECT P_now_count,  P_reserve_count FROM parking WHERE P_name = '%1'").arg(park_name);
    QSqlQuery q = mysqlc.execute(sql);
    q.next();
    int now_count=q.value(0).toInt();
    int reserve=q.value(1).toInt();
    mysqlc.parking_now_count=now_count;
    mysqlc.reserve=reserve;
    createPie(reserve);
}

void car::createPie(int reserve)
{
    mysqlc.reserve=reserve;
    int now=mysqlc.parking_now_count;
    int surplus=mysqlc.parking_count-mysqlc.parking_now_count-mysqlc.reserve;
    //创建饼图
    // 创建一个QPieSeries对象并添加数据//为每个分块设置颜色
    series=new QPieSeries;
    series->append("预约数",reserve);
    series->append("入库数",now)->setColor("#FFA500");
    series->append("剩余数",surplus);
    series->setHoleSize(0.1);
    series->pieSize();

    for (int i = 0; i <=2; ++i) {
        slice=series->slices().at(i);
        //设置标签文字，格式为：标签名: 值
        slice->setLabel(slice->label() + QString::asprintf(":%.0f", slice->value()));
        if(slice->value() < 10)
        {
            slice->setLabelVisible(false);
        }
        else {
            slice->setLabelVisible(true);
        }
        connect(slice,SIGNAL(hovered(bool)),this,SLOT(on_PieSliceHight(bool)));
    }
    slice->setExploded(true); // 最后一个分块设置为分裂效果
    slice->setExplodeDistanceFactor(0.1);

    chart=new QChart;
    chart->addSeries(series);
    chart->setTitle(mysqlc.parkingname);
    chart->legend()->setVisible(true); // 显示图例
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setBackgroundBrush(QBrush(QColor(255, 255, 255))); // 设置背景为白色

    chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->resize(340,290);
    chartview->backgroundBrush();

    QPixmap pixmap=chartview->grab();
    ui->label_pie->setPixmap(pixmap);
}

void car::get_Duration()
{
    ui->horizontalSlider->setMaximum(int(player->duration()));
}

void car::slider_Changed()
{
    pos=ui->horizontalSlider->value();
    player->setPosition(pos);
}

void car::On_position_Changed(qint64 position)
{
    ui->horizontalSlider->setValue(int(position));

}

void car::on_fileopen_clicked()
{
    if(camera->isActive()){
        //停止摄像头
        camera->stop();
        //隐藏摄像头显示区域
    }
    //viewfinder->setVisible(false);
    ui->camera->setVisible(true);
    ui->camera->clear();
   /* player->setVideoOutput(videowidget);
    videowidget->setVisible(true);
    videowidget->raise();*/         //提升层级
    filename=QFileDialog::getOpenFileName(this,"选择播放视频的文件","..\\");
    qDebug()<<filename;
    player->setSource(QUrl::fromLocalFile(filename));
    player->play();
}


void car::on_video_pause_clicked()
{
    if(camera->isActive()){
        camera->stop();
        cameraPaused=true;
    }else {
        player->pause();
    }
}


void car::on_video_start_clicked()
{
    if(camera->isAvailable()&&cameraPaused==true){
        camera->start();
        cameraPaused=false;
    }else {
        player->play();
    }
}


void car::on_camera_take_clicked()
{
    if (camera->isActive()) {
        // 拍照：使用 Qt6 的拍照接口
        imageCapture->captureToFile();
    }
    else if (player->playbackState() == QMediaPlayer::PlayingState) {
        if (videoSink && videoSink->videoFrame().isValid()) {
            QVideoFrame frame = videoSink->videoFrame();
            frame.map(QVideoFrame::ReadOnly);
            QImage image = frame.toImage();
            frame.unmap();
            emit plate_start(image);
            // if (!image.isNull()) {
            //     Mat mat(image.height(), image.width(), CV_8UC4, const_cast<uchar*>(image.bits()), image.bytesPerLine());
            //     Mat rgbMat;
            //     cvtColor(mat, rgbMat, COLOR_BGRA2RGB);
            //     emit plate_start(rgbMat);
            // } else {
            //     qDebug() << "QVideoFrame 转 QImage 失败";
            // }
        } else {
            qDebug() << "videoSink 无效或没有帧";
        }
    }
    else {
        // 从 QLabel 中获取图像
        QPixmap pixmap = ui->camera->pixmap();  // camera 是 QLabel 指针
        if (!pixmap.isNull()) {
            QImage img = pixmap.toImage();
            // Mat src = Mat(img.height(), img.width(), CV_8UC4, const_cast<uchar*>(img.bits()), static_cast<size_t>(img.bytesPerLine())).clone();
            // Mat rgbImg;
            // cvtColor(src, rgbImg, COLOR_BGRA2RGB); // BGRA 转 RGB
            emit plate_start(img);
        }
    }
}


void car::on_camera_button_clicked()
{
    // 停止视频播放（如果正在播放）
    if (player->playbackState() != QMediaPlayer::StoppedState) {
        player->stop();
    }

    // 停止摄像头（如果正在运行）
    if (camera && camera->isActive()) {
        camera->stop();
    }

    // 清空 QLabel 显示区域
    ui->camera->clear();
    ui->camera->setVisible(true);

    // 给系统一点时间释放摄像头资源
    QTimer::singleShot(100, this, [=]() {
        if (camera) {
            // 重新绑定（可选，防止状态错误）
            mediaCaptureSession.setCamera(camera);
            mediaCaptureSession.setVideoOutput(videoSink);

            // 启动摄像头
            camera->start();
        }
    });
}


void car::on_submitcar_clicked()
{
    QString license_plate=ui->car_input->text();
    if(!checkPlateNumber(license_plate)){
        return;
    }
    if((mysqlc.parking_now_count+mysqlc.reserve)>mysqlc.parking_count){
        QMessageBox::information(this,"入场失败","车位已满");
        qDebug()<<"现有车位"<<mysqlc.parking_now_count<<"预约量:"<<mysqlc.reserve<<"总车位:"<<mysqlc.parking_count;
        return;
    }
    q.prepare("select check_in_time,check_out_time from car where license_plate=:license_plate");
    q.bindValue(":license_plate",license_plate);
    q.exec();
    q.next();
    if(!q.value(0).isNull()&&q.value(1).isNull()){   //入库时间不为空，出库时间为空 车辆还没出库
        QMessageBox::information(this,"入库失败","车辆还未出库");
        return;
    }
    QDateTime currentDateTime = QDateTime::currentDateTime();
    // 将时间转换为字符串格式（格式化为 "yyyy-MM-dd hh:mm:ss"）存储到MySQL的database
    QString formattedDateTime = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
    //将信息上传到数据库
    //位置
    QString location = mysqlc.parkingname;

    QString sql_submitCar = QStringLiteral("INSERT INTO CAR (license_plate, check_in_time,location) VALUES ('%1','%2','%3');").arg(license_plate,formattedDateTime,location);

    if(mysqlc.bool_execute(sql_submitCar))
    {
        qDebug()<<"车牌数据插入成功";
        ui->car_input->clear();  //清空输入框
        QMessageBox::information(this,"停车入库","车牌入库成功!");


        mysqlc.park_increase(); //让现有车库加一
        //emit now_count_acc_signal();
        qDebug()<<mysqlc.parking_now_count;
        park_num();

    }
    else {
        qDebug()<<"车牌插入失败";

        QMessageBox::information(this,"停车入库","车牌入库失败！！");

    }

}


void car::on_deletecar_clicked()
{
    QString license_plate=ui->car_output->text();
    if(!checkPlateNumber(license_plate))
    {
        return;
    }
    QString sqlplate_Check=QStringLiteral("select id from car where license_plate='%1' and check_out_time is null").arg(license_plate);
    QSqlQuery query=mysqlc.execute(sqlplate_Check);
    if(!query.size()) //如果不存在此数据
    {
        QMessageBox::information(this,"入库检测","当前车牌不在车库当中!!");
        return ;
    }
    QString sql_time= QStringLiteral("select check_in_time from CAR where license_plate = '%1' ORDER BY check_in_time DESC;").arg(license_plate);
    QSqlQuery q = mysqlc.execute(sql_time);
    q.next();
    QDateTime oldDateTime = q.value(0).toDateTime();



    //获取当前的时间
    // 获取当前时间
    QDateTime currentDateTime = QDateTime::currentDateTime();
    // 将时间转换为字符串格式（格式化为 "yyyy-MM-dd hh:mm:ss"）存储到MySQL的database
    QString formattedDateTime = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");

    //qDebug()<<oldDateTime<<currentDateTime;
    //根据时间计算费用
    //调用时间函数，传入参数，识别的车牌号（去求过去的时间)，还有现在的时间,根据时间差去求所需要的费用
    qDebug()<<oldDateTime<<currentDateTime;
    int fee = fee_charge(oldDateTime,currentDateTime,license_plate);


    //将信息上传到数据库
    qDebug()<<formattedDateTime<<fee<<license_plate;


    //QString sql_submitfee = QStringLiteral("UPDATE CAR SET check_out_time='%1', fee='%2' WHERE license_plate='%3';").arg(formattedDateTime,fee,QChar::fromLatin1(license_plate.toLatin1()[0]));

    //q.prepare("UPDATE CAR SET check_out_time=:check_out_time, fee=:fee WHERE license_plate=:license_plate");
    q.prepare("update car set check_out_time=:check_out_time,fee=:fee where license_plate=:license_plate");
    q.bindValue(":check_out_time", formattedDateTime);
    q.bindValue(":fee", fee);
    q.bindValue(":license_plate", license_plate);

    if(q.exec())
    {
        qDebug()<<"车辆出库成功";
        ui->car_output->clear();  //清空输入框
        QString message = QString("出库成功，车牌号'%1'需要支付'%2'元").arg(license_plate, QString::number(fee, 'f', 2));

        QMessageBox::information(this,"停车出库库",message);
        //车牌插入成功后，更新车库数据
        mysqlc.park_reduce(); //让现有车位数量减一
        //emit now_count_dec_signal();
        park_num();

    }
    else {
        qDebug()<<"车牌出库失败";
        //qDebug()<<sql_submitfee;
        QMessageBox::information(this,"停车入库","车牌出库失败！！");

    }
}


void car::on_pictureopen_clicked()
{
    if(camera->isActive()){
        //停止摄像头
        camera->stop();
        //隐藏摄像头显示区域
        //将显示区域设置为文件播放的videowidget
    }
    //viewfinder->setVisible(false);
    if(player->isPlaying()){
        player->stop();
    }
    //viewfinder->setVisible(false);
    ui->camera->setVisible(true);
    //videowidget->setVisible(false);
    QString filepath=QFileDialog::getOpenFileName(this,"选取图片","..\\");
    QPixmap*pix=new QPixmap(filepath);
    ui->camera->setPixmap(pix->scaled(450,320, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void car::on_PieSliceHight(bool show)
{
    slice=static_cast<QPieSlice*>(sender());
    slice->setExploded(true);
}


void car::on_messageButton_clicked()
{
    if ((camera && camera->isActive()) ||
        (player && (player->playbackState() == QMediaPlayer::PlayingState ||
                    player->playbackState() == QMediaPlayer::PausedState))){
        player->stop();
        viewfinder->setVisible(false);
        //videowidget->setVisible(false);
    }
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setColumnWidth(2,150); //第三列宽度
    ui->tableWidget->setColumnWidth(3,150);//第四列宽度
    ui->tableWidget->verticalHeader()->setVisible(false);
    QStringList header;
    header<<"ID"<<"车牌号"<<"入库时间"<<"出库时间"<<"费用"<<"停车地点"<<"车费单价";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    QString sqlstrCar="SELECT id, license_plate, check_in_time, check_out_time, fee, location, P_fee FROM CAR JOIN parking ON Car.location = parking.P_name ORDER BY check_in_time DESC;";
    QSqlQuery q=mysqlc.execute(sqlstrCar);
    int i = 0;
    while(q.next()) {
        print_widget(q,i);
        i++;
    }
}


void car::on_carcheck_clicked()
{
    //读取用户的输入数据
    QString Car_name = ui->find_lineEdit->text();
    QDateTime begin_datetimes = ui->beginTimeEdit->dateTime();
    QDateTime end_datetimes = ui->endTimeEdit->dateTime();
    QString begin_time = begin_datetimes.toString("yyyy-MM-dd hh:mm:ss");
    QString end_time = end_datetimes.toString("yyyy-MM-dd hh:mm:ss");
    //书写sql语句
    //如果用户没有输入车牌号 则不显示
    if(Car_name.isEmpty())
    {
        //名字为空根据时间查询
        //qDebug()<<"名字为空"<<begin_time<<end_time;

        q.prepare("SELECT id, license_plate, check_in_time, check_out_time, fee, location, P_fee from car JOIN parking ON car.location = parking.P_name WHERE check_in_time BETWEEN :begin_time AND :end_time;");
        q.bindValue(":begin_time", begin_time);
        q.bindValue(":end_time", end_time);
        int i = 0;
        if(q.exec())
        {

            while (q.next()) {
                print_widget(q,i);
                i++;
            }
        }
    }
    else
    {   //名字不为空，根据时间和 名字
        //qDebug()<<"名字为空"<<begin_time<<end_time;
        q.prepare("SELECT id, license_plate, check_in_time, check_out_time, fee, location, P_fee from car JOIN parking ON car.location = parking.P_name WHERE check_in_time BETWEEN :begin_time AND :end_time AND license_plate =:Car_name;");
        q.bindValue(":begin_time", begin_time);
        q.bindValue(":end_time", end_time);
        q.bindValue(":Car_name",Car_name);
        int i = 0;
        if(q.exec())
        {
            while (q.next())
            {
                print_widget(q,i);
                i++;
            }
        }
    }
}


void car::on_cardelete_clicked()
{
    //读取当前鼠标所在车辆信息表的行数
    int row = ui->tableWidget->currentRow();
    qDebug()<<row;
    if(row>=0)
    {
        //读取用户点击位置的车牌号
        QString id = ui->tableWidget->item(row,0)->text();

        QString sql_Drop_car = QStringLiteral("DELETE FROM CAR WHERE id = '%1';").arg(id);

        if (mysqlc.bool_execute(sql_Drop_car))
        {
            qDebug() << "CAR delete successfully.";
            car::on_messageButton_clicked(); //模拟点击，更新
            // TODO现有车位同步
            mysqlc.park_reduce();
        }
        else
        {
            qDebug()<<sql_Drop_car;
            qDebug() << "User Add error" << id;
        }
    }
}

