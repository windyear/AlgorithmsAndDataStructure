//
// Created by windyear_office on 18-3-8.
//

//之前用C++改写java程序的时候没有考虑如何写出比较好的代码，也没有考虑效率等因素。
//后来学习了一段时间的effective C++,了解了一些编程应该遵循的准则，所以后面的代码尽量遵循准则进行开发
#include "edgeweightedgrapdfs.h"

EdgeWeightedGrapDFS::EdgeWeightedGrapDFS(const EdgeWeightDiGraph &g, int start_point):
        marked(g.V(), false), count(0) {
    DFS(g, start_point);
}

void EdgeWeightedGrapDFS::DFS(const EdgeWeightDiGraph &g, int point){
    marked[point] = true;
    count++;
    //遍历该点的邻点
    for(DirectedEdge edge: g.Adj(point)){
        //出现一个错误，因为传入的对象是const的，所以不能调用非const的函数
        int to = edge.To();
        if(Marked(to) == false){
            DFS(g, to);
        }
    }
}

int EdgeWeightedGrapDFS::Count() const {
    return count;
}

bool EdgeWeightedGrapDFS::Marked(int v) const {
    return marked[v];
}