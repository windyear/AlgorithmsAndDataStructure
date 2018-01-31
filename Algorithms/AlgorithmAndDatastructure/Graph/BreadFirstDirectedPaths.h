//
// Created by windyear_office on 18-1-31.
//

#ifndef SORTALGORITHM_BREADFIRSTDIRECTEDPATHS_H
#define SORTALGORITHM_BREADFIRSTDIRECTEDPATHS_H


#include "Digraph.h"

class BreadFirstDirectedPaths {
private:
    int* edge_to;
    bool* marked;
    int start_point;//起点
public:
    BreadFirstDirectedPaths(Digraph g, int v);
    ~BreadFirstDirectedPaths();
    void BFS(Digraph g, int v);
    list<int> PathTo(int v);
    bool HasPathTo(int v);

};


#endif //SORTALGORITHM_BREADFIRSTDIRECTEDPATHS_H
