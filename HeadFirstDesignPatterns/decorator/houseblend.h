//
// Created by windyear_office on 18-5-7.
//

#ifndef HEADFIRSTDESIGNPATTERNS_HOUSEBLEND_H
#define HEADFIRSTDESIGNPATTERNS_HOUSEBLEND_H

#include "beverage.h"

class HouseBlend: public Beverage{
public:
    HouseBlend(){
        description = "House Blend Coffee";
    }

    double Cost() override {
        return 0.99;
    }
};
#endif //HEADFIRSTDESIGNPATTERNS_HOUSEBLEND_H
