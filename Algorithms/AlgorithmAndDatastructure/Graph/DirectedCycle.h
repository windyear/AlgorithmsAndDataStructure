//
// Created by windyear_office on 18-1-31.
//

#ifndef SORTALGORITHM_DIRECTEDCYCLE_H
#define SORTALGORITHM_DIRECTEDCYCLE_H

#include <vector>
#include "Digraph.h"

using namespace std;
class DirectedCycle {
private:
    bool* marked;
    int* edge_to;//记录路线
    bool* on_stack;//用来保存是否在栈上，不同于无向图，不用确认是否在同一次递归中。
    vector<int> path;
public:
    DirectedCycle(Digraph g);
    ~DirectedCycle();
    void DFS(Digraph g, int start_point);
    bool HasCycle();
    vector<int> CyclePath();

};


#endif //SORTALGORITHM_DIRECTEDCYCLE_H
