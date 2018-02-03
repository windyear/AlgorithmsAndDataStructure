//
// Created by windyear_office on 18-2-3.
//

#ifndef SORTALGORITHM_MINPQ_H
#define SORTALGORITHM_MINPQ_H

#include <vector>
using namespace std;

//为了后面使用起来的方便，这里应该使用泛型编程，模板类。
class MinPQ {
private:
    //基于数组的完全二叉树，直接使用vector
    vector<int> priority;
    int length;
    //还有一些比如比较，交换等基础方法，不对外公开
    bool less(int i, int j);
    void Exchange(int i, int j);
    //堆调整
    void Swim(int k);
    void Sink(int k);
public:
    MinPQ(int maxN);
    void Insert(int v);
    int DelteMax();
    int Size();
    bool IsEmpty();
};

#endif //SORTALGORITHM_MINPQ_H
