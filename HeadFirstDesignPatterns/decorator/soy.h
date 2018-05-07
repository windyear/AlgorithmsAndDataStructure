//
// Created by windyear_office on 18-5-7.
//

#ifndef HEADFIRSTDESIGNPATTERNS_SOY_H
#define HEADFIRSTDESIGNPATTERNS_SOY_H

#include "condiment_decorator.h"

class Soy: public CondimentDecorator{
public:
    Beverage* beverage;
    explicit Soy(Beverage* b1): beverage(b1){

    }

    std::string GetDescription() override {
        return beverage->GetDescription() + ", soy";
    }

    double Cost() override {
        return 0.15 + beverage->Cost();
    }
};
#endif //HEADFIRSTDESIGNPATTERNS_SOY_H
