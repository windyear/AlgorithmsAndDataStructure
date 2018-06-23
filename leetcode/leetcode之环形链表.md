---
title: leetcode之环形链表 
tags: C++,leetcode,算法
grammar_cjkRuby: true
---
## 题目描述
- 给定一个链表，判断链表中是否有环。不用额外空间。
## 题目分析
- 可以使用快慢指针，快指针比满指针快一步，如果有环就一定可以追上。如果到达了空指针，说明没有环。
- 注意比较相等的时候要比较指针相等，不是节点的值相等。
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
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 快慢指针，一个走一步，一个走两步，如果有环肯定能碰到，如果没有就最后都指向空。
        bool has_cycle = false;
        if((head == NULL) || (head->next == NULL)){
            return false;
        }
        ListNode* p1 = head;
        ListNode* p2 = head;
        while((p1 != NULL) || (p2 != NULL)){
            // 往下走一步和两步
            // 如果走到结尾，证明是无环
            if(p1->next == NULL){
                return false;
            }
            else{
                p1 = p1->next;
            }
            if(p2->next == NULL){
                return false;
            }
            else{
                p2 = p2->next;
            }
            if(p2->next == NULL){
                return false;
            }
            else{
                p2 = p2->next;
            }
            if(p1 == p2 ){
                return true;
            }
        }
        return false;
    }
};
```
**改进版代码：**因为快指针走得更快，所以如果没有环肯定先到达尾部，所以只需判断快指针是否指向空。
```c++?linenums
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 快慢指针，一个走一步，一个走两步，如果有环肯定能碰到，如果没有就最后都指向空。
        bool has_cycle = false;
        if((head == NULL) || (head->next == NULL)){
            return false;
        }
        ListNode* p1 = head;
        ListNode* p2 = head;
        // 快指针先到达，所以可以只检查快指针。
        // 不能先检查next
        while((p2 != NULL) && (p2->next != NULL)){
            // 往下走一步和两步
            // 如果走到结尾，证明是无环
            p1 = p1->next;
            p2 = p2->next;
            p2 = p2->next;
            if(p1 == p2){
                return true;
            }
        }
        return false;
    }
};
```
**一个坑：** 判断指针的是否不能先判断next，有可能快指针已经指向了空。
## 总结
一到快慢指针典型的题目。