//
// Created by windyear_office on 18-5-7.
//

#ifndef HEADFIRSTDESIGNPATTERNS_ESPRESSO_H
#define HEADFIRSTDESIGNPATTERNS_ESPRESSO_H

#include "beverage.h"

class Espresso: public Beverage{
public:
    Espresso(){
        description = "Espresso";
    }

    double Cost() override {
        return 1.99;
    }
};
#endif //HEADFIRSTDESIGNPATTERNS_ESPRESSO_H
