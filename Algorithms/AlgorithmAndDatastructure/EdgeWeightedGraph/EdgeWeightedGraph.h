//
// Created by windyear_office on 18-2-3.
//

#ifndef SORTALGORITHM_EDGEWEIGHTEDGRAPH_H
#define SORTALGORITHM_EDGEWEIGHTEDGRAPH_H

#include <vector>
#include <string>
#include "Edge.h"

using namespace std;

class EdgeWeightedGraph {
private:
    int v; //定点数目
    int e; //边数目
    vector<vector<Edge> > adj; //邻接表,这个指针有问题。之前用普通数组，类对象作为值传递的时候会调用复制构造函数，这时候会出问题。浅拷贝。
public:
    EdgeWeightedGraph(int v);//直接构造有v个顶点的图
    EdgeWeightedGraph(string filename);//一个从文件中读取图的结构的构造函数
    ~EdgeWeightedGraph();//删除new出来的内存空间
    int V() const;//返回点数
    int E() const;//返回边数
    void AddEdge(Edge edge);//添加一条边
    vector<Edge> Adj(int v);//返回迭代器，list的迭代器。
    vector<Edge> Edges();//返回所有边
};


#endif //SORTALGORITHM_EDGEWEIGHTEDGRAPH_H
