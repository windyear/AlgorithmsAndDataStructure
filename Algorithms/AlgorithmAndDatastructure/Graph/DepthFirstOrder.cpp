//
// Created by windyear_office on 18-1-31.
//

#include "DepthFirstOrder.h"

DepthFirstOrder::DepthFirstOrder(Digraph g) {
    marked = new bool[g.V()];
    //必须进行下面这个初始化，不然会出现不确定的情况。因为还没有赋值就使用了。
    for(int v = 0; v < g.V(); v++){
        marked[v] = false;
    }
    //遍历所有顶点。深度优先。
    for(int v = 0; v < g.V(); v++){
        if(!marked[v]){
            DFS(g, v);
        }
    }
}

DepthFirstOrder::~DepthFirstOrder() {
    delete[] marked;
}

void DepthFirstOrder::DFS(Digraph g, int v) {
    pre_path.push(v);
    marked[v] = true;
    for(auto s: g.Adj(v)){
        if(!marked[s]){
            DFS(g, s);
        }
    }
    post_path.push(v);
    reverse_post_path.push(v);
}

queue<int> DepthFirstOrder::PostPath() {
    return post_path;
}

queue<int> DepthFirstOrder::PrePath() {
    return pre_path;
}

stack<int> DepthFirstOrder::ReversePostPath() {
    return reverse_post_path;
}