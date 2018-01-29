//
// Created by windyear_office on 18-1-29.
//

#include "TwoColorGraph.h"

TwoColorGraph::TwoColorGraph(Graph g) {
    marked = new bool[g.V()];
    color = new bool[g.V()];
    is_two_color = true;
    for(int v = 0; v < g.V(); v++){
        if(!marked[v]){
            DFS(g, v);
        }
    }
}

TwoColorGraph::~TwoColorGraph() {
    delete[] marked;
    delete[] color;
}

bool TwoColorGraph::IsTwoColor() {
    return is_two_color;
}

void TwoColorGraph::DFS(Graph g, int v) {
    marked[v] = true;
    for(int s: g.Adj(v)){
        if(!marked[s]){
            color[s] = !color[v];
            DFS(g, s);
        }else if(color[s] == color[v]){
            is_two_color = false;
        }
    }
}
