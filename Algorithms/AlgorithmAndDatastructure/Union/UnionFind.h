//
// Created by windyear_office on 18-2-6.
//

#ifndef SORTALGORITHM_UNIONFIND_H
#define SORTALGORITHM_UNIONFIND_H

//思路：
//一个数组的索引当做是数字，数组的元素值相同代表连接在一起。
//主要有两个操作，一个是连接，遍历数组，所有连接到一起的元素连到新元素上，即值等于新元素的值。
//是否相等就判断元素值是否相等即可。
//注意动态数组用指针表示，在析构函数进行delete,否则内存泄漏。
class UnionFind {
public:
    UnionFind(int N);
    ~UnionFind();
    void Union(int p, int q);
    bool IsConnected(int p, int q);
private:
    //代表数字id
    //要使用一个动态数组，所以可以定义一个指针变量，然后数组的长度使用常量表示
    int* id;
    const int klength;
};


#endif //SORTALGORITHM_UNIONFIND_H
