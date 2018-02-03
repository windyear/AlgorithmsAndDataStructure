//
// Created by windyear_office on 18-2-3.
//

#ifndef SORTALGORITHM_EDGE_H
#define SORTALGORITHM_EDGE_H

#include <string>
using namespace std;
class Edge {
private:
    const int v;
    const int w;//两个点,不需要改变
    const double weight;//权重
public:
    //如果成员函数不用修改成员，应该声明为const
    Edge(int v, int w, double weight);
    ~Edge();
    double Weight() const;
    int Either() const;
    int Other(int vertex) const;
    int CompareTo(Edge that) const;
    string ToString() const;
};


#endif //SORTALGORITHM_EDGE_H
