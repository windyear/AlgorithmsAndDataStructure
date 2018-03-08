//
// Created by windyear_office on 18-3-8.
//

#include <iostream>
#include "edgeweighteddfsorder.h"

//使用初始化列表进行初始化
EdgeWeightedDFSOrder::EdgeWeightedDFSOrder(const EdgeWeightDiGraph &g) :
    count(0), marked(g.V(), false), pre_order(), post_order(), reverse_order()
{
    for(int i = 0; i < g.V(); i++){
        if(marked[i] == false){
            DFS(g, i);
        }
    }
}

void EdgeWeightedDFSOrder::DFS(const EdgeWeightDiGraph &g, int point) {
    //不同的顺序就是记录被访问点的时间不同
    marked[point] = true;
    pre_order.push(point);
    //cout << point << " ";
    for(DirectedEdge edge: g.Adj(point)){
        int to = edge.To();
        if(marked[to] == false){
            DFS(g, to);
        }
    }
    post_order.push(point);
    reverse_order.push(point);
}

queue<int> EdgeWeightedDFSOrder::PrePath() const {
    return pre_order;
}

queue<int> EdgeWeightedDFSOrder::PostPath() const {
    return post_order;
}

stack<int> EdgeWeightedDFSOrder::ReversePath() const {
    return reverse_order;
}
