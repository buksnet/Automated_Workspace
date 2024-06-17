#ifndef POSITIONPICK_H
#define POSITIONPICK_H

#include <QWidget>
#include <fstream>
#include "init.h"


namespace Ui {
class PositionPick;
}

class PositionPick : public QWidget
{
    Q_OBJECT
public:
    explicit PositionPick(QWidget *parent = nullptr);
    ~PositionPick();
    void setCategory(int);
    void addPositions();
private:
    Ui::PositionPick *ui;
    std::string category;
signals:
    void addToTransaction(QString name, double quantity, double price);

};


#endif // POSITIONPICK_H
