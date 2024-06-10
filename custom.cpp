#include "custom.h"
#include "ui_custom.h"

Custom::Custom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Custom)
{
    ui->setupUi(this);
    connect(ui->send,
            &QPushButton::clicked,
            this,
            [=](){std::cout << "На кухню был отправлен запрос на текущий рецепт: \"\"\"\n" << ui->textEdit->toPlainText().data()
                            <<"\n\"\"\"\nОжидание подтверждения..."<< std::endl;});
    connect(ui->clear,
            &QPushButton::clicked,
            this,
            [=](){ui->textEdit->clear();});
}

Custom::~Custom()
{
    delete ui;
}
