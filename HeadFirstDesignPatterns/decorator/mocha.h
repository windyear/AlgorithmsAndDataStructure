//
// Created by windyear_office on 18-5-7.
//

#ifndef HEADFIRSTDESIGNPATTERNS_MOCHA_H
#define HEADFIRSTDESIGNPATTERNS_MOCHA_H

#include "condiment_decorator.h"

class Mocha: public CondimentDecorator{
public:
    Beverage* beverage;
    explicit Mocha(Beverage* b1): beverage(b1){

    }
    std::string GetDescription(){
        return beverage->GetDescription() + ", Mocha";
    }
    double Cost() override {
        return 0.20 + beverage->Cost();
    }
};
#endif //HEADFIRSTDESIGNPATTERNS_MOCHA_H
