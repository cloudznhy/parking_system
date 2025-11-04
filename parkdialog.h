#ifndef PARKDIALOG_H
#define PARKDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QDialogButtonBox>
#include<QLabel>
class ParkDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ParkDialog(QWidget *parent = nullptr)
        : QDialog(parent)
    {
        setWindowTitle("新增停车场");
        setModal(true);
        setMinimumWidth(380);

        // 全局样式，贴合现有按钮主题色
        setStyleSheet(
            "QLabel{font: 10pt \"微软雅黑\";}"
            "QLineEdit,QSpinBox,QDoubleSpinBox{background:#F7F7F7;border:1px solid #CFCFCF;border-radius:6px;padding:4px;font:10pt \"微软雅黑\";}"
            "QDialogButtonBox QPushButton{background-color:#95E1D3;color:#fff;border-radius:7px;height:32px;padding:0 14px;font:10pt \"微软雅黑\";}"
            "QDialogButtonBox QPushButton:hover{filter:brightness(0.95);}"
        );

        QVBoxLayout *root = new QVBoxLayout(this);

        QLabel *title = new QLabel("停车场信息", this);
        QFont tf = title->font(); tf.setPointSize(12); tf.setBold(true);
        title->setFont(tf);
        root->addWidget(title);

        QFormLayout *form = new QFormLayout();
        form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
        form->setFormAlignment(Qt::AlignJustify);
        form->setRowWrapPolicy(QFormLayout::DontWrapRows);
        form->setHorizontalSpacing(14);
        form->setVerticalSpacing(10);

        nameEdit = new QLineEdit(this);
        nameEdit->setPlaceholderText("请输入停车场名称，如 A 区");
        reserveSpin = new QSpinBox(this);
        nowSpin = new QSpinBox(this);
        allSpin = new QSpinBox(this);
        feeSpin = new QDoubleSpinBox(this);

        reserveSpin->setRange(0, 1000000);
        nowSpin->setRange(0, 1000000);
        allSpin->setRange(0, 1000000);
        feeSpin->setRange(0.0, 1000000.0);
        feeSpin->setDecimals(2);
        feeSpin->setSuffix(" 元/小时");

        // 默认值
        reserveSpin->setValue(0);
        nowSpin->setValue(0);
        allSpin->setValue(100);
        feeSpin->setValue(10.0);

        form->addRow(tr("名称"), nameEdit);
        form->addRow(tr("预约数"), reserveSpin);
        form->addRow(tr("现有数"), nowSpin);
        form->addRow(tr("总车位"), allSpin);
        form->addRow(tr("单价"), feeSpin);

        root->addLayout(form);

        QDialogButtonBox *buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
        root->addWidget(buttons);
        connect(buttons, &QDialogButtonBox::accepted, this, &QDialog::accept);
        connect(buttons, &QDialogButtonBox::rejected, this, &QDialog::reject);
    }

    QString pName() const { return nameEdit->text(); }
    int pReserve() const { return reserveSpin->value(); }
    int pNow() const { return nowSpin->value(); }
    int pAll() const { return allSpin->value(); }
    double pFee() const { return feeSpin->value(); }

private:
    QLineEdit *nameEdit;
    QSpinBox *reserveSpin;
    QSpinBox *nowSpin;
    QSpinBox *allSpin;
    QDoubleSpinBox *feeSpin;
};

#endif // PARKDIALOG_H


