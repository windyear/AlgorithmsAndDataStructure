//
// Created by windyear_office on 18-1-27.
//

#include "DepthFirstPaths.h"

DepthFirstPaths::DepthFirstPaths(Graph g, int s) {
    marked = new bool[g.V()];
    edge_to = new int[g.V()];
    start_point = s;
    DFS(g, s);
}

DepthFirstPaths::~DepthFirstPaths() {
    delete[] marked;
    delete[] edge_to;
}

void DepthFirstPaths::DFS(Graph g, int v) {
    marked[v] = true;
    for(int s: g.Adj(v)){
        if(!marked[s]){
            edge_to[s] = v;
            DFS(g, s);
        }
    }
}

bool DepthFirstPaths::HasPathTo(int v) {
    return marked[v];
}

list<int> DepthFirstPaths::PathTo(int v) {
    if(!HasPathTo(v)){
        //返回一个空的列表
        list<int> no_path;
        return no_path;
    }
    list<int> path;
    //头插法
    for(int x = v; x != start_point; x = edge_to[x]){
        path.push_front(x);
    }
    //最后加上起点
    path.push_front(start_point);
    return path;
}