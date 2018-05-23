//
// Created by windyear_office on 18-4-5.
//

#ifndef HEADFIRSTDESIGNPATTERNS_FLY_WITH_WINGS_H
#define HEADFIRSTDESIGNPATTERNS_FLY_WITH_WINGS_H

#include <iostream>
#include "fly_behavior.h"

class FlyWithWings: public FlyBehavior{
public:
    void Fly(){
        std::cout << "I can fly with wings! I am very happy!" << std::endl;
    }
};
#endif //HEADFIRSTDESIGNPATTERNS_FLY_WITH_WINGS_H
