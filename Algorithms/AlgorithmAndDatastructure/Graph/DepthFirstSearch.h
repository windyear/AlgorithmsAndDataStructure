//
// Created by windyear_office on 18-1-27.
//

#ifndef SORTALGORITHM_DEPTHFIRSTSEARCH_H
#define SORTALGORITHM_DEPTHFIRSTSEARCH_H

#include "Graph.h"

//深度优先搜索：访问一个顶点时首先标记其已经被访问，然后递归地访问它的没有被标记过的节点。
class DepthFirstSearch {
private:
    int count; //记录访问到的节点数目
    bool* marked;//标记节点是否被访问
public:
    DepthFirstSearch(Graph g, int s);//构造函数，传入图结构和开始访问的节点
    ~DepthFirstSearch();
    void DFS(Graph g, int s);//深度优先遍历的主程序
    int Count();
    bool Marked(int v);
};


#endif //SORTALGORITHM_DEPTHFIRSTSEARCH_H
