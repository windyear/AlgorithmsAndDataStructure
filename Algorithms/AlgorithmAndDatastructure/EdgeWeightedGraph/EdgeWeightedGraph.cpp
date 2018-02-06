//
// Created by windyear_office on 18-2-3.
//

#include <fstream>
#include "EdgeWeightedGraph.h"

EdgeWeightedGraph::EdgeWeightedGraph(int v): adj(v){
    this->v = v;
    this->e = 0;
}

//从文件中读取图
EdgeWeightedGraph::EdgeWeightedGraph(string filename){
    ifstream input(filename);
    if(input){
        int num_of_e;
        input >> v >> num_of_e;
        e = 0;
        adj.resize(v);
        for(int i = 0; i < num_of_e; i++){
            int v, w;
            double weight;
            input >> v >> w >> weight;
            Edge e(v, w, weight);
            AddEdge(e);
        }
    }
    input.close();
}

int EdgeWeightedGraph::E() const {
    return e;
}

int EdgeWeightedGraph::V() const {
    return v;
}

vector<Edge> EdgeWeightedGraph::Adj(int v) {
    return adj[v];
}

void EdgeWeightedGraph::AddEdge(Edge edge) {
    int v = edge.Either();
    int w = edge.Other(v);
    //为两个邻接表都增加一个元素，每条边有两个节点
    adj[v].push_back(edge);
    adj[w].push_back(edge);
    e++;
}

vector<Edge> EdgeWeightedGraph::Edges() {
    //返回所有边
    //由于每条边会存储两次，所以遍历的时候要排除相同的边。一个简单的方法是根据节点的大小判断。同一条边只会被加入一次
    vector<Edge> all_edges;
    for(int i = 0; i < v; i++){
        for(auto v: adj[i]){
            if(v.Other(i) > i){
                all_edges.push_back(v);
            }
        }
    }
    return all_edges;
}

EdgeWeightedGraph::~EdgeWeightedGraph() {

}