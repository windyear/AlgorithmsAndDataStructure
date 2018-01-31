//
// Created by windyear_office on 18-1-31.
//

#ifndef SORTALGORITHM_TOPOLOGICAL_H
#define SORTALGORITHM_TOPOLOGICAL_H

#include <stack>
#include "Digraph.h"

using namespace std;

class Topological {
private:
    stack<int> order;//存储一个拓扑排序
public:
    Topological(Digraph g);
    bool IsDAG();
    stack<int> Order();
};


#endif //SORTALGORITHM_TOPOLOGICAL_H
