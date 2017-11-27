/*
author: windyear
time: 2017-11-26
*/
#include "weighted_quick_union.h"

WeightedQuickUnion::WeightedQuickUnion(int N):klength(N),count(N){
    id = new int[klength];
    sizeoftree = new int[klength];
    for(int i = 0; i < klength; i++){
        id[i] =i;
        sizeoftree[i] = 1;
    }
}

WeightedQuickUnion::~WeightedQuickUnion(){
    delete[] id;
    delete[] sizeoftree;
}

void WeightedQuickUnion::Union(int p, int q){
    int proot = Root(p);
    int qroot = Root(q);
    if( proot == qroot){
        return;
    }
    //比较两棵树的节点数，节点少的连接到多的那边去，然后相应的树节点总数相加。
    if(sizeoftree[proot] <= sizeoftree[qroot]){
        id[proot] = q;
        sizeoftree[q] += sizeoftree[p];
    }else{
        id[qroot] = p;
        sizeoftree[p] += sizeoftree[q];
    }
    count--;
}

int WeightedQuickUnion::Root(int number){
    //这里一开始用了if是错的，应该是不断循环
    while(id[number] != number){
        number = id[number];
    }
    return number;
}

bool WeightedQuickUnion::IsConnected(int p, int q){
    return Root(p) == Root(q);
}

int WeightedQuickUnion::Count(){
    return count;
}
