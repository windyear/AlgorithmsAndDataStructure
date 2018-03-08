//
// Created by windyear_office on 18-3-8.
//

#ifndef SORTALGORITHM_EDGEWEIGHTEDGRAPDFS_H
#define SORTALGORITHM_EDGEWEIGHTEDGRAPDFS_H


#include "EdgeWeightDiGraph.h"

class EdgeWeightedGrapDFS {
private:
    int count;
    vector<bool> marked;
public:
    EdgeWeightedGrapDFS(const EdgeWeightDiGraph& g, int start_point);//构造函数，传入图的引用
    void DFS(const EdgeWeightDiGraph& g, int point); //这个函数需要修改成员，不能使用const修饰
    int Count() const; //不用修改成员变量，使用const修饰。
    bool Marked(int v) const; //不用修改成员变量，使用const修饰
};


#endif //SORTALGORITHM_EDGEWEIGHTEDGRAPDFS_H
