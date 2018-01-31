//
// Created by windyear_office on 18-1-31.
//

#include "DirectedCycle.h"

DirectedCycle::DirectedCycle(Digraph g) {
    //初始化几个数组
    marked = new bool[g.V()];
    edge_to = new int[g.V()];
    on_stack = new bool[g.V()];
    for(int i = 0; i < g.V(); i++){
        marked[i] = false;
        edge_to[i] = i;
        on_stack[i] = false;
    }
    for(int v = 0; v < g.V(); v++){
        if(!marked[v]){
            DFS(g, v);
        }
    }
}

DirectedCycle::~DirectedCycle() {
    delete[] marked;
    delete[] edge_to;
    delete[] on_stack;
}

bool DirectedCycle::HasCycle() {
    return path.empty();
}

vector<int> DirectedCycle::CyclePath() {
    return path;
}

void DirectedCycle::DFS(Digraph g, int start_point) {
    //访问到的点入栈
    on_stack[start_point] = true;
    marked[start_point] = true;
    //递归访问相邻点，判断是否有环
    for(auto v: g.Adj(start_point)){
        if(HasCycle()){
            return;
        }else if(!marked[start_point]){
            edge_to[v] = start_point;
            DFS(g, v);
        }else if(on_stack[v]){
            //将路径存起来,从start_point开始返回
            for(int w = start_point;  w != v; w = edge_to[w]){
                path.push_back(w);
            }
            //补上路径。
            path.push_back(v);
            path.push_back(start_point);
        }
    }
    on_stack[start_point] = false;
    return;
}