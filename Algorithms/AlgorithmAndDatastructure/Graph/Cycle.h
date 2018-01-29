//
// Created by windyear_office on 18-1-28.
//

#ifndef SORTALGORITHM_CYCLE_H
#define SORTALGORITHM_CYCLE_H

#include "Graph.h"

//查看图中是否存在环：思路很简单，只需要做深度优先遍历，每次遍历邻点的时候查看是否被遍历过。
class Cycle {
private:
    bool* marked;
    bool has_cycle;
public:
    Cycle(Graph g);
    ~Cycle();
    void DFS(Graph g, int v, int neighbor_point);
    bool HasCycle();
};


#endif //SORTALGORITHM_CYCLE_H
