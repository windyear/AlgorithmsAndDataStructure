//
// Created by windyear_office on 18-4-5.
//

#ifndef HEADFIRSTDESIGNPATTERNS_DUCK_H
#define HEADFIRSTDESIGNPATTERNS_DUCK_H

#include <iostream>
#include "fly_behavior.h"
#include "quack_behavior.h"

class Duck{
public:
    // 指向行为类型的指针，用于实现多态。
    FlyBehavior* fly_behavior;
    QuackBehavior* quack_behavior;
    // 鸭子的行为
    void PerformQuack(){
        quack_behavior->Quack_();
    }
    void PerformFly(){
        fly_behavior->Fly();
    }
    void Swim(){
        std::cout << "I can swim! All ducks float, even decoys." << std::endl;
    }
    void Display(){
        std::cout << "I can display!" << std::endl;
    }
    void SetFlyBehavior(FlyBehavior* fb) {
        delete fly_behavior;
        fly_behavior = fb;
    }

    void SetQuackBehavior(QuackBehavior* qb){
        delete quack_behavior;
        quack_behavior = qb;
    }
    virtual ~Duck(){

    }
};
#endif //HEADFIRSTDESIGNPATTERNS_DUCK_H
