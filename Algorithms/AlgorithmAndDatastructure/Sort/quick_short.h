//
// Created by windyear_office on 17-12-14.
//

#ifndef SORTALGORITHM_QUICK_SHORT_H
#define SORTALGORITHM_QUICK_SHORT_H

#include "basesort.h"

class QuickSort:public Sort{
public:
    explicit QuickSort(int length, int* p_array):Sort(length, p_array){}
    //第一种思路，选取最后一个元素作为参考值，每次都划分出两组元素，然后递归继续快速排序
    void Quick_Sort(int low, int high){
        //判断递归结束的条件
        if(low >= high){
            return;
        }else {
            //划分值
            int label = array[high];
            int smaller_index = low;
            //开始循环遍历数组元素，遇到小于参考值的将其交换到前面
            for(int i = low; i < high; i++){
                if(array[i] < label){
                    Exchange(i, smaller_index);
                    smaller_index++;
                }
            }
            //最后交换一下最后的元素到中间
            Exchange(high, smaller_index);
            //开始递归
            //犯了一个大错误，此时smaller_index已经在正确的位置，不用进行排序，否则循环根本不会终止。
            Quick_Sort(low, smaller_index - 1);
            Quick_Sort(smaller_index + 1, high);
        }
    }

    //思路二：两边搜索，从两边分别向中间搜索，分别找到大于和小于的元素，交换，指导两个索引大小逆转
    void Quick_Sort2(int low, int high){
        if(low >= high){
            return;
        }else{
            //先选一个标记
            int label = array[low];
            int left = low + 1;
            int right = high;
            while(true){
                //左边遍历
                while(array[left] < label){
                    if(left == high){
                        break;
                    }
                    left++;
                }
                while(array[right] >= label){
                    if(right == low){
                        break;
                    }
                    right--;
                }
                //刚开始的时候这里忘记了加一个等于号，导致循环不能终止。
                if(left >= right){
                    break;
                }
                Exchange(left, right);
            }
            Exchange(low, right);
            Quick_Sort2(low, right - 1);
            Quick_Sort2(right + 1, high);
        }
    }
};
#endif //SORTALGORITHM_QUICK_SHORT_H
