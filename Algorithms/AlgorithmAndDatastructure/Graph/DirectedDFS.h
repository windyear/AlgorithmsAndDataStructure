//
// Created by windyear_office on 18-1-30.
//

#ifndef SORTALGORITHM_DIRECTEDDFS_H
#define SORTALGORITHM_DIRECTEDDFS_H


#include "Digraph.h"

class DirectedDFS {
private:
    int count; //记录访问到的节点数目
    bool* marked;//标记节点是否被访问
public:
    DirectedDFS(Digraph g, int s);//构造函数，传入图结构和开始访问的节点
    DirectedDFS(Digraph g, vector<int> source); //找出集合source中的点可以遍历到的点
    ~DirectedDFS();
    void DFS(Digraph g, int s);//深度优先遍历的主程序
    int Count();
    bool Marked(int v);
};


#endif //SORTALGORITHM_DIRECTEDDFS_H
