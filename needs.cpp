#include "needs.h"
#include "ui_needs.h"

Needs::Needs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Needs)
{
    ui->setupUi(this);
}

Needs::~Needs()
{
    delete ui;
}
