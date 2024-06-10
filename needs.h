#ifndef NEEDS_H
#define NEEDS_H

#include <QWidget>

namespace Ui {
class Needs;
}

class Needs : public QWidget
{
    Q_OBJECT

public:
    explicit Needs(QWidget *parent = nullptr);
    ~Needs();

private:
    Ui::Needs *ui;
};

#endif // NEEDS_H
