//
// Created by windyear_office on 18-4-5.
//

#ifndef HEADFIRSTDESIGNPATTERNS_MUTE_QUACK_H
#define HEADFIRSTDESIGNPATTERNS_MUTE_QUACK_H

#include <iostream>
#include "quack_behavior.h"

class MuteQuack: public QuackBehavior{
public:
    void Quack_(){
        std::cout << "Mute...Mute...Mute..." << std::endl;
    }
};
#endif //HEADFIRSTDESIGNPATTERNS_MUTE_QUACK_H
