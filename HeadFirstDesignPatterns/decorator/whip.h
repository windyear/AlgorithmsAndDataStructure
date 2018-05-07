//
// Created by windyear_office on 18-5-7.
//

#ifndef HEADFIRSTDESIGNPATTERNS_WHIP_H
#define HEADFIRSTDESIGNPATTERNS_WHIP_H

#include "condiment_decorator.h"

class Whip: public CondimentDecorator{
public:
    Beverage* beverage;
    explicit Whip(Beverage* b1): beverage(b1){

    }

    std::string GetDescription() override {
        return beverage->GetDescription() + ", whip";
    }

    double Cost() override {
        return 0.10 + beverage->Cost();
    }
};
#endif //HEADFIRSTDESIGNPATTERNS_WHIP_H
