/********************************************************************************
** Form generated from reading UI file 'initfile.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITFILE_H
#define UI_INITFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_initfile
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *cancel;
    QPushButton *submit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *ip;
    QLineEdit *port;
    QLineEdit *databasename;
    QLineEdit *account;
    QLineEdit *password;
    QLineEdit *parkingname;
    QLineEdit *fee;
    QLineEdit *allcount;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *initfile)
    {
        if (initfile->objectName().isEmpty())
            initfile->setObjectName(QString::fromUtf8("initfile"));
        initfile->resize(391, 446);
        horizontalLayoutWidget = new QWidget(initfile);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 369, 381, 71));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setSpacing(40);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        cancel = new QPushButton(horizontalLayoutWidget);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setMinimumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(cancel);

        submit = new QPushButton(horizontalLayoutWidget);
        submit->setObjectName(QString::fromUtf8("submit"));
        submit->setMinimumSize(QSize(20, 30));

        horizontalLayout_2->addWidget(submit);

        layoutWidget = new QWidget(initfile);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 381, 351));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(100, 0));
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_9->setMargin(0);

        horizontalLayout->addWidget(label_9);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(90, 0));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_3);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_6);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_2);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_7);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_5);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_4);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_8);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ip = new QLineEdit(layoutWidget);
        ip->setObjectName(QString::fromUtf8("ip"));
        ip->setEnabled(true);
        ip->setMinimumSize(QSize(1, 35));

        verticalLayout_2->addWidget(ip);

        port = new QLineEdit(layoutWidget);
        port->setObjectName(QString::fromUtf8("port"));
        port->setMinimumSize(QSize(0, 35));

        verticalLayout_2->addWidget(port);

        databasename = new QLineEdit(layoutWidget);
        databasename->setObjectName(QString::fromUtf8("databasename"));
        databasename->setMinimumSize(QSize(1, 35));

        verticalLayout_2->addWidget(databasename);

        account = new QLineEdit(layoutWidget);
        account->setObjectName(QString::fromUtf8("account"));
        account->setMinimumSize(QSize(1, 35));

        verticalLayout_2->addWidget(account);

        password = new QLineEdit(layoutWidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setMinimumSize(QSize(1, 35));

        verticalLayout_2->addWidget(password);

        parkingname = new QLineEdit(layoutWidget);
        parkingname->setObjectName(QString::fromUtf8("parkingname"));
        parkingname->setMinimumSize(QSize(1, 35));

        verticalLayout_2->addWidget(parkingname);

        fee = new QLineEdit(layoutWidget);
        fee->setObjectName(QString::fromUtf8("fee"));
        fee->setMinimumSize(QSize(1, 35));

        verticalLayout_2->addWidget(fee);

        allcount = new QLineEdit(layoutWidget);
        allcount->setObjectName(QString::fromUtf8("allcount"));
        allcount->setMinimumSize(QSize(1, 35));

        verticalLayout_2->addWidget(allcount);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(initfile);

        QMetaObject::connectSlotsByName(initfile);
    } // setupUi

    void retranslateUi(QWidget *initfile)
    {
        initfile->setWindowTitle(QCoreApplication::translate("initfile", "Form", nullptr));
        cancel->setText(QCoreApplication::translate("initfile", "\345\217\226\346\266\210", nullptr));
        submit->setText(QCoreApplication::translate("initfile", "\347\241\256\345\256\232", nullptr));
        label_9->setText(QCoreApplication::translate("initfile", "\345\201\234\350\275\246\345\234\272\346\225\260\346\215\256\345\210\235\345\247\213\345\214\226", nullptr));
        label_3->setText(QCoreApplication::translate("initfile", " IP", nullptr));
        label_6->setText(QCoreApplication::translate("initfile", "\347\253\257\345\217\243\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("initfile", "\346\225\260\346\215\256\345\272\223\345\220\215", nullptr));
        label_7->setText(QCoreApplication::translate("initfile", "\350\264\246\345\217\267", nullptr));
        label->setText(QCoreApplication::translate("initfile", "\345\257\206\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("initfile", "\345\201\234\350\275\246\345\234\272\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("initfile", "\345\201\234\350\275\246\345\234\272\344\273\267\346\240\274", nullptr));
        label_8->setText(QCoreApplication::translate("initfile", "\345\201\234\350\275\246\345\234\272\345\256\271\351\207\217", nullptr));
        ip->setText(QCoreApplication::translate("initfile", "127.0.0.1", nullptr));
        port->setText(QCoreApplication::translate("initfile", "3306", nullptr));
        databasename->setText(QCoreApplication::translate("initfile", "park", nullptr));
        account->setText(QCoreApplication::translate("initfile", "root", nullptr));
        parkingname->setText(QCoreApplication::translate("initfile", "1", nullptr));
        fee->setText(QCoreApplication::translate("initfile", "10", nullptr));
        allcount->setText(QCoreApplication::translate("initfile", "300", nullptr));
    } // retranslateUi

};

namespace Ui {
    class initfile: public Ui_initfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITFILE_H
