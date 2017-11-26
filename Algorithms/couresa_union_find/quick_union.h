/*
author: windyear
time: 2017-11-26
思路：
快速连接，之前的方法需要遍历数组且改变很多元素的值，使用树的结构来表示元素的关系，
树连接时可以直接连接根节点即可。
*/

#ifndef QUICK_UNION_H_INCLUDED
#define QUICK_UNION_H_INCLUDED
class QuickUnion{
public:
    QuickUnion(int N);
    ~QuickUnion();
    void Union(int p, int q);
    bool IsConnected(int p, int q);
    int Root(int number);
private:
    const int klength;
    int* id;
};


#endif // QUICK_UNION_H_INCLUDED
