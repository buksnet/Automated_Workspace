#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "init.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void PaymentMethodSwap();
    void PaymentTimeSwap();
    void updateTotal();
    void PushToTable(QString name, double quantity, double price);
private:
    Ui::MainWindow *ui;

public slots:
    void addToTransaction(QString name, double quantity, double price);
    void tipsUpdate();
};

#endif // MAINWINDOW_H
