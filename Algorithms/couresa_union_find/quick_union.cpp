/*
author: windyear
time: 2017-11-26
*/
#include "quick_union.h"

QuickUnion::QuickUnion(int N):klength(N){
    id = new int[klength];
    for(int i = 0; i < klength; i++){
        id[i] = i;
    }
}

QuickUnion::~QuickUnion(){
    delete[] id;
}

void QuickUnion::Union(int p, int q){
    int proot = Root(p);
    int qroot = Root(q);
    id[proot] = qroot;
    return ;
}

bool QuickUnion::IsConnected(int p, int q){
    return Root(p) == Root(q);
}

int QuickUnion::Root(int number){
    //这里一开始用了if是错的，应该是不断循环
    while(id[number] != number){
        number = id[number];
    }
    return number;
}
