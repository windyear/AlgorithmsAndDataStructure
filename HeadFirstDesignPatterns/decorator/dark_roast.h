//
// Created by windyear_office on 18-5-7.
//

#ifndef HEADFIRSTDESIGNPATTERNS_DARK_ROAST_H
#define HEADFIRSTDESIGNPATTERNS_DARK_ROAST_H

#include "beverage.h"

class DarkRoast: public Beverage{
public:
    DarkRoast(){
        description = "Dark Roast";
    }

    double Cost() override{
        return 0.99;
    }
};
#endif //HEADFIRSTDESIGNPATTERNS_DARK_ROAST_H
