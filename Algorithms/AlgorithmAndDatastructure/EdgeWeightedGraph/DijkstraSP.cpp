//
// Created by windyear_office on 18-2-7.
//

#include "DijkstraSP.h"

DijkstraSP::DijkstraSP(EdgeWeightDiGraph g, int start_point) {
    //初始化所有变量
    distance_to = new double[g.V()];
    marked = new bool[g.V()];
    //因为稍后要更新值，所以先初始化空间。
    edge_to.resize(g.V());
    for(int i = 0; i < g.V(); i++){
        distance_to[i] = MAX_DISTANCE;
    }
    //到达自己时距离为０
    distance_to[start_point] = 0.0;
    marked[start_point] = true;
    //每次放松一个点，一共需要放松v-1次，可以使用一个for循环进行松弛
    for(int i = 0; i < g.V() - 1; i++){
        int shortest_index = ToRelax(start_point, g.V());
        marked[shortest_index] =  true;
        Relax(g, shortest_index);
    }
}

DijkstraSP::~DijkstraSP() {
    delete[] distance_to;
}

double DijkstraSP::DistanceTo(int v) {
    return distance_to[v];
}

int DijkstraSP::ToRelax(int start_point, int num_of_point) {
    int shortest;
    for(int i = 0; i < num_of_point; i++){
        if(marked[i] == true){
            continue;
        }
        if(distance_to[shortest] <= distance_to[i]){
            shortest = i;
        }
    }
    return shortest;
}

void DijkstraSP::Relax(EdgeWeightDiGraph &g, int to_relax) {
    for(auto e: g.Adj(to_relax)){
        int to = e.To();
        if(distance_to[to] > distance_to[to_relax] + e.Weight()){
            distance_to[to] = distance_to[to_relax] + e.Weight();
            edge_to[to] = e;
        }
    }
}

bool DijkstraSP::HasPathTo(int end_point) {
    return distance_to[end_point] < MAX_DISTANCE;
}

list<DirectedEdge> DijkstraSP::PathTo(int point) {
    if(!HasPathTo(point)){
        list<DirectedEdge> no;
        return no;
    }
    list<DirectedEdge> path;
    for(DirectedEdge e = edge_to[point]; e.Weight() != 0; e = edge_to[e.From()]){
        path.push_front(e);
    }
    return path;
}