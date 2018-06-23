---
title: leetcode之合并有序链表
tags: leetcode,算法,C++
grammar_cjkRuby: true
---

## 题目
1. 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
2. 示例：输入：1->2->4, 1->3->4；输出：1->1->2->3->4->4

## 分析
- 思路比较简单，直接遍历两个链表，知道两个到达结尾。每次合并一个节点。
- 值得注意的是两个链表结束的时间不同，所以先判断是否有一个链表已经到达结尾，如果到达了直接合并另一个链表节点。
- 二者都非空比较大小后合并。

## 代码
- 速度较快，8ms。
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        // 保存返回的指针
        ListNode* result_point = result;
        if((l1 == NULL) && (l2 == NULL)){
            return NULL;
        }
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        while((l1 != NULL) or (l2 != NULL)){
            if(l1 == NULL){
                ListNode* new_node = new ListNode(l2->val);
                result->next = new_node;
                result = new_node;
                l2 = l2->next;
                continue;
            }
            if(l2 == NULL){
                ListNode* new_node = new ListNode(l1->val);
                result->next = new_node;
                result = new_node;
                l1 = l1->next;
                continue;
            }
            if(l2->val < l1->val){
                ListNode* new_node = new ListNode(l2->val);
                result->next = new_node;
                result = new_node;
                l2 = l2->next;
            }
            else{
                ListNode* new_node = new ListNode(l1->val);
                result->next = new_node;
                result = new_node;
                l1 = l1->next;
            }
        }
        return result_point->next;
    }
};
```
## 总结
题目较为简单，但是要主要保留第一个节点。还有每次合并到result链表后，result要从新指向最后一个节点。