//
// Created by windyear_office on 18-2-3.
//

#include "MaxPQ.h"

MaxPQ::MaxPQ(int maxN) : priority(maxN + 1){
    length = maxN;
}

void MaxPQ::Exchange(int i, int j) {
    if(i > length || j > length){
        return;
    }
    int temp = priority[i];
    priority[i] = priority[j];
    priority[j] = temp;
}

bool MaxPQ::less(int i, int j) {
    if(i > length || j > length){
        return false;
    }
    if(priority[i] <= priority[j]){
        return false;
    }else{
        return true;
    }
}

void MaxPQ::Sink(int k) {
    //先找到两个子节点，找出大一点的子节点，再比较父节点与子节点来判断是否要交换。
    //while的条件保证了还有子节点。
    while(2*k <= length){
        int son = 2*k;
        if(son < length && less(son, son + 1)){
            son++;
        }
        if(less(son, k)){
            break;
        }
        Exchange(son, k);
        k = son;
    }
}

void MaxPQ::Swim(int k) {
    //保证还有父节点
    while(k > 1){
        if(less(k/2, k)){
            Exchange(k/2, k);
            k = k / 2;
        }else{
            break;
        }
    }
}

bool MaxPQ::IsEmpty() {
    return length == 0;
}

int MaxPQ::Size() {
    return length;
}

void MaxPQ::Insert(int v) {
    priority.push_back(v);
    length++;
    Swim(length);
}

int MaxPQ::DelteMax() {
    int max = priority[1];
    Exchange(length, 1);
    length--;
    Sink(1);
    return max;
}