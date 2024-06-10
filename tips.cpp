#include "tips.h"
#include "ui_tips.h"

Tips::Tips(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tips)
{
    ui->setupUi(this);
}

Tips::~Tips()
{
    delete ui;
}
