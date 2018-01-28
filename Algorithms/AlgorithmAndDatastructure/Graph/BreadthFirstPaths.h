//
// Created by windyear_office on 18-1-28.
//

#ifndef SORTALGORITHM_BREADTHFIRSTPATHS_H
#define SORTALGORITHM_BREADTHFIRSTPATHS_H

#include "Graph.h"

//广度优先搜索，思路是先进先出，利用一个辅助队列，访问一个队列的节点时，将还没有访问的邻接点加入队列。
//直到所有节点都被访问到。从起点开始，每次都访问最近的节点。
//队列中的节点表示已经被访问到了但是其邻接点还没有进行访问判断的节点。
class BreadthFirstPaths {
private:
    int* edge_to;
    bool* marked;
    int start_point;//起点
public:
    BreadthFirstPaths(Graph g, int v);
    ~BreadthFirstPaths();
    void BFS(Graph g, int v);
    list<int> PathTo(int v);
    bool HasPathTo(int v);
};


#endif //SORTALGORITHM_BREADTHFIRSTPATHS_H
