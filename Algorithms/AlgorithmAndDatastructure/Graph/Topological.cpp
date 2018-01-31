//
// Created by windyear_office on 18-1-31.
//

#include <iostream>
#include "Topological.h"
#include "DirectedCycle.h"
#include "DepthFirstOrder.h"

Topological::Topological(Digraph g) {
    //首先判断是否有环
    DirectedCycle directed_cycle(g);
    if(!directed_cycle.HasCycle()){
        DepthFirstOrder depth_first_order(g);
        order = depth_first_order.ReversePostPath();
    }else{
        cout << "输入的图有环！" << endl;
    }
}

bool Topological::IsDAG() {
    return order.empty();
}

stack<int> Topological::Order() {
    return order;
}
