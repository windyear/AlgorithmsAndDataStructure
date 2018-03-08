//
// Created by windyear_office on 18-3-8.
//

#ifndef SORTALGORITHM_EDGEWEIGHTEDDFSORDER_H
#define SORTALGORITHM_EDGEWEIGHTEDDFSORDER_H

#include <vector>
#include <stack>
#include <queue>
#include "EdgeWeightDiGraph.h"

using namespace std;
//深度前序，后序，逆后序遍历
class EdgeWeightedDFSOrder {
private:
    int count;
    vector<bool> marked;
    queue<int> pre_order;
    queue<int> post_order;
    stack<int> reverse_order;
public:
    EdgeWeightedDFSOrder(const EdgeWeightDiGraph& g);
    void DFS(const EdgeWeightDiGraph& g, int point);
    //下面的函数返回遍历的顺序的容器
    queue<int> PrePath() const;
    queue<int> PostPath() const;
    stack<int> ReversePath() const;
};


#endif //SORTALGORITHM_EDGEWEIGHTEDDFSORDER_H
