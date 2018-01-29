//
// Created by windyear_office on 18-1-29.
//

#ifndef SORTALGORITHM_TWOCOLORGRAPH_H
#define SORTALGORITHM_TWOCOLORGRAPH_H

#include "Graph.h"

//二分图问题，也是图的着色问题：思路是遍历的同时进行染色，遇到已经染色的节点，判断其与相邻的节点是否一样的颜色，是的话
//就不是二分图。二分图的特性是没有奇数圈，颜色数目为２。
class TwoColorGraph {
private:
    bool* marked;
    bool* color;//用两种情况标识图节点的颜色
    bool is_two_color;
public:
    TwoColorGraph(Graph g);
    ~TwoColorGraph();
    void DFS(Graph g, int v);
    bool IsTwoColor();
};


#endif //SORTALGORITHM_TWOCOLORGRAPH_H
