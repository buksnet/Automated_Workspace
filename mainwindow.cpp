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

    int wdt[4] {30, 135, 40, 80};
    auto table = ui->tableWidget;
    for (int i =0; i<4; i++){
        table->setColumnWidth(i, wdt[i]);
    }

    connect(ui->soupButton,
            &QPushButton::clicked,
            this,
            [=](){PositionPick *w = new PositionPick; w->setWindowTitle(w->windowTitle()+" - Супы"); w->setCategory(0); w->show();QObject::connect(w, &PositionPick::addToTransaction, this, &MainWindow::addToTransaction);});
    connect(ui->secondButton,
            &QPushButton::clicked,
            this,
            [=](){PositionPick *w = new PositionPick; w->setWindowTitle(w->windowTitle()+" - Вторые блюда"); w->setCategory(1); w->show(); QObject::connect(w, &PositionPick::addToTransaction, this, &MainWindow::addToTransaction);});
    connect(ui->traditionalButton,
            &QPushButton::clicked,
            this,
            [=](){PositionPick *w = new PositionPick; w->setWindowTitle(w->windowTitle()+" - Традиционные блюда"); w->setCategory(2); w->show(); QObject::connect(w, &PositionPick::addToTransaction, this, &MainWindow::addToTransaction);});
    connect(ui->topDishesButton,
            &QPushButton::clicked,
            this,
            [=](){PositionPick *w = new PositionPick; w->setWindowTitle(w->windowTitle()+" - Блюда месяца"); w->setCategory(3); w->show();QObject::connect(w, &PositionPick::addToTransaction, this, &MainWindow::addToTransaction);});
    connect(ui->customButton,
            &QPushButton::clicked,
            this,
            [=](){PositionPick *w = new PositionPick; w->setWindowTitle(w->windowTitle()+" - Свой рецепт"); w->setCategory(4); w->show();QObject::connect(w, &PositionPick::addToTransaction, this, &MainWindow::addToTransaction);});
    connect(ui->sweetButton,
            &QPushButton::clicked,
            this,
            [=](){PositionPick *w = new PositionPick; w->setWindowTitle(w->windowTitle()+" - Десерты"); w->setCategory(5); w->show();QObject::connect(w, &PositionPick::addToTransaction, this, &MainWindow::addToTransaction);});



    connect(ui->tipsButton,
            &QPushButton::clicked,
            this,
            [=](){Tips *tip = new Tips; tip->show(); QObject::connect(tip, &Tips::tipsUpdate, this, &MainWindow::tipsUpdate);});
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

void MainWindow::PushToTable(QString name, double quantity, double price){
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(QString::number(ui->tableWidget->rowCount())));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(name, 0));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(QString::number(quantity)));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem(QString::number(price, 'f', 2)));
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
void MainWindow::addToTransaction(QString name, double quantity, double price){
    PushToTable(qPrintable(name), quantity, price);
    currTransaction.addPosition(price, quantity);
    updateTotal();
}

void MainWindow::tipsUpdate(){
    std::cout << "Trigger";
    updateTotal();
}
