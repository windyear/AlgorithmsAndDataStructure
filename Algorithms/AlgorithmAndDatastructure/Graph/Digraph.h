//
// Created by windyear_office on 18-1-30.
//

#ifndef SORTALGORITHM_DIGRAPH_H
#define SORTALGORITHM_DIGRAPH_H
#include <vector>
#include <list>
#include <string>

using namespace std;
//有向图的代码跟无向图差不多，只需要将添加边的操作变成只添加一条边。
class Digraph {
private:
    int v; //定点数目
    int e; //边数目
    vector<list<int> > adj; //邻接表,这个指针有问题。之前用普通数组，类对象作为值传递的时候会调用复制构造函数，这时候会出问题。浅拷贝。
public:
    Digraph(int v);//直接构造有v个顶点的图
    Digraph(string filename, int v);//一个从文件中读取图的结构的构造函数
    ~Digraph();//删除new出来的内存空间
    int V();//返回点数
    int E();//返回边数
    void AddEdge(int v, int w);//添加一条边
    list<int> Adj(int v);//返回迭代器，list的迭代器。
    Digraph Reverse();//反向图，可以找到所有指向一个节点的边。
};


#endif //SORTALGORITHM_DIGRAPH_H
