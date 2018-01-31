//
// Created by windyear_office on 18-1-31.
//

#ifndef SORTALGORITHM_DEPTHFIRSTDIRECTEDPATHS_H
#define SORTALGORITHM_DEPTHFIRSTDIRECTEDPATHS_H


#include "Digraph.h"

class DepthFirstDirectedPaths {
private:
    int* edge_to;//记录起点到一个顶点的路径的最后的一个节点
    bool* marked;//记录节点是否已经被访问
    int start_point;//起点
public:
    DepthFirstDirectedPaths(Digraph g, int s);
    ~DepthFirstDirectedPaths();
    void DFS(Digraph g, int v);
    bool HasPathTo(int v);
    list<int> PathTo(int v);

};


#endif //SORTALGORITHM_DEPTHFIRSTDIRECTEDPATHS_H
