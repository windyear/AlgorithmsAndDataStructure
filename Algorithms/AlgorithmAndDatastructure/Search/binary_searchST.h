//
// Created by windyear_office on 18-9-29.
// 有序数组实现的符号表，核心是二分查找，优化查找的时间。插入耗时，要移动数组。
// 没有实现comparable接口，所以不能处理各种不同类型的key。

#ifndef SORTALGORITHM_BINARY_SEARCHST_H
#define SORTALGORITHM_BINARY_SEARCHST_H

#include <vector>

template <typename Key, typename Value>
class Binary_SearchST{
private:
    // 数组长度经常发生变化，采用指针
    Key* keys;
    Value* values;
    // 一个记录数组长度， 一个记录字典长度.
    int N;
    int length;

    // 重要的函数,可以调整数组的大小
    void resize(int capacity){
        if(capacity <= N){
            return;
        }
        // 临时指针
        Key* temp_keys = new Key[capacity];
        Value* temp_values = new Value[capacity];
        for(int i = 0; i < N; i++){
            temp_keys[i] = keys[i];
            temp_values[i] = values[i];
        }
        // 删除原来的空间
        delete [] keys;
        delete [] values;
        keys = temp_keys;
        values = temp_values;
        temp_keys = nullptr;
        temp_values = nullptr;
        length = capacity;
        return;
    }

public:
    // 构造函数
    explicit Binary_SearchST(int capacity=10):N(0), length(capacity){
        keys = new Key[capacity];
        values = new Value[capacity];
    }

    // delete指针指向的数组
    ~Binary_SearchST(){
        delete [] keys;
        delete [] values;
    }

    int size(){
        return N;
    }

    bool is_empty(){
        return N == 0;
    }

    // 核心函数,通过二分查找找到对应索引，表示第几个。
    int rank(Key key){
        // 递推式
        int low = 0;
        int high = N - 1;
        while(low <= high){
            int middle = low + (high - low) / 2;
            // key 有序
            if(key < keys[middle]){
                high = middle - 1;
            }
            else if(key > keys[middle]){
                low = middle + 1;
            }
            else{
                return middle;
            }
        }
        // 有可能没找到，但是要返回位置。
        return low;
    }

    // 根据key查找value;
    Value* get(Key key){
        if(is_empty()){
            return nullptr;
        }
        // 这个不一定可以查到,还需要比较一下。
        int i = rank(key);
        if((i < N) && (key == keys[i])){
            return &values[i];
        }
        return nullptr;
    }

    // 是否包含某个键
    bool contains(Key key){
        return get(key) != nullptr;
    }
    // 删除
    void delete_element(Key key){
        if(is_empty()){
            return;
        }

        int i = rank(key);
        // key not in the table
        if(i == N){
            return;
        }
        if(keys[i] != key){
            return;
        }

        // 后面的元素往前移动一位
        for(int j = i; j < N-1; j++){
            keys[j] = keys[j+1];
            values[j] = values[j+1];
        }
        N--;
        // 动态调整数组长度
        if((N > 0) && (N == length/4)){
            resize(length/2);
        }
    }

    // 插入元素,比较麻烦，要整体移动数组的元素
    void put(Key key, Value value){
        int i = rank(key);
        // key in the table
        if((i < N) && (keys[i] == key)){
            values[i] = value;
            return;
        }

        // key not in the table
        // 扩容
        if(N == length){
            resize(2*length);
        }
        for(int j = N; j > i; j--){
            keys[j] = keys[j-1];
            values[j] = values[j-1];
        }
        keys[i] = key;
        values[i] = value;
        N++;
    }

    // 最大最小值, 没有检查为空的情况，存在运行错误。
    Key min_key(){
        return keys[0];
    }

    Key max_key(){
        return keys[N-1];
    }

    void delete_min(){
        delete_element(min_key());
    }

    void delete_max(){
        delete_element(max_key());
    }

    // 选择第k大的值
    Key select(int k){
        return keys[k];
    }

    Key floor(Key key){
        int i = rank(key);
        if((i < N) && (key == keys[i])){
            return keys[i];
        }
        if(i == 0){
               return keys[i];
            }
        else {
            return keys[i-1];
        }
    }

    Key ceiling(Key key){
        int i = rank(key);
        return keys[i];
    }

    int size(Key lo, Key hi){
        if(lo > hi){
            return 0;
        }
        if(contains(hi)){
            return rank(hi) - rank(lo) + 1;
        }
        else{
            return rank(hi) - rank(lo);
        }
    }

    // 返回一个容器装着keys
    std::vector<Key> all_keys(Key lo, Key hi){
        std::vector<Key> keys_queue;
        if(lo > hi){
            return keys_queue;
        }
        for(int i = rank(lo); i < rank(hi); i++){
            keys_queue.push_back(keys[i]);
        }
        if(contains(hi)){
            keys_queue.push_back(hi);
        }
        return keys_queue;
    }

    std::vector<Key> all_keys(){
        return all_keys(min_key(), max_key());
    }
};
#endif //SORTALGORITHM_BINARY_SEARCHST_H
