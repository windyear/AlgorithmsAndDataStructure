//
// Created by windyear_office on 18-2-6.
//

#ifndef SORTALGORITHM_QUICKUNION_H
#define SORTALGORITHM_QUICKUNION_H

/*
author: windyear
time: 2017-11-26
思路：
快速连接，之前的方法需要遍历数组且改变很多元素的值，使用树的结构来表示元素的关系，
树连接时可以直接连接根节点即可。
*/
class QuickUnion {
public:
    QuickUnion(int N);
    ~QuickUnion();
    void Union(int p, int q);
    bool IsConnected(int p, int q);
    int Root(int number);
    int Count();
private:
    const int klength;
    int* id;
    int count;
};


#endif //SORTALGORITHM_QUICKUNION_H
