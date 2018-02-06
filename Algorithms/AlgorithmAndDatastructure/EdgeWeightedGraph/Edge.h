//
// Created by windyear_office on 18-2-3.
//

#ifndef SORTALGORITHM_EDGE_H
#define SORTALGORITHM_EDGE_H

#include <string>
using namespace std;
//这里的边要加入优先队列，所以应该实现一个比较的算法。
class Edge {
private:
    int v;
    int w;//两个点,不需要改变
    double weight;//权重
public:
    //如果成员函数不用修改成员，应该声明为const
    //如果不适用默认参数的话，后面的vector调用resize函数的时候会不能初始化空间。
    Edge(int v = 0, int w = 0, double weight = 0);
    ~Edge();
    double Weight() const;
    int Either() const;
    int Other(int vertex) const;
    int CompareTo(Edge that) const;
    string ToString() const;
    //重载一个比较操作符，进行比较
    //这里的小于要返回相反的情况，这样用在优先队列中才会有效。
    friend bool operator<(Edge e1, Edge e2){
        if(e1.Weight() < e2.Weight()){
            return false;
        }
        return true;
    }
};


#endif //SORTALGORITHM_EDGE_H
