//
// Created by windyear_office on 17-11-29.
//
/*
 * 每次测试的时候自己输入数组很麻烦
 * 于是写一个生成测试数组的类模板，可以生成不同类型的数组
*/
#ifndef SORTALGORITHM_CREATE_TEST_ARRAY_H
#define SORTALGORITHM_CREATE_TEST_ARRAY_H

#include <cstdlib>
#include <unistd.h>
template<class T, int length>
class CreateTestArray{
public:
    explicit CreateTestArray(){
       //生成的数组的最大值不超过数组长度，采用随机数的方式
        sleep(1);
        srand((unsigned)time(NULL));
        //长度不能超过你n_mod
        int n_mod = length;
        if(length == 0){
            return;
        }
        //生成随机数组
        for(int i = 0; i < length; i++){
            test_array[i] = rand() % n_mod;
        }
    }
    //返回数组地址
    T* GetArrayAdress(){
        return test_array;
    }
    //返回数组长度
    int GetSize(){
        return length;
    }
private:
    //一个私有的测试数组
    T test_array[length];
};
#endif //SORTALGORITHM_CREATE_TEST_ARRAY_H
