---
title: leetcode之删除链表中重复的元素
tags: C++,leetcode,算法
grammar_cjkRuby: true
---
## 题目
- 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
- 输入: 1->1->2;输出: 1->2

## 分析
- 题目比较简单，直接遍历一次即可。使用两个指针，如果后一个节点的值和前面一个相等，删除后面的一个节点。
- 注意传入的头结点为空或者只有一个元素的情况。
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
    ListNode* deleteDuplicates(ListNode* head) {
        if((head == NULL) || (head->next == NULL)){
            return head;
        }
        ListNode* p = head;
        ListNode* q = head->next;
        while(q != NULL){
            if(p->val == q->val){
                p->next = q->next;
                q = q->next;
            }
            else{
                p = p->next;
                q = q->next;
            }
        }
       return head;
    }
};
```
## 总结
- 题目比较简单，也不用添加哨兵节点。