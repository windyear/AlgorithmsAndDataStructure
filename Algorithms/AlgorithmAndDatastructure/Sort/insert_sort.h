//
// Created by windyear_office on 17-11-29.
//
/*
 * 插入排序主要是遍历数组，然后每个元素都找到它对应应该插入的位置，在对已经排好序的程序进行插入排序的时候可以很快。
 * 但是数组的移动操作次数比较多。
 */

#include "basesort.h"

class InsertSort: public Sort{
public:
    explicit InsertSort(int length, int* p_array): Sort(length, p_array){}

    //插入排序
    void Insert_Sort(){
        for(int i = 0; i < N - 1; i++){
            int insert_index = i + 1;
            int temp = array[insert_index];
            for(int j = i; j >= 0; j--){
                //如果还没找到合适位置，元素往后移动一个位置
                if(temp < array[j]){
                    //特殊处理一下j=0的情况
                    array[j+1] = array[j];
                    if(j == 0){
                        array[j] = temp;
                    }
                }else{
                    array[j+1] = temp;
                    //error:这里一开始使用了continue导致某个元素找到应该插入的位置后没有进入
                    // 到下一个位置的寻找，而是继续替换掉前面的元素。
                    break;
                }
            }
        }
    }

    void Insert_Sort2(){
        //每次都找到元素应该放置的位置
        for(int i = 1; i < N; i++){
            for(int j = i; j > 0 && array[j] < array[j-1]; j--){
                Exchange(j, j-1);
            }
        }
    }
};
