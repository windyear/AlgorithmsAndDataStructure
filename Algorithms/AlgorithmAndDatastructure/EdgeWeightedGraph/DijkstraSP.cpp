//
// Created by windyear_office on 18-2-7.
//

#include "DijkstraSP.h"

DijkstraSP::DijkstraSP(EdgeWeightDiGraph g, int start_point) {
    //初始化所有变量
    distance_to = new double[g.V()];
    marked = new bool[g.V()];
    for(int i = 0; i < g.V(); i++){
        marked[i] = false;
    }
    //因为稍后要更新值，所以先初始化空间。
    edge_to.resize(g.V());
    //所有值都为最大的距离
    for(int i = 0; i < g.V(); i++){
        distance_to[i] = MAX_DISTANCE;
    }
    //到达自己时距离为０
    distance_to[start_point] = 0.0;
    marked[start_point] = true;
    //每次放松一个点，一共需要放松v-1次，可以使用一个for循环进行松弛
    //先放松起点。
    Relax(g, start_point);
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
//这个函数的目的是选出一个距离开始点最近的一个点来进行松弛
int DijkstraSP::ToRelax(int start_point, int num_of_point) {
    int shortest;
    //这里先设置一个shortest为第一个还没有被松弛的值
    for(int i = 0; i < num_of_point; i++){
        if(marked[i] == true){
            continue;
        }else{
            shortest = i;
            break;
        }
    }
    for(int i = 0; i < num_of_point; i++){
        if(marked[i] == true){
            continue;
        }
        if(distance_to[shortest] >= distance_to[i]){
            shortest = i;
        }
    }
    return shortest;
}

//放松节点的操作是找到节点为出发点的边，然后比较一下加上这条边之后是否满足能够把路径起点到该边终点的距离变短。变短就更新距离。并且添加路径。
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