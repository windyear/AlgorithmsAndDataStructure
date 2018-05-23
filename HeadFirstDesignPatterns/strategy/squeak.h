//
// Created by windyear_office on 18-4-5.
//

#ifndef HEADFIRSTDESIGNPATTERNS_SQUEAK_H
#define HEADFIRSTDESIGNPATTERNS_SQUEAK_H

#include <iostream>
#include "quack_behavior.h"

class Squeak: public QuackBehavior{
public:
    void Quack_(){
        std::cout << "Squeak...Squeak...Squeak..." << std::endl;
    }
};
#endif //HEADFIRSTDESIGNPATTERNS_SQUEAK_H
