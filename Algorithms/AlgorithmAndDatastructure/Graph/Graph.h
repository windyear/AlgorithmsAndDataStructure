//
// Created by windyear_office on 18-1-25.
//

#ifndef SORTALGORITHM_GRAPH_H
#define SORTALGORITHM_GRAPH_H

#include <list>
#include <vector>

using namespace std;

//采用邻接表来存储图。
//graph作为参数会调用复制构造函数。
class Graph {
private:
    int v; //定点数目
    int e; //边数目
    vector<list<int> > adj; //邻接表,这个指针有问题。之前用普通数组，类对象作为值传递的时候会调用复制构造函数，这时候会出问题。浅拷贝。
public:
    Graph(int v);
    ~Graph();//删除new出来的内存空间
    int V();//返回点数
    int E();//返回边数
    void AddEdge(int v, int w);//添加一条边
    list<int> Adj(int v);//返回迭代器，list的迭代器。
};


#endif //SORTALGORITHM_GRAPH_H
