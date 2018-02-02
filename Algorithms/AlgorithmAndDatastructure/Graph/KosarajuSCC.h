//
// Created by windyear_office on 18-2-2.
//

#ifndef SORTALGORITHM_KOSARAJUSCC_H
#define SORTALGORITHM_KOSARAJUSCC_H

#include "Digraph.h"

//该算法的核心在于用逆向图的逆后续进行深度优先遍历可以得到在同一个强连通分量的所有节点。
//在图g中深度遍历，如果存在s到v，只需要再证明有v到s的存在即可。反过来假设逆向图逆后序v到s，存在两种情况，一种是
//不在同一个连通分量，第二种是存在v到s的路径。如果g中存在s到v，证明g-1中存在v到s。得证。
class KosarajuSCC {
private:
    bool* marked;
    int* id;//标记连通分量
    int count;//标记是第几个连通分量
public:
    KosarajuSCC(Digraph g);
    ~KosarajuSCC();
    void DFS(Digraph g, int v);
    int Id(int v);
    int Count();
    //判断两个节点是否在同一个分量，即是否连接在一起
    bool Connected(int v, int w);
    void TestSCC(Digraph g);
};


#endif //SORTALGORITHM_KOSARAJUSCC_H
