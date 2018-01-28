//
// Created by windyear_office on 18-1-28.
//

#ifndef SORTALGORITHM_CONNECTEDCOMPONENTS_H
#define SORTALGORITHM_CONNECTEDCOMPONENTS_H

#include "Graph.h"

//查找连通分量，利用深度优先搜索，先从一个起点开始搜索，然后检查哪些节点还没有被查到，继续使用深度搜索。
//用一个id数组以节点作为索引标记节点属于第几个连通分量。
class ConnectedComponents {
private:
    bool* marked;
    int* id;//标记连通分量
    int count;//标记是第几个连通分量
public:
    ConnectedComponents(Graph g);
    ~ConnectedComponents();
    void DFS(Graph g, int v);
    int Id(int v);
    int Count();
    //判断两个节点是否在同一个分量，即是否连接在一起
    bool Connected(int v, int w);
};


#endif //SORTALGORITHM_CONNECTEDCOMPONENTS_H
