//
// Created by windyear_office on 18-5-7.
//

#ifndef HEADFIRSTDESIGNPATTERNS_BEVERAGE_H
#define HEADFIRSTDESIGNPATTERNS_BEVERAGE_H

#include <string>

class Beverage{
public:
    std::string description;
    explicit Beverage(std::string s1 = "Unknown Beverage"){

    }
    // 不加virtual实现不了多态
    virtual std::string GetDescription(){
        return description;
    }
    virtual double Cost() = 0;
};
#endif //HEADFIRSTDESIGNPATTERNS_BEVERAGE_H
