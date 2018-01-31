//
// Created by windyear_office on 18-1-31.
//

#ifndef SORTALGORITHM_DEPTHFIRSTORDER_H
#define SORTALGORITHM_DEPTHFIRSTORDER_H
#include <queue>
#include <stack>
#include "Digraph.h"

using namespace std;
//这个类的方法利用深度优先搜索获得遍历定点的顺序，包括前序，后序，逆后序。而逆后序正好就是拓扑排序。
class DepthFirstOrder {
private:
    bool* marked;
    queue<int> pre_path;
    queue<int> post_path;
    stack<int> reverse_post_path;
public:
    DepthFirstOrder(Digraph g);
    ~DepthFirstOrder();
    void DFS(Digraph g, int V);
    queue<int> PrePath();
    queue<int> PostPath();
    stack<int> ReversePostPath();
};


#endif //SORTALGORITHM_DEPTHFIRSTORDER_H
