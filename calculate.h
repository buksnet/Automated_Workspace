#ifndef CALCULATE_H
#define CALCULATE_H
#include <iostream>

class Calculate
{
private:
    double sum;
    int tipPercent;
    double tipValue;
    std::string note;
public:
    Calculate();
    void setTip(int perc){tipPercent = perc;}
    void setTip(double perc){tipValue = perc;}
    void addPosition(double, double);
    void removePosition(double, double);
    void addNote(char* data){note = data;}
    std::string getNote(){return note.c_str();}
    double getSum();
    void clear();
};

#endif // CALCULATE_H
