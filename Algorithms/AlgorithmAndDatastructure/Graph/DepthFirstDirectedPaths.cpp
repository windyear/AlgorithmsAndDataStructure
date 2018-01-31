//
// Created by windyear_office on 18-1-31.
//

#include "DepthFirstDirectedPaths.h"

DepthFirstDirectedPaths::DepthFirstDirectedPaths(Digraph g, int s) {
    marked = new bool[g.V()];
    edge_to = new int[g.V()];
    //因为后面用到了marked的内容，如果还没有初始化，使用里面的值，会有未知情况发生，如果是只有被赋值的操作就没有问题。
    for(int i = 0; i < g.V(); i++){
        marked[i] = false;
    }
    start_point = s;
    DFS(g, s);
}

DepthFirstDirectedPaths::~DepthFirstDirectedPaths() {
    delete[] marked;
    delete[] edge_to;
}

void DepthFirstDirectedPaths::DFS(Digraph g, int v) {
    marked[v] = true;
    for(int s: g.Adj(v)){
        if(!marked[s]){
            edge_to[s] = v;
            DFS(g, s);
        }
    }
}

bool DepthFirstDirectedPaths::HasPathTo(int v) {
    return marked[v];
}

list<int> DepthFirstDirectedPaths::PathTo(int v) {
    if (!HasPathTo(v)) {
        //返回一个空的列表
        list<int> no_path;
        return no_path;
    }
    list<int> path;
    //头插法
    for (int x = v; x != start_point; x = edge_to[x]) {
        path.push_front(x);
    }
    //最后加上起点
    path.push_front(start_point);
    return path;
}