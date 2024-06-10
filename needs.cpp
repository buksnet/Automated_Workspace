#include "needs.h"
#include "ui_needs.h"

Calculate currTransaction;

Needs::Needs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Needs)
{
    ui->setupUi(this);
    connect(ui->commit,
            &QPushButton::clicked,
            this,
            [=](){currTransaction.addNote(ui->textEdit->toPlainText().toLocal8Bit().data());this->close();});
    connect(ui->clear,
            &QPushButton::clicked,
            this,
            [=](){ui->textEdit->clear();});
}

Needs::~Needs()
{
    delete ui;
}
