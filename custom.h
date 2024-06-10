#ifndef CUSTOM_H
#define CUSTOM_H

#include <iostream>
#include <QWidget>

namespace Ui {
class Custom;
}

class Custom : public QWidget
{
    Q_OBJECT

public:
    explicit Custom(QWidget *parent = nullptr);
    ~Custom();

private:
    Ui::Custom *ui;
};

#endif // CUSTOM_H
