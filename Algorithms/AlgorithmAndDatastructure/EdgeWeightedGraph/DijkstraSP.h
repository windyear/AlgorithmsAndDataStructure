//
// Created by windyear_office on 18-2-7.
//

#ifndef SORTALGORITHM_DIJKSTRASP_H
#define SORTALGORITHM_DIJKSTRASP_H

#include <vector>
#include <stack>
#include <list>
#include "DirectedEdge.h"
#include "EdgeWeightDiGraph.h"

using namespace std;
const double MAX_DISTANCE = 9999;
//由于还没有实现优先队列，所以先实现一个用for循环找到最近顶点的点，而且该顶点要还没有被松弛。所以要增加一个数组来记录被松弛了的顶点。
//算法的原理是利用松弛的方法，每次都松弛一个距离顶点最近的点。]
//松弛就是通过被松弛的点可以使其他的一些路径变短。
class DijkstraSP {
private:
    double* distance_to;//用来保存每个节点与顶点的距离。
    bool* marked;
    vector<DirectedEdge> edge_to;
public:
    DijkstraSP(EdgeWeightDiGraph g, int start_point);
    ~DijkstraSP();
    bool HasPathTo(int end_point);
    list<DirectedEdge> PathTo(int point);
    double DistanceTo(int v);
    int ToRelax(int start_point, int num_of_point);
    void Relax(EdgeWeightDiGraph& g, int to_relax);
};


#endif //SORTALGORITHM_DIJKSTRASP_H
