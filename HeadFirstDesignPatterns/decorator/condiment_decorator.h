//
// Created by windyear_office on 18-5-7.
//

#ifndef HEADFIRSTDESIGNPATTERNS_CONDIMENT_DECORATOR_H
#define HEADFIRSTDESIGNPATTERNS_CONDIMENT_DECORATOR_H

#include "beverage.h"

class CondimentDecorator: public Beverage{
public:
    std::string GetDescription(){};
};
#endif //HEADFIRSTDESIGNPATTERNS_CONDIMENT_DECORATOR_H
