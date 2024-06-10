#include "calculate.h"
#include <math.h>
Calculate::Calculate()
{
    sum = 0.f;
    tipPercent = 0;
    tipValue = 0.f;
}

void Calculate::addPosition(double price, double count=1){
    sum += std::ceil((price * count*100))/100;
}

void Calculate::removePosition(double price, double count = 1){
    sum -= std::ceil((price * count*100))/100;
}

double Calculate::getSum(){
    return sum * (1+tipPercent/100) + tipValue;
}

void Calculate::clear(){
    sum = 0;
    tipPercent = 0;
    tipValue = 0;
}
