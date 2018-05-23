//
// Created by windyear_office on 18-4-5.
//

#ifndef HEADFIRSTDESIGNPATTERNS_FLYBEHAVIOR_H
#define HEADFIRSTDESIGNPATTERNS_FLYBEHAVIOR_H

//一个算法抽象类，把会变化的部分分离出来
class FlyBehavior {
public:
    virtual void Fly() = 0;
};


#endif //HEADFIRSTDESIGNPATTERNS_FLYBEHAVIOR_H
