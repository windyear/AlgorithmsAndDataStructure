//
// Created by windyear_office on 18-2-3.
//

#ifndef SORTALGORITHM_LAZYPRIM_H
#define SORTALGORITHM_LAZYPRIM_H

#include "Edge.h"
#include "../Priority_Queue/MinPQ.h"
#include "EdgeWeightedGraph.h"
#include <vector>
#include <queue>

using namespace std;

//最小生成树的prim算法，先随机选择一个点，划分为两个切分集，选择最短的一条边加入到最小生成树。
//然后对应的点加入切分集，再次基于贪心算法的原理选择最短的一条横切边加入。知道定点全部加入。
class LazyPrim {
private:
    //需要一个数组标记访问了的节点，一个存储最小生成树，一个优先队列存放横切边集合。
    bool* marked;
    vector<Edge> mst;
    //直接使用stl的优先队列
    priority_queue<Edge> pq; //横切边
    //一个私有成员函数为了添加节点以及还没访问节点之间的横切边。
    void Visit(EdgeWeightedGraph g, int v);
public:
    LazyPrim(EdgeWeightedGraph g);
    ~LazyPrim();
    //返回最小生成树对应的所有边
    vector<Edge> Edges();
    double Weight();
};


#endif //SORTALGORITHM_LAZYPRIM_H
