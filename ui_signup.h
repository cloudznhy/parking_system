/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

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

class Ui_signup
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *imglabel;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLineEdit *account;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QLineEdit *signup_password;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_3;
    QLineEdit *signup_password2;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *return_2;
    QPushButton *confirm;

    void setupUi(QWidget *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName(QString::fromUtf8("signup"));
        signup->resize(604, 373);
        signup->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(signup);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 591, 361));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        imglabel = new QLabel(layoutWidget);
        imglabel->setObjectName(QString::fromUtf8("imglabel"));
        imglabel->setMinimumSize(QSize(300, 300));

        horizontalLayout_2->addWidget(imglabel);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\345\275\251\344\272\221"));
        font.setPointSize(14);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));
        label->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(label);

        account = new QLineEdit(layoutWidget);
        account->setObjectName(QString::fromUtf8("account"));
        account->setMinimumSize(QSize(0, 40));
        account->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;\n"
"font: 10pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";"));

        verticalLayout->addWidget(account);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 50));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(label_2);

        signup_password = new QLineEdit(layoutWidget);
        signup_password->setObjectName(QString::fromUtf8("signup_password"));
        signup_password->setMinimumSize(QSize(0, 40));
        signup_password->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;\n"
"font: 10pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";"));

        verticalLayout->addWidget(signup_password);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_3);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 50));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8(""));
        label_3->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(label_3);

        signup_password2 = new QLineEdit(layoutWidget);
        signup_password2->setObjectName(QString::fromUtf8("signup_password2"));
        signup_password2->setMinimumSize(QSize(0, 40));
        signup_password2->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;\n"
"font: 10pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";"));

        verticalLayout->addWidget(signup_password2);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        return_2 = new QPushButton(layoutWidget);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setMinimumSize(QSize(30, 40));
        return_2->setStyleSheet(QString::fromUtf8("background-color:qlineargradient(spread:pad,x1:0.52,y1:1,x2:0.54,y2:0,\n"
"stop:0.0112994  rgba(64,145,232,255),\n"
"stop:1 rgba(255,255,255,255));\n"
"color:rgb(255,255,255);\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;\n"
"font:14pt\"\345\215\216\346\226\207\351\232\266\344\271\246\"\n"
"\n"
"\n"
""));

        horizontalLayout->addWidget(return_2);

        confirm = new QPushButton(layoutWidget);
        confirm->setObjectName(QString::fromUtf8("confirm"));
        confirm->setMinimumSize(QSize(30, 40));
        confirm->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.52, y1:1, x2:0.54, y2:0, \n"
"stop:0.0112994 rgba(64, 145, 232, 255), \n"
"stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"border:0px groove gray;\n"
"border-radius:7px;\n"
"padding:2px 4px;\n"
"font: 14pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";"));

        horizontalLayout->addWidget(confirm);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QWidget *signup)
    {
        signup->setWindowTitle(QCoreApplication::translate("signup", "Form", nullptr));
        imglabel->setText(QString());
        label->setText(QCoreApplication::translate("signup", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("signup", "\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("signup", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        return_2->setText(QCoreApplication::translate("signup", "\350\277\224\345\233\236", nullptr));
        confirm->setText(QCoreApplication::translate("signup", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
