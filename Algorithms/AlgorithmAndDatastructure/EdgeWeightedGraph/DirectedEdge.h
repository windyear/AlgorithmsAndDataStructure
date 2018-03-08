//
// Created by windyear_office on 18-2-7.
//

#ifndef SORTALGORITHM_DIRECTEDEDGE_H
#define SORTALGORITHM_DIRECTEDEDGE_H

#include <string>
using namespace std;
//跟无向图的区别主要在于边是有方向的，所以可以指定两个函数分别返回边的起点和终点。
class DirectedEdge {
private:
    int v;
    int w;
    double weight;
public:
    //默认构造函数在初始化STL容器的时候会用到。
    DirectedEdge(int v = 0, int w = 0, double weight = 0);
    int From();
    int To();
    string ToString();
    double Weight();
};

#endif //SORTALGORITHM_DIRECTEDEDGE_H
