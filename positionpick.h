#ifndef POSITIONPICK_H
#define POSITIONPICK_H

#include <QWidget>

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
};

#endif // POSITIONPICK_H
