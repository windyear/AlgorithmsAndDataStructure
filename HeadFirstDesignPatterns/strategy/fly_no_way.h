//
// Created by windyear_office on 18-4-5.
//

#ifndef HEADFIRSTDESIGNPATTERNS_FLY_NO_WAY_H
#define HEADFIRSTDESIGNPATTERNS_FLY_NO_WAY_H

#include <iostream>
#include "fly_behavior.h"

class FlyNoWay: public FlyBehavior{
public:
    void Fly(){
        std::cout << "I can't fly! I am very foolish!" << std::endl;
    }
};

#endif //HEADFIRSTDESIGNPATTERNS_FLY_NO_WAY_H
