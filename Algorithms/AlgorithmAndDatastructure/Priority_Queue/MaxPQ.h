//
// Created by windyear_office on 18-2-3.
//

#ifndef SORTALGORITHM_MAXPQ_H
#define SORTALGORITHM_MAXPQ_H

#include <vector>

using namespace std;

//最大优先队列，可以用基本的数组或者链表等实现，但是插入或者删除最大元素的操作总有一个需要线性时间。
//采用完全二叉树实现的优先队列，即最大堆，可以实现对数时间的查找和插入。
class MaxPQ {
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
    MaxPQ(int maxN);
    void Insert(int v);
    int DelteMax();
    int Size();
    bool IsEmpty();
};


#endif //SORTALGORITHM_MAXPQ_H
