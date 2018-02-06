//
// Created by windyear_office on 18-2-3.
//

#include "LazyPrim.h"

LazyPrim::LazyPrim(EdgeWeightedGraph g) {
    //初始化成员
    marked = new bool[g.V()];
    for(int i = 0; i < g.V(); i++){
        marked[i] = false;
    }
    //将第０个点加入最小生成树。
    Visit(g, 0);
    //从优先队列中取出最小值，然后判断边是否有效，有效则加入。
    while(!pq.empty()){
        Edge e = pq.top();
        pq.pop();
        //拿出两个点
        int v = e.Either();
        int w = e.Other(v);
        //判断两条边是否都已经被标记了
        if(marked[v] && marked[w]){
            continue;
        }
        //加入到最小生成树
        mst.push_back(e);
        //看那个点还没有加入就加入
        if(!marked[w]){
            Visit(g, w);
        }
        if(!marked[v]){
            Visit(g, v);
        }
    }
}

LazyPrim::~LazyPrim() {
    delete[] marked;
}

void LazyPrim::Visit(EdgeWeightedGraph g, int v) {
    marked[v] = true;
    for(auto e: g.Adj(v)){
        if(!marked[e.Other(v)]){
            pq.push(e);
        }
    }
}

vector<Edge> LazyPrim::Edges() {
    return mst;
}

double LazyPrim::Weight() {
    //遍历所有边
    double weight = 0;
    for(auto e: mst){
        weight += e.Weight();
    }
}