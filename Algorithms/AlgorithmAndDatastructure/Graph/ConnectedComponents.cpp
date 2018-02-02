//
// Created by windyear_office on 18-1-28.
//

#include "ConnectedComponents.h"

ConnectedComponents::ConnectedComponents(Graph g) {
    //初始化数组
    marked = new bool[g.V()];
    id = new int[g.V()];
    count = 0;
    //遍历每个点，如果还没有被访问即标记，就对其使用深度优先搜索。
    for(int v = 0; v < g.V(); v++){
        if(!marked[v]){
            DFS(g, v);
            //一次深度优先搜索产生一个新的连通分量
            count++;
        }
    }
}

ConnectedComponents::~ConnectedComponents() {
    delete[] marked;
    delete[] id;
}

bool ConnectedComponents::Connected(int v, int w) {
    return id[v] == id[w];
}

int ConnectedComponents::Count() {
    return count;
}

int ConnectedComponents::Id(int v) {
    return id[v];
}

void ConnectedComponents::DFS(Graph g, int v) {
    marked[v] = true;
    //标记连通分量
    id[v] = count;
    for(auto V: g.Adj(v)){
        if(!marked[V]){
            DFS(g,V);
        }
    }
}
