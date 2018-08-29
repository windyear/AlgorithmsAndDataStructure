---
title: leetcode142之寻找环形链表的环的起点
tags: leetcode,算法, C++
grammar_cjkRuby: true
---
## 题目
- 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
- 说明：不允许修改给定的链表。
- 尽量不用额外的存储空间
## 分析
- 这个跟寻找环的题目相似，但是难度增加了。花费了较多时间去做。
- 肯定是利用快慢指针找出是否存在环。画图之后发现，慢指针走的步数是环的长度。所以，只要另一个指针从开头出发，慢指针继续向前走，他们碰到的节点就是环的入口。
- 第一版的代码还用了一个记录长度整型，多走了一些步骤。后面优化了。
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
    ListNode *detectCycle(ListNode *head) {
        // 快慢指针，先求出环的长度，然后一个指针先走一个环的长度的步数，然后另一个指针从头开始，他们会在入口点遇见。
        if((head == nullptr) || (head->next == nullptr)){
            return nullptr;
        }
        int count = 0;
        ListNode* normal = head;
        ListNode* fast = head;
        // 找到相等点或者到达空指针
        while(true){
            if((fast->next == nullptr) || (fast->next->next == nullptr)){
                return nullptr;
            }
            fast = (fast->next)->next;
            normal = normal->next;
            count += 1;
            if(fast == normal){
                break;
            }
        }
        // count的次数就是环的长度
        fast = head;
        while(count > 0){
            fast = fast->next;
            count--;
        }
        normal = head;
        while(true){
            if(normal == fast){
                return fast;
            }
            fast = fast->next;
            normal = normal->next;
        }
    }
};
```
**改良版本代码**
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
    ListNode *detectCycle(ListNode *head) {
        // 快慢指针，先求出环的长度，然后一个指针先走一个环的长度的步数，然后另一个指针从头开始，他们会在入口点遇见。
        if((head == nullptr) || (head->next == nullptr)){
            return nullptr;
        }
        // int count = 0;
        ListNode* normal = head;
        ListNode* fast = head;
        // 找到相等点或者到达空指针
        while(true){
            if((fast->next == nullptr) || (fast->next->next == nullptr)){
                return nullptr;
            }
            fast = (fast->next)->next;
            normal = normal->next;
            // count += 1;
            if(fast == normal){
                break;
            }
        }
        // count的次数就是环的长度
        fast = head;
        // while(count > 0){
        //     fast = fast->next;
        //     count--;
        // }
        while(true){
            if(normal == fast){
                return fast;
            }
            fast = fast->next;
            normal = normal->next;
        }
    }
};
```
## 总结
链表问题还是要注重快慢指针的应用和画图出来。