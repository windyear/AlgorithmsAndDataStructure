//
// Created by windyear_office on 18-9-12.
// 专门用作测试查找表的头文件
//

#ifndef SORTALGORITHM_TEST_SEARCH_H
#define SORTALGORITHM_TEST_SEARCH_H
#include "sequential_searchST.h"
#include <string>
#include <fstream>
#include <memory>

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
#endif //SORTALGORITHM_TEST_SEARCH_H
