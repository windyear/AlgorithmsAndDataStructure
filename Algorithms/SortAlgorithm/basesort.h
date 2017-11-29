//
// Created by windyear_office on 17-11-28.
//
/*
 * 定义一个所有排序类的基类，包含交换，比较等方法。
 * 这里只实现对整型数据的排序，不使用泛型编程。
 * 使用泛型编程可以实现处理不容数据类型的数组的排序。
 * 排序算法实现从小到大的排序
 */
#ifndef SORTALGORITHM_BASESORT_H
#define SORTALGORITHM_BASESORT_H
#include <iostream>
using namespace std;

class Sort{
public:
    //定义两个成员分别表示数组的长度和指向数组的指针。
    //不能定义为私有，否则子类访问不到，只能通过公有成员函数访问。
    int N;
    int* array;

    explicit Sort(int length, int* p_array):N(length), array(p_array){}
    ~Sort(){}
    bool IsShorted(){
        for(int i = 1; i < N; i++){
            if( array[i] < array[i-1]){
                return false;
            }
        }
        return true;
    }

    void Exchange(int p, int q){
        if(p >= N || q >= N){
            cout << "error, out of the array index!" << endl;
        }
        int temp;
        temp = array[p];
        array[p] = array[q];
        array[q] = temp;
        return;
    }

    void ShowArray(){
        cout << "the array is :";
        for(int i = 0; i < N; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }
};
#endif
