//
// Created by windyear_office on 18-1-30.
//

#include "Digraph.h"
#include <fstream>

Digraph::Digraph(int v): adj(v){
    //创建空的邻接表，点的数目为v
    this->v = v;
    this->e = 0;
    //this->adj = new vector(v);//不要将stl和数组混合使用，比如这里指向list的指针，但是根本无法确定list的大小。可以改用vector。
    //后来发现原因应该是传入图对象是使用了默认的复制构造函数，而数组不能直接赋值。换成vector之后才可以。
}
Digraph::Digraph(string filename, int s){
    ifstream input(filename);
    //能够打开文件
    e = 0;
    if(input){
        //直接当做流来进行处理
        int edge;
        input >> v >> edge;
        //依次读取每条边
        //可以用resize进行重新分配内存，stl的容器都是自动管理内存的，不用管他们。
        adj.resize(v);
        int point1, point2;
        for(int i = 0; i < edge; i++){
            input >> point1 >> point2;
            AddEdge(point1, point2);
        }
    }
    input.close();
}


Digraph::~Digraph() {
    //delete[] adj;

}

int Digraph::E() {
    return e;
}

int Digraph::V() {
    return v;
}

void Digraph::AddEdge(int v, int w) {
    //这里只加一条边
    adj[v].push_back(w);
    e++;
}
//直接返回一个列表，列表不大的话消耗不大。
list<int> Digraph::Adj(int v) {
    return adj[v];
}

Digraph Digraph::Reverse() {
    Digraph digraph(v);
    for(int s = 0; s < v; s++){
        for(auto w: Adj(s)){
            digraph.AddEdge(w, s);
        }
    }
    return digraph;
}