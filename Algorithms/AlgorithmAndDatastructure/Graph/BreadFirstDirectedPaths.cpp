//
// Created by windyear_office on 18-1-31.
//

#include <queue>
#include "BreadFirstDirectedPaths.h"

BreadFirstDirectedPaths::BreadFirstDirectedPaths(Digraph g, int v) {
    start_point = v;
    //初始化两个数组
    marked = new bool[g.V()];
    for(int i = 0; i < g.V(); i++){
        marked[i] = false;
    }
    edge_to = new int[g.V()];
    BFS(g,start_point);
}

BreadFirstDirectedPaths::~BreadFirstDirectedPaths() {
    delete[] marked;
    delete[] edge_to;
}

bool BreadFirstDirectedPaths::HasPathTo(int v) {
    return marked[v];
}

void BreadFirstDirectedPaths::BFS(Digraph g, int v) {
    //利用一个队列进行辅助存储还没有访问的节点。
    //首先处理开始的节点
    //加入队列的时候证明已经被访问了，标记为已访问,标记的顺序不能反。
    queue<int> point_queue;
    marked[v] = true;
    edge_to[v] = v;
    //这里的for循环可以合并，将第一个点加到队列中就可以。
    for(int s: g.Adj(v)){
        if(!marked[s]){
            //加入队列，并且其父节点为v
            edge_to[s] = v;
            marked[s] = true;
            point_queue.push(s);
        }
    }
    //接着，一直从队列中取出节点，直至队列为空
    while(!point_queue.empty()){
        int point = point_queue.front();
        point_queue.pop();
        for(int s: g.Adj(point)){
            if(!marked[s]){
                //加入队列，并且其父节点为v
                edge_to[s] = point;
                marked[s] = true;
                point_queue.push(s);
            }
        }
    }

}

list<int> BreadFirstDirectedPaths::PathTo(int v) {
    if(!HasPathTo(v)){
        //返回一个空的列表
        list<int> no_path;
        return no_path;
    }
    list<int> path;
    //头插法
    for(int x = v; x != start_point; x = edge_to[x]){
        path.push_front(x);
    }
    //最后加上起点
    path.push_front(start_point);
    return path;
}
