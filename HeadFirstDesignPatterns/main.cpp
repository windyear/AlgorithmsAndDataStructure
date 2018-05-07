#include <iostream>
#include "decorator/beverage.h"
#include "decorator/espresso.h"
#include "decorator/dark_roast.h"
#include "decorator/mocha.h"
#include "decorator/soy.h"

int main() {
    std::cout << "Test decorator!" << std::endl;
    //先订一杯基础饮料，不带调料
    Beverage* espresso = new Espresso();
    std::cout << espresso->GetDescription() << " $" << espresso->Cost() << std::endl;
    delete espresso;

    // 订一杯有加调料的饮料
    // 深焙咖啡
    Beverage* dark_roast = new DarkRoast();
    std::cout << dark_roast->GetDescription() << " $" << dark_roast->Cost() << std::endl;
    // 加摩卡的深焙咖啡
    Beverage* mocha_dark_roast = new Mocha(dark_roast);
    std::cout << mocha_dark_roast->GetDescription() << " $" << mocha_dark_roast->Cost() << std::endl;
    // 再加豆浆
    Beverage* soy_mocha_dark_roast = new Soy(mocha_dark_roast);
    std::cout << soy_mocha_dark_roast->GetDescription() << " $" << soy_mocha_dark_roast->Cost() << std::endl;
    delete soy_mocha_dark_roast;
    delete mocha_dark_roast;
    delete dark_roast;

    return 0;
}