//
// Created by windyear_office on 18-6-21.
//

#ifndef SORTALGORITHM_SEQUENTIAL_SEARCHST_H
#define SORTALGORITHM_SEQUENTIAL_SEARCHST_H
#include <vector>
#include <iostream>

using namespace std;

// 使用链表实现的一个简单的符号表，使用泛型。每个节点都包含 key 和 value
template <typename Key, typename Value>
class SequentialSearchST{
    // 定义一个内部节点类
private:
    class Node{
    public:
        Key key;
        Value value;
        Node* next;
    public:
        Node(Key key, Value value, Node* next){
            this->key = key;
            this->value = value;
            this->next = next;
        }
    };
    // 链表的头指针
    Node* first;
    int n;

public:
    // 为了表示没有查找到，只能返回一个值的指针。
    Value* get(Key key){
        for(Node* node = first; node != nullptr; node = node->next){
            if(node->key == key){
                return &(node->value);
            }
        }
        return nullptr;
    };

    void put(Key key, Value value){
        // 遍历节点，如果存在key，则覆盖value，否则新增一个节点。
        for(Node* node = first; node != nullptr; node = node->next){
            if(node->key == key){
                node->value = value;
                return;
            }
        }
        // 如果找不到节点，更新头结点
        first = new Node(key, value, first);
        n++;
        return;
    };

    int size(){
        return n;
    };
    // 从开始删除某个节点
    void delete_element(Key key){
        if(first->key == key){
            // 保存新的头指针。
            Node* head = first->next;
            delete first;
            first = head;
            n--;
            return;
        }
        // 遍历链表。
        Node* p = first;
        Node* q = first->next;
        while(q != nullptr){
            if(q->key == key){
                p->next = q->next;
                delete q;
                q = p->next;
                n--;
                return;
            }
            p = p->next;
            q = q->next;
        }
        std::cout << "The key isn't in the ST." << endl;
        return;
    };
    // 利用查找函数
    bool contains(Key key){
        return get(key) != nullptr;
    };

    // 返回一个关键字的集合
    vector<Key> keys(){
        vector<Key> all_key;
        for(Node* node = first; node != nullptr; node = node->next){
            all_key.push_back(node->key);
        }
        return all_key;
    };

    bool is_empty(){
        return first == nullptr;
    };

    // 构造函数
    SequentialSearchST():n(0), first(nullptr){

    }
    // 析构函数需要delete整个链表
    ~SequentialSearchST(){
        for(Node* node = first; node != nullptr;){
            Node* to_delete = node;
            node = node->next;
            delete to_delete;
        }
    }
};
#endif //SORTALGORITHM_SEQUENTIAL_SEARCHST_H
