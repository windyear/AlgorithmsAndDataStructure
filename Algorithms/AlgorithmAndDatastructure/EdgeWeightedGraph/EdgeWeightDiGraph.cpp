//
// Created by windyear_office on 18-2-7.
//

#include <fstream>
#include "EdgeWeightDiGraph.h"

EdgeWeightDiGraph::EdgeWeightDiGraph(int v): adj(v){
    this->v = v;
    this->e = 0;
}

//从文件中读取图
EdgeWeightDiGraph::EdgeWeightDiGraph(string filename){
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
            DirectedEdge e(v, w, weight);
            AddEdge(e);
        }
    }
    input.close();
}

int EdgeWeightDiGraph::E() const {
    return e;
}

int EdgeWeightDiGraph::V() const {
    return v;
}

vector<DirectedEdge> EdgeWeightDiGraph::Adj(int v) {
    return adj[v];
}

void EdgeWeightDiGraph::AddEdge(DirectedEdge edge) {
    int v = edge.From();
    //为两个邻接表都增加一个元素，每条边有两个节点
    //这里只能添加一条边
    adj[v].push_back(edge);
    e++;
}

vector<DirectedEdge> EdgeWeightDiGraph::Edges() {
    //返回所有边
    //由于每条边会存储两次，所以遍历的时候要排除相同的边。一个简单的方法是根据节点的大小判断。同一条边只会被加入一次
    vector<DirectedEdge> all_edges;
    for(int i = 0; i < v; i++){
        for(auto v: adj[i]){
            //因为边不会重复，所以直接添加
            all_edges.push_back(v);
        }
    }
    return all_edges;
}

EdgeWeightDiGraph::~EdgeWeightDiGraph() {

}