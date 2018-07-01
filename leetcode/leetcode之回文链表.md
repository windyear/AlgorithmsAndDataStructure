---
title: leetcode之回文链表
tags: leetcode,算法, C++
grammar_cjkRuby: true
---
## 题目
- 请判断一个链表是否为回文链表。
- 输入: 1->2->2->1；输出: true
## 分析
- 第一时间想到的是利用栈，额外的存储空间保存前面一半的节点值，然后跟后一半比较是否相等即可。
- 还有一个方法是翻转一半的链表。
- 由于单向链表不能反向搜索，所以经常应用快慢指针。比如用快慢指针找到一半的位置。
## 代码
```c++?linenums
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stack>

static auto lo = [] {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //想不到不用额外空间的方法
        //使用栈来存储数据
        if((head == nullptr) ||(head->next == nullptr)){
            return true;
        }
        stack<int> val;
        // 统计长度
        int size_of_list = 0;
        ListNode* point = head;
        while(point != nullptr){
            size_of_list += 1;
            point = point->next;
        }
        int a, b;
        a = size_of_list / 2;
        b = size_of_list % 2;
        // 分单数和双数的情况
        if(b == 0){
            while(a > 0){
                a--;
                val.push(head->val);
                head = head->next;
            }
            while(head != nullptr){
                if(head->val != val.top()){
                    return false;
                }
                head = head->next;
                val.pop();
            }
            return true;
        }
        else{
            while(a > 0){
                a--;
                val.push(head->val);
                head = head->next;
            }
            head = head->next;
            while(head != nullptr){
                if(head->val != val.top()){
                    return false;
                }
                head = head->next;
                val.pop();
            }
            return true;
        }
    }
};
```
## 总结
反向顺序需要马上想到栈，链表问题少不了快慢指针。