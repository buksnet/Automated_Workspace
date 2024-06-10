#ifndef TIPS_H
#define TIPS_H

#include <QWidget>
#include "init.h"

namespace Ui {
class Tips;
}

class Tips : public QWidget
{
    Q_OBJECT

public:
    explicit Tips(QWidget *parent = nullptr);
    ~Tips();
    void addTips(bool);

private:
    Ui::Tips *ui;
};

#endif // TIPS_H
