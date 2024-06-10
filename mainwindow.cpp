#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tips.h"
#include "needs.h"
#include "positionpick.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    updateTotal();

    int wdt[4] {25, 135, 65, 50};
    auto table = ui->tableWidget;
    for (int i =0; i<4; i++){
        table->setColumnWidth(i, wdt[i]);
    }

    connect(ui->soupButton,
            &QPushButton::clicked,
            this,
            [=](){PositionPick *w = new PositionPick; w->setWindowTitle(w->windowTitle()+" - Супы"); w->setCategory(0); w->show();});
    connect(ui->secondButton,
            &QPushButton::clicked,
            this,
            [=](){PositionPick *w = new PositionPick; w->setWindowTitle(w->windowTitle()+" - Вторые блюда"); w->setCategory(1); w->show();});
    connect(ui->traditionalButton,
            &QPushButton::clicked,
            this,
            [=](){PositionPick *w = new PositionPick; w->setWindowTitle(w->windowTitle()+" - Традиционные блюда"); w->setCategory(2); w->show();});
    connect(ui->topDishesButton,
            &QPushButton::clicked,
            this,
            [=](){PositionPick *w = new PositionPick; w->setWindowTitle(w->windowTitle()+" - Блюда месяца"); w->setCategory(3); w->show();});
    connect(ui->customButton,
            &QPushButton::clicked,
            this,
            [=](){PositionPick *w = new PositionPick; w->setWindowTitle(w->windowTitle()+" - Свой рецепт"); w->setCategory(4); w->show();});
    connect(ui->sweetButton,
            &QPushButton::clicked,
            this,
            [=](){PositionPick *w = new PositionPick; w->setWindowTitle(w->windowTitle()+" - Десерты"); w->setCategory(5); w->show();});


    connect(ui->tipsButton,
            &QPushButton::clicked,
            this,
            [=](){Tips *tip = new Tips; tip->show();});
    connect(ui->payOptionMethod,
            &QPushButton::clicked,
            this,
            &MainWindow::PaymentMethodSwap);
    connect(ui->payOptionTime,
            &QPushButton::clicked,
            this,
            &MainWindow::PaymentTimeSwap);
    connect(ui->needsButton,
            &QPushButton::clicked,
            this,
            [=](){Needs *need = new Needs; need->show();});
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTotal(){
    ui->totalValue->setText(QString::number(currTransaction.getSum(), 'f', 2));
}

void MainWindow::PushToTable(int index, std::string name, double quantity, double price){
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(index));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(name.c_str()));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(quantity));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem(price));
}

void MainWindow::PaymentMethodSwap(){
    std::string text1 = "Оплата:\nналичными", text2 = "Оплата:\nкартой";
    if (ui->payOptionMethod->text() == text1.c_str()) ui->payOptionMethod->setText(text2.c_str());
    else ui->payOptionMethod->setText(text1.c_str());
}

void MainWindow::PaymentTimeSwap(){
    std::string text1 = "Оплата:\nсразу", text2 = "Оплата:\nпосле";
    if (ui->payOptionTime->text() == text1.c_str()) ui->payOptionTime->setText(text2.c_str());
    else ui->payOptionTime->setText(text1.c_str());
}
