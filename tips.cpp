#include "tips.h"
#include "ui_tips.h"

Tips::Tips(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tips)
{
    ui->setupUi(this);
    connect(ui->tip5per,
            &QPushButton::clicked,
            this,
            [=](){currTransaction.setTip(5);emit tipsUpdate();});
    connect(ui->tip10per,
            &QPushButton::clicked,
            this,
            [=](){currTransaction.setTip(10);emit tipsUpdate();});
    connect(ui->tip15per,
            &QPushButton::clicked,
            this,
            [=](){currTransaction.setTip(15);emit tipsUpdate();});
    connect(ui->tip20per,
            &QPushButton::clicked,
            this,
            [=](){currTransaction.setTip(20);emit tipsUpdate();});
    connect(ui->tip25per,
            &QPushButton::clicked,
            this,
            [=](){currTransaction.setTip(25);emit tipsUpdate();});
    connect(ui->tipthisper,
            &QPushButton::clicked,
            this,
            [=](){addTips(true);});
    connect(ui->tipthissum,
            &QPushButton::clicked,
            this,
            [=](){addTips(false);});
}

Tips::~Tips()
{
    delete ui;
}

void Tips::addTips(bool isperc){
    if (!isperc){
        double value = ui->lineEdit->text().toDouble();
        currTransaction.setAddition(value);
    }
    else {
        int value = ui->lineEdit->text().toInt();
        currTransaction.setTip(value);
    }
    emit tipsUpdate();
}
