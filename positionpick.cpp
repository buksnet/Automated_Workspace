#include "positionpick.h"
#include "ui_positionpick.h"

PositionPick::PositionPick(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PositionPick)
{
    ui->setupUi(this);
    addPositions();

    connect(ui->resetButton,
            &QPushButton::clicked,
            this,
            [=](){ui->quantity->setValue(1);});
    connect(ui->closeButton,
            &QPushButton::clicked,
            this,
            [=](){this->close();});
}

PositionPick::~PositionPick()
{
    delete ui;
}

void PositionPick::setCategory(int cat){
    switch (cat){
    case 0: category = "soups"; break;
    case 1: category = "seconds"; break;
    case 2: category = "traditional"; break;
    case 3: category = "topDishes"; break;
    case 4: category = "custom"; break;
    case 5: category = "sweets"; break;
    default: break;
    }


}
