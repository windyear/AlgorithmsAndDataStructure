//
// Created by windyear_office on 18-2-2.
//

#include <iostream>
#include "KosarajuSCC.h"
#include "DepthFirstOrder.h"

KosarajuSCC::KosarajuSCC(Digraph g) {
    //初始化数组
    marked = new bool[g.V()];
    id = new int[g.V()];
    count = 0;
    //遍历每个点，如果还没有被访问即标记，就对其使用深度优先搜索。
    //获取逆向图的逆后序
    DepthFirstOrder depth_first_order(g.Reverse());
    stack<int> reverse_path = depth_first_order.ReversePostPath();
    int length = reverse_path.size();
    for(int v = 0; v < length; v++){
        int w = reverse_path.top();
        if(!marked[w]){
            DFS(g, w);
            //一次深度优先搜索产生一个新的连通分量
            count++;
        }
        reverse_path.pop();
    }
}

KosarajuSCC::~KosarajuSCC() {
    delete[] marked;
    delete[] id;
}

bool KosarajuSCC::Connected(int v, int w) {
    return id[v] == id[w];
}

int KosarajuSCC::Count() {
    return count;
}

int KosarajuSCC::Id(int v) {
    return id[v];
}

void KosarajuSCC::DFS(Digraph g, int v) {
    marked[v] = true;
    //标记连通分量
    id[v] = count;
    for(auto V: g.Adj(v)){
        if(!marked[V]){
            DFS(g,V);
        }
    }
}

void KosarajuSCC::TestSCC(Digraph g) {
    vector<vector<int> > components(Count());
    for(int i = 0; i < g.V(); i++){
        components[Id(i)].push_back(i);
    }
    cout << "components: " << endl;
    for(int i = 0; i < Count(); i++){
        for(auto v: components[i]){
            cout << v << " ";
        }
        cout << endl;
    }
}