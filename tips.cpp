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
            [=](){currTransaction.setTip(5);});
    connect(ui->tip10per,
            &QPushButton::clicked,
            this,
            [=](){currTransaction.setTip(10);});
    connect(ui->tip15per,
            &QPushButton::clicked,
            this,
            [=](){currTransaction.setTip(15);});
    connect(ui->tip20per,
            &QPushButton::clicked,
            this,
            [=](){currTransaction.setTip(20);});
    connect(ui->tip25per,
            &QPushButton::clicked,
            this,
            [=](){currTransaction.setTip(25);});
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
    if (isperc){
        double value = ui->lineEdit->text().toDouble();
        currTransaction.setTip(value);
    }
    else {
        int value = ui->lineEdit->text().toInt();
        currTransaction.setTip(value);
    }
}
