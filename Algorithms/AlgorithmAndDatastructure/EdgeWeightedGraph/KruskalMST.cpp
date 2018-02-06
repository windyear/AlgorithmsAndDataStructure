//
// Created by windyear_office on 18-2-6.
//

#include <queue>
#include "KruskalMST.h"
#include "../Union/UnionFind.h"

KruskalMST::KruskalMST(EdgeWeightedGraph g) {
    //初始化一个优先队列，一个union对象。
    priority_queue<Edge> pq;
    UnionFind uf(g.V());
    //mst.resize(g.V());
    for(auto e: g.Edges()){
        pq.push(e);
    }
    while(!pq.empty() && mst.size() < g.V() - 1){
        //获取一条最短的边
        Edge e = pq.top();
        pq.pop();
        int v = e.Either();
        int w = e.Other(v);
        //判断这条边是否有效，如果两个点能够连在一起，说明无效。
        if(uf.IsConnected(v, w)){
            continue;
        }
        uf.Union(w, v);
        mst.push_back(e);
    }
}

vector<Edge> KruskalMST::Edges() {
    return mst;
}
double KruskalMST::Weight() {
    double weight = 0;
    for(auto e: mst){
        weight += e.Weight();
    }
}