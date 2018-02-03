//
// Created by windyear_office on 18-2-3.
//

#include "MinPQ.h"

MinPQ::MinPQ(int maxN) : priority(maxN + 1){
    length = maxN;
}

void MinPQ::Exchange(int i, int j) {
    if(i > length || j > length){
        return;
    }
    int temp = priority[i];
    priority[i] = priority[j];
    priority[j] = temp;
    return;
}

bool MinPQ::less(int i, int j) {
    if(i > length || j > length){
        return false;
    }
    if(priority[i] <= priority[j]){
        return true;
    }else{
        return false;
    }
}

void MinPQ::Sink(int k) {
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

void MinPQ::Swim(int k) {
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

bool MinPQ::IsEmpty() {
    return length == 0;
}

int MinPQ::Size() {
    return length;
}

int MinPQ::DelteMax() {
    int max = priority[1];
    Exchange(length, 1);
    length--;
    Sink(1);
    return max;
}

void MinPQ::Insert(int v){
        priority.push_back(v);
        length++;
        //这里一开始写错了，不应该是v，应该是最后的长度。
        Swim(length);
    }