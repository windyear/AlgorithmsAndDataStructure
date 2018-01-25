//
// Created by windyear_office on 17-12-1.
//

#ifndef SORTALGORITHM_SHELL_SORT_H
#define SORTALGORITHM_SHELL_SORT_H

#include "basesort.h"

class ShellSort:public Sort{
public:
    explicit ShellSort(int length, int* p_array):Sort(length, p_array){}
    void Shell_Sort(){
        //希尔排序是插入排序的优化版本，每次移动的距离大一些，这样面对随机数组的排序时就不用一个一个位置慢慢移动
        //初始的间隔值寻求3h+1，然后每次取其三分之一
        int h = 1;
        while(h < N / 3){
            h = 3 * h + 1;
        }
        //一直到h=1
        while(h > 0){
            for(int i = h; i < N; i++){
                //这里判断从j大于h开始，否则数组会越界。
                for(int j = i; j >= h && array[j] < array[j-h]; j = j - h){
                    Exchange(j, j - h);
                }
            }
            h = h / 3;
        }
    }
};
#endif //SORTALGORITHM_SHELL_SORT_H
