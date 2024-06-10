#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tips.h"
#include "needs.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int wdt[4] {25, 135, 65, 50};
    auto table = ui->tableWidget;
    for (int i =0; i<4; i++){
        table->setColumnWidth(i, wdt[i]);
    }

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

