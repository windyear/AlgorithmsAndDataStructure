//
// Created by windyear_office on 18-2-6.
//

#ifndef SORTALGORITHM_KRUSKALMST_H
#define SORTALGORITHM_KRUSKALMST_H


#include <vector>
#include "Edge.h"
#include "EdgeWeightedGraph.h"
//思路就是以边为对象，每次选取不会构成一个环的最短边，直到选取了v－１条边。是否构成环可以用union_find结构来表示，每次加入边就相当于把边的两个点连到一起。
//用一个优先队列保存所有边即可。
class KruskalMST {
private:
    vector<Edge> mst;
public:
    KruskalMST(EdgeWeightedGraph g);
    vector<Edge> Edges();
    double Weight();
};


#endif //SORTALGORITHM_KRUSKALMST_H
