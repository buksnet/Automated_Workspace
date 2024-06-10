#include "positionpick.h"
#include "ui_positionpick.h"
#include "CSVRow.h"

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

void PositionPick::addPositions(){
    std::ifstream file(":/foodbase/menu/"+ category + ".csv");
    std::vector<std::vector<std::string>> data = readCSV(file);
    int index = 0;
    std::string btnName;
    std::vector<int> {};
    for(unsigned long long int i = 1; i < data.size(); i++){
        QPushButton *newbutton = new QPushButton;
        newbutton->resize(190, 190);
        newbutton->setText(data[i][0].c_str());
        btnName = ("Button" + std::to_string(index));
        newbutton->setObjectName(btnName.c_str());
        newbutton->setStyleSheet("QPushButton{\
                                 color: white;\
                                 background-color: #000033;\
                                 border: 1px solid black;\
                                 border-radius: 7px;\
                             }\
                             QPushButton:hover{\
                                 background-color: rgb(92, 100, 150);\
                             }\
                             QPushButton:pressed{\
                                 background-color:rgb(0, 0, 30);\
                                 border: 3px inset\
                             }");
        newbutton->setParent(ui->ParentWidget);
        newbutton->move(5 + i*192, 5+abs(index/3)*192);
        connect(ui->ParentWidget->findChild<QPushButton *>(btnName.c_str()),
                &QPushButton::clicked,
                this,
                [=](){currTransaction.addPosition(std::stod(data[i][1]), ui->quantity->text().toDouble()); });
        index++;
}
}
