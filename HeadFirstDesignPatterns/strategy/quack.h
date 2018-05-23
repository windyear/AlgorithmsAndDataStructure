//
// Created by windyear_office on 18-4-5.
//

#ifndef HEADFIRSTDESIGNPATTERNS_QUACK_H
#define HEADFIRSTDESIGNPATTERNS_QUACK_H

#include <iostream>
#include "quack_behavior.h"

class Quack: public QuackBehavior{
public:
    void Quack_(){
        std::cout << "Quack...Quack...Quack..." << std::endl;
    }
};
#endif //HEADFIRSTDESIGNPATTERNS_QUACK_H
