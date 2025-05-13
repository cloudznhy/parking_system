/********************************************************************************
** Form generated from reading UI file 'car.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAR_H
#define UI_CAR_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_car
{
public:
    QStackedWidget *stackedWidget;
    QWidget *message;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *find_lineEdit;
    QDateTimeEdit *beginTimeEdit;
    QDateTimeEdit *endTimeEdit;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *carcheck;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *cardelete;
    QSpacerItem *horizontalSpacer_7;
    QTableWidget *tableWidget;
    QWidget *camera_page;
    QLabel *camera_label;
    QPushButton *thread_camera_init;
    QComboBox *comboBox;
    QPushButton *camera_opem_button;
    QPushButton *thread_release;
    QPushButton *thread_pasuse;
    QWidget *main;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *camera;
    QLabel *label_pie;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *car_input;
    QPushButton *submitcar;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *car_output;
    QPushButton *deletecar;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout;
    QPushButton *fileopen;
    QPushButton *pictureopen;
    QLabel *screen_label;
    QPushButton *camera_button;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *video_pause;
    QPushButton *camera_take;
    QPushButton *video_start;
    QWidget *ctrol;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *check_camera;
    QSpacerItem *verticalSpacer_2;
    QPushButton *ctrolButton;
    QSpacerItem *verticalSpacer_3;
    QPushButton *messageButton;
    QSpacerItem *verticalSpacer_4;
    QPushButton *mainButton;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QWidget *car)
    {
        if (car->objectName().isEmpty())
            car->setObjectName("car");
        car->resize(994, 625);
        car->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        stackedWidget = new QStackedWidget(car);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 10, 831, 561));
        message = new QWidget();
        message->setObjectName("message");
        horizontalLayoutWidget = new QWidget(message);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 40, 671, 51));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName("label_4");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(110, 35));
        label_4->setStyleSheet(QString::fromUtf8("font: 13pt \"\346\226\260\345\256\213\344\275\223\";"));

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        find_lineEdit = new QLineEdit(horizontalLayoutWidget);
        find_lineEdit->setObjectName("find_lineEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(find_lineEdit->sizePolicy().hasHeightForWidth());
        find_lineEdit->setSizePolicy(sizePolicy1);
        find_lineEdit->setMinimumSize(QSize(90, 0));
        find_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_4->addWidget(find_lineEdit);

        beginTimeEdit = new QDateTimeEdit(horizontalLayoutWidget);
        beginTimeEdit->setObjectName("beginTimeEdit");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(beginTimeEdit->sizePolicy().hasHeightForWidth());
        beginTimeEdit->setSizePolicy(sizePolicy2);
        beginTimeEdit->setMinimumSize(QSize(120, 0));
        beginTimeEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;\n"
"font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        beginTimeEdit->setDateTime(QDateTime(QDate(2025, 4, 1), QTime(0, 0, 0)));
        beginTimeEdit->setDate(QDate(2025, 4, 1));
        beginTimeEdit->setCurrentSection(QDateTimeEdit::Section::DaySection);

        horizontalLayout_4->addWidget(beginTimeEdit);

        endTimeEdit = new QDateTimeEdit(horizontalLayoutWidget);
        endTimeEdit->setObjectName("endTimeEdit");
        sizePolicy2.setHeightForWidth(endTimeEdit->sizePolicy().hasHeightForWidth());
        endTimeEdit->setSizePolicy(sizePolicy2);
        endTimeEdit->setMinimumSize(QSize(120, 0));
        endTimeEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;\n"
"font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        endTimeEdit->setDateTime(QDateTime(QDate(2025, 4, 1), QTime(0, 0, 0)));
        endTimeEdit->setDate(QDate(2025, 4, 1));
        endTimeEdit->setCurrentSection(QDateTimeEdit::Section::DaySection);

        horizontalLayout_4->addWidget(endTimeEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        carcheck = new QPushButton(horizontalLayoutWidget);
        carcheck->setObjectName("carcheck");
        sizePolicy2.setHeightForWidth(carcheck->sizePolicy().hasHeightForWidth());
        carcheck->setSizePolicy(sizePolicy2);
        carcheck->setMinimumSize(QSize(70, 35));
        carcheck->setStyleSheet(QString::fromUtf8("background-color:#95E1D3;\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:white;\n"
"border-radius:7px;"));

        horizontalLayout_4->addWidget(carcheck);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        cardelete = new QPushButton(horizontalLayoutWidget);
        cardelete->setObjectName("cardelete");
        sizePolicy2.setHeightForWidth(cardelete->sizePolicy().hasHeightForWidth());
        cardelete->setSizePolicy(sizePolicy2);
        cardelete->setMinimumSize(QSize(70, 35));
        cardelete->setStyleSheet(QString::fromUtf8("background-color:#95E1D3;\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:white;\n"
"border-radius:7px;"));

        horizontalLayout_4->addWidget(cardelete);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        tableWidget = new QTableWidget(message);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        if (tableWidget->rowCount() < 10)
            tableWidget->setRowCount(10);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 100, 781, 441));
        tableWidget->setShowGrid(true);
        tableWidget->setSortingEnabled(false);
        tableWidget->setRowCount(10);
        tableWidget->setColumnCount(7);
        stackedWidget->addWidget(message);
        camera_page = new QWidget();
        camera_page->setObjectName("camera_page");
        camera_label = new QLabel(camera_page);
        camera_label->setObjectName("camera_label");
        camera_label->setGeometry(QRect(170, 20, 521, 321));
        thread_camera_init = new QPushButton(camera_page);
        thread_camera_init->setObjectName("thread_camera_init");
        thread_camera_init->setGeometry(QRect(100, 370, 81, 51));
        comboBox = new QComboBox(camera_page);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(240, 370, 61, 51));
        camera_opem_button = new QPushButton(camera_page);
        camera_opem_button->setObjectName("camera_opem_button");
        camera_opem_button->setGeometry(QRect(370, 370, 71, 51));
        thread_release = new QPushButton(camera_page);
        thread_release->setObjectName("thread_release");
        thread_release->setGeometry(QRect(480, 370, 81, 51));
        thread_pasuse = new QPushButton(camera_page);
        thread_pasuse->setObjectName("thread_pasuse");
        thread_pasuse->setGeometry(QRect(620, 370, 81, 51));
        stackedWidget->addWidget(camera_page);
        main = new QWidget();
        main->setObjectName("main");
        gridLayoutWidget = new QWidget(main);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 811, 572));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        camera = new QLabel(gridLayoutWidget);
        camera->setObjectName("camera");
        sizePolicy.setHeightForWidth(camera->sizePolicy().hasHeightForWidth());
        camera->setSizePolicy(sizePolicy);
        camera->setMinimumSize(QSize(450, 320));

        gridLayout->addWidget(camera, 0, 0, 1, 1);

        label_pie = new QLabel(gridLayoutWidget);
        label_pie->setObjectName("label_pie");

        gridLayout->addWidget(label_pie, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);

        label_title = new QLabel(gridLayoutWidget);
        label_title->setObjectName("label_title");
        label_title->setMinimumSize(QSize(0, 50));
        label_title->setMaximumSize(QSize(16777215, 16777215));
        label_title->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_title->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_2->addWidget(label_title);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(10);
        verticalLayout_5->setObjectName("verticalLayout_5");
        car_input = new QLineEdit(gridLayoutWidget);
        car_input->setObjectName("car_input");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(car_input->sizePolicy().hasHeightForWidth());
        car_input->setSizePolicy(sizePolicy3);
        car_input->setMinimumSize(QSize(0, 40));
        car_input->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        verticalLayout_5->addWidget(car_input);

        submitcar = new QPushButton(gridLayoutWidget);
        submitcar->setObjectName("submitcar");
        submitcar->setMinimumSize(QSize(0, 35));
        submitcar->setStyleSheet(QString::fromUtf8("background-color:#95E1D3;\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:white;\n"
"border-radius:7px;"));

        verticalLayout_5->addWidget(submitcar);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(10);
        verticalLayout_4->setObjectName("verticalLayout_4");
        car_output = new QLineEdit(gridLayoutWidget);
        car_output->setObjectName("car_output");
        sizePolicy3.setHeightForWidth(car_output->sizePolicy().hasHeightForWidth());
        car_output->setSizePolicy(sizePolicy3);
        car_output->setMinimumSize(QSize(0, 40));
        car_output->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        verticalLayout_4->addWidget(car_output);

        deletecar = new QPushButton(gridLayoutWidget);
        deletecar->setObjectName("deletecar");
        deletecar->setMinimumSize(QSize(0, 35));
        deletecar->setStyleSheet(QString::fromUtf8("background-color:#95E1D3;\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:white;\n"
"border-radius:7px;"));

        verticalLayout_4->addWidget(deletecar);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy4);
        label_3->setMinimumSize(QSize(0, 25));

        verticalLayout_2->addWidget(label_3);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalSlider = new QSlider(gridLayoutWidget);
        horizontalSlider->setObjectName("horizontalSlider");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy5);
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout_3->addWidget(horizontalSlider);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        fileopen = new QPushButton(gridLayoutWidget);
        fileopen->setObjectName("fileopen");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(fileopen->sizePolicy().hasHeightForWidth());
        fileopen->setSizePolicy(sizePolicy6);
        fileopen->setMinimumSize(QSize(77, 35));
        fileopen->setStyleSheet(QString::fromUtf8("background-color:#95E1D3;\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:white;\n"
"border-radius:7px;"));

        horizontalLayout->addWidget(fileopen);

        pictureopen = new QPushButton(gridLayoutWidget);
        pictureopen->setObjectName("pictureopen");
        sizePolicy6.setHeightForWidth(pictureopen->sizePolicy().hasHeightForWidth());
        pictureopen->setSizePolicy(sizePolicy6);
        pictureopen->setMinimumSize(QSize(77, 35));
        pictureopen->setStyleSheet(QString::fromUtf8("background-color:#95E1D3;\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:white;\n"
"border-radius:7px;"));

        horizontalLayout->addWidget(pictureopen);

        screen_label = new QLabel(gridLayoutWidget);
        screen_label->setObjectName("screen_label");

        horizontalLayout->addWidget(screen_label);

        camera_button = new QPushButton(gridLayoutWidget);
        camera_button->setObjectName("camera_button");
        camera_button->setMinimumSize(QSize(0, 35));
        camera_button->setStyleSheet(QString::fromUtf8("background-color:#95E1D3;\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:white;\n"
"border-radius:7px;"));

        horizontalLayout->addWidget(camera_button);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        video_pause = new QPushButton(gridLayoutWidget);
        video_pause->setObjectName("video_pause");
        video_pause->setMinimumSize(QSize(0, 35));
        video_pause->setStyleSheet(QString::fromUtf8("background-color:#95E1D3;\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:white;\n"
"border-radius:7px;"));

        horizontalLayout_3->addWidget(video_pause);

        camera_take = new QPushButton(gridLayoutWidget);
        camera_take->setObjectName("camera_take");
        camera_take->setMinimumSize(QSize(0, 35));
        camera_take->setStyleSheet(QString::fromUtf8("background-color:#95E1D3;\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:white;\n"
"border-radius:7px;"));

        horizontalLayout_3->addWidget(camera_take);

        video_start = new QPushButton(gridLayoutWidget);
        video_start->setObjectName("video_start");
        video_start->setMinimumSize(QSize(0, 35));
        video_start->setStyleSheet(QString::fromUtf8("background-color:#95E1D3;\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:white;\n"
"border-radius:7px;"));

        horizontalLayout_3->addWidget(video_start);


        verticalLayout_3->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_3, 1, 0, 1, 1);

        stackedWidget->addWidget(main);
        ctrol = new QWidget();
        ctrol->setObjectName("ctrol");
        gridLayoutWidget_2 = new QWidget(ctrol);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(-1, 9, 801, 541));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedWidget->addWidget(ctrol);
        verticalLayoutWidget = new QWidget(car);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(840, 0, 141, 571));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        check_camera = new QPushButton(verticalLayoutWidget);
        check_camera->setObjectName("check_camera");
        check_camera->setMinimumSize(QSize(35, 45));
        check_camera->setStyleSheet(QString::fromUtf8("background-color:#95E1D3;\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:white;\n"
"border-radius:7px;"));

        verticalLayout->addWidget(check_camera);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        ctrolButton = new QPushButton(verticalLayoutWidget);
        ctrolButton->setObjectName("ctrolButton");
        ctrolButton->setMinimumSize(QSize(35, 45));
        ctrolButton->setStyleSheet(QString::fromUtf8("background-color:#95E1D3;\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:white;\n"
"border-radius:7px;"));

        verticalLayout->addWidget(ctrolButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        messageButton = new QPushButton(verticalLayoutWidget);
        messageButton->setObjectName("messageButton");
        messageButton->setMinimumSize(QSize(35, 45));
        messageButton->setStyleSheet(QString::fromUtf8("background-color:#95E1D3;\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:white;\n"
"border-radius:7px;"));

        verticalLayout->addWidget(messageButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        mainButton = new QPushButton(verticalLayoutWidget);
        mainButton->setObjectName("mainButton");
        mainButton->setMinimumSize(QSize(35, 45));
        mainButton->setStyleSheet(QString::fromUtf8("background-color:#95E1D3;\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:white;\n"
"border-radius:7px;"));

        verticalLayout->addWidget(mainButton);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);


        retranslateUi(car);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(car);
    } // setupUi

    void retranslateUi(QWidget *car)
    {
        car->setWindowTitle(QCoreApplication::translate("car", "Form", nullptr));
        label_4->setText(QCoreApplication::translate("car", "\350\275\246\345\272\223\344\277\241\346\201\257\347\263\273\347\273\237", nullptr));
        find_lineEdit->setPlaceholderText(QCoreApplication::translate("car", "\346\237\245\350\257\242\347\232\204\350\275\246\347\211\214\345\217\267", nullptr));
        carcheck->setText(QCoreApplication::translate("car", "\346\237\245\350\257\242", nullptr));
        cardelete->setText(QCoreApplication::translate("car", "\345\210\240\351\231\244", nullptr));
        camera_label->setText(QString());
        thread_camera_init->setText(QCoreApplication::translate("car", "\345\210\235\345\247\213\345\214\226", nullptr));
        camera_opem_button->setText(QCoreApplication::translate("car", "open", nullptr));
        thread_release->setText(QCoreApplication::translate("car", "\351\207\212\346\224\276\350\265\204\346\272\220", nullptr));
        thread_pasuse->setText(QCoreApplication::translate("car", "\346\232\202\345\201\234", nullptr));
        camera->setText(QString());
        label_pie->setText(QString());
        label_title->setText(QCoreApplication::translate("car", "\350\257\206\345\210\253\347\232\204\350\275\246\347\211\214\345\217\267", nullptr));
        car_input->setText(QString());
        car_input->setPlaceholderText(QCoreApplication::translate("car", "\345\205\245\345\272\223\350\275\246\347\211\214\345\217\267", nullptr));
        submitcar->setText(QCoreApplication::translate("car", "\345\205\245\345\272\223", nullptr));
        car_output->setText(QString());
        car_output->setPlaceholderText(QCoreApplication::translate("car", "\345\207\272\345\272\223\350\275\246\347\211\214\345\217\267", nullptr));
        deletecar->setText(QCoreApplication::translate("car", "\345\207\272\345\272\223", nullptr));
        label_3->setText(QString());
        fileopen->setText(QCoreApplication::translate("car", "\350\247\206\351\242\221", nullptr));
        pictureopen->setText(QCoreApplication::translate("car", "\345\233\276\347\211\207", nullptr));
        screen_label->setText(QString());
        camera_button->setText(QCoreApplication::translate("car", "\346\221\204\345\203\217\345\244\264", nullptr));
        video_pause->setText(QCoreApplication::translate("car", "\346\232\202\345\201\234", nullptr));
        camera_take->setText(QCoreApplication::translate("car", "\346\210\252\345\217\226\347\205\247\347\211\207", nullptr));
        video_start->setText(QCoreApplication::translate("car", "\346\222\255\346\224\276", nullptr));
        check_camera->setText(QCoreApplication::translate("car", "\347\233\221\346\216\247", nullptr));
        ctrolButton->setText(QCoreApplication::translate("car", "\347\256\241\347\220\206\351\241\265\351\235\242", nullptr));
        messageButton->setText(QCoreApplication::translate("car", "\350\275\246\350\276\206\344\277\241\346\201\257", nullptr));
        mainButton->setText(QCoreApplication::translate("car", "\344\270\273\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class car: public Ui_car {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAR_H
