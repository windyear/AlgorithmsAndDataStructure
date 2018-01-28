//
// Created by windyear_office on 18-1-27.
//

#ifndef SORTALGORITHM_DEPTHFIRSTPATHS_H
#define SORTALGORITHM_DEPTHFIRSTPATHS_H

#include "Graph.h"

//记录深度优先搜索过程中的路径，记录一棵父链接的路径
//像quick_union算法一样
class DepthFirstPaths {
private:
    int* edge_to;//记录起点到一个顶点的路径的最后的一个节点
    bool* marked;//记录节点是否已经被访问
    int start_point;//起点
public:
    DepthFirstPaths(Graph g, int s);
    ~DepthFirstPaths();
    void DFS(Graph g, int v);
    bool HasPathTo(int v);
    list<int> PathTo(int v);
};


#endif //SORTALGORITHM_DEPTHFIRSTPATHS_H
