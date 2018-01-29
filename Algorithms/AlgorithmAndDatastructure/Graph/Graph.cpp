//
// Created by windyear_office on 18-1-25.
//

#include <fstream>
#include "Graph.h"

Graph::Graph(int v): adj(v){
    //创建空的邻接表，点的数目为v
    this->v = v;
    this->e = 0;
    //this->adj = new vector(v);//不要将stl和数组混合使用，比如这里指向list的指针，但是根本无法确定list的大小。可以改用vector。
    //后来发现原因应该是传入图对象是使用了默认的复制构造函数，而数组不能直接赋值。换成vector之后才可以。
}
Graph::Graph(string filename, int s):adj(s){
    ifstream input(filename);
    //能够打开文件
    e = 0;
    if(input){
        //直接当做流来进行处理
        int edge;
        input >> v >> edge;
        //依次读取每条边
        int point1, point2;
        for(int i = 0; i < edge; i++){
            input >> point1 >> point2;
            AddEdge(point1, point2);
        }
    }
    input.close();
}


Graph::~Graph() {
    //delete[] adj;

}

int Graph::E() {
    return e;
}

int Graph::V() {
    return v;
}

void Graph::AddEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
    e++;
}
//直接返回一个列表，列表不大的话消耗不大。
list<int> Graph::Adj(int v) {
    return adj[v];
}
