//
// Created by windyear_office on 17-11-28.
//
#ifndef SORTALGORITHM_SELECT_SORT_H
#define SORTALGORITHM_SELECT_SORT_H
#include "basesort.h"

class SelectSort: public Sort{
public:
    explicit SelectSort(int length, int* p_array):Sort(length, p_array){}

    void Select_Sort(){
        //每次选择一个最小值，然后交换到前面
        for(int i = 0; i < N; i++){
            //用一个标记保留最小值的索引，这样就不用每次都操作数组
            int min = i;
            for(int j = i + 1; j < N; j++){
                if(array[j] < array[min]){
                    min = j;
                }
            }
            Exchange(min, i);
        }
    }
};
#endif