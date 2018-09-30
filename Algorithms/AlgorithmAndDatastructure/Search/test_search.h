//
// Created by windyear_office on 18-9-12.
// 专门用作测试查找表的头文件
//

#ifndef SORTALGORITHM_TEST_SEARCH_H
#define SORTALGORITHM_TEST_SEARCH_H
#include "sequential_searchST.h"
#include "binary_searchST.h"
#include <string>
#include <fstream>
#include <memory>

// 简单测试一下基于无序链表的符号表
void test_sqequential_search_ST(string file_name){
    // 改用只能指针比较安全
    auto st = make_shared<SequentialSearchST<string, int>>();
    // SequentialSearchST<string, int>* st = new SequentialSearchST<string, int>();
    ifstream input(file_name);
    int count = 0;
    string input_char;
    while(input >> input_char){
        st->put(input_char, count);
        count++;
    }
    cout << "The original ST:" << st->size() << endl;
    for(auto node: st->keys()){
        cout << node << " " << *(st->get(node)) << endl;
    }
    // 测试删除功能
    st->delete_element("L");
    st->delete_element("H");
    cout << "Delete key \"L\" and \"H\": " << st->size() << endl;
    for(auto node: st->keys()){
        cout << node << " " << *(st->get(node)) << endl;
    }
    cout << "Is St contains \"X\":" << st->contains("X") << endl;
    cout << "Is ST empty?" << st->is_empty() << endl;
    // delete st;
}

// 简单测试一下基于有序数组的符号表，核心是采用了二分查找法。
void test_binary_searchST(string file_name){
    auto st = make_shared<Binary_SearchST<string, int> >();
    ifstream input(file_name);
    int count = 0;
    string input_string;
    while(input >> input_string){
        st->put(input_string, count);
        count++;
    }

    // 遍历符号表，应该是有序的。
    for(string key: st->all_keys()){
        cout << key << " " << *(st->get(key)) << endl;
    }
}
// 用符号表统计单词出现次数的测试程序
void Frequency_Counter(string input_min_len, string filename){
    // 文件读入流
    ifstream input(filename);
    int min_len = stoi(input_min_len);
    SequentialSearchST<string, int> ST;
    // 从文件流中读取所有的单词，直到文件的末尾。
    string word;
    while(input >> word){
        if(word.size() < min_len){
            continue;
        }
        // 查找算法非常耗时，因为要遍历链表
        if(ST.contains(word)){
            ST.put(word, (*ST.get(word)) + 1);
        }
        else{
            ST.put(word, 1);
        }
    }
    // 找到出现频率最大的单词
    string max = " ";
    ST.put(max, 0);
    for(auto key: ST.keys()){
        if(*(ST.get(key)) > *(ST.get(max))){
            max = key;
        }

    }
    cout << "The most frequency word is " << max << " and it appends " << *(ST.get(max)) << " times!" << endl;
}
#endif //SORTALGORITHM_TEST_SEARCH_H
