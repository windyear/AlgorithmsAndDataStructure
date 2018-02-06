//
// Created by windyear_office on 18-2-6.
//

#include "UnionFind.h"

UnionFind::UnionFind(int N):klength(N){
    id = new int[N];
    for(int i = 0; i < N; i++){
        id[i] = i;
    }
}

UnionFind::~UnionFind(){
    delete[] id;
}

void UnionFind::Union(int p, int q){
    //必须先用两个变量保留原来的id对应的值，不然之后id[p]之后会变成id[q]
    int pid = id[p];
    int qid = id[q];
    for(int i = 0; i < klength; i++){
        if(id[i] == pid){
            id[i] = qid;
        }
    }
}

bool UnionFind::IsConnected(int p, int q){
    return id[p] == id[q];
}
