//
// Created by windyear_office on 18-5-23.
//

#ifndef HEADFIRSTDESIGNPATTERNS_MALLARD_DUCK_H
#define HEADFIRSTDESIGNPATTERNS_MALLARD_DUCK_H

#include "Duck.h"
#include "quack.h"
#include "fly_with_wings.h"
#include "fly_no_way.h"

class MallardDuck: public Duck{
public:
    MallardDuck(){
        quack_behavior = new Quack();
        // 这里用于测试不同的飞行类型
        // fly_behavior = new FlyWithWings();
        fly_behavior = new FlyNoWay();
    }

    void Display(){
        std::cout << "I am a real Mallard duck!" << std::endl;
    }

    ~MallardDuck(){
        delete quack_behavior;
        delete fly_behavior;
    }
};
#endif //HEADFIRSTDESIGNPATTERNS_MALLARD_DUCK_H
