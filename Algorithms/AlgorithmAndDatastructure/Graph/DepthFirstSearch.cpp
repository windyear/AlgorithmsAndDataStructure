//
// Created by windyear_office on 18-1-27.
//

#include "DepthFirstSearch.h"
DepthFirstSearch::DepthFirstSearch(Graph g, int s) {
    //创建标记数组
    marked = new bool[g.V()];
    count = 0;
    DFS(g, s);
}

DepthFirstSearch::~DepthFirstSearch() {
    delete[] marked;//删除动态创建的数组
}

int DepthFirstSearch::Count() {
    return count;
}

bool DepthFirstSearch::Marked(int v) {
    return marked[v];
}

void DepthFirstSearch::DFS(Graph g, int s) {
    //首先标记访问的节点为已经访问，然后遍历其相邻节点
    //如果邻节点还没有被访问，　就递归访问其邻节点
    marked[s] = true;
    count++;
    for(auto V: g.Adj(s)){
        if(!Marked(V)){
            DFS(g,V);
        }
    }
}