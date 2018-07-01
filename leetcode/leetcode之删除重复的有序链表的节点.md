---
title: leetcode之删除重复的有序链表的节点
tags: leetcode,算法, C++
grammar_cjkRuby: true
---
## 题目
- 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
- 输入: 1->2->3->3->4->4->5：输出: 1->2->5。
## 分析
1. 这个删除重复链表的题目跟之前的不同，要把重复的元素全部删除。遍历链表可以删除重复多余的链表，但是会剩下一个。问题的关键在于怎样把有重复的最后一个节点删除。
2. 可添加一个标记，如果为true，说明有重复，向后移动指针需要将重复的最后一个删除。
3. 增加一个头结点方便统一操作。
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
        // 这道题跟之前删除链表的不同之处是相同的都要删除。
        // 注意链表是排好序的
        // 加一个头结点，然后如果出现重复的情况做一个标记
        if((head == nullptr) || (head->next == nullptr)){
            return head;
        }
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* p = new_head;
        ListNode* q = head;
        ListNode* r = head->next;
        bool is_repeat = false;
        while(r != nullptr){
            if(r->val == q->val){
                // 删除r节点
                is_repeat = true;
                q->next = r->next;
                r = r->next;
            }
            else{
                // 先判断是否重复了
                if(is_repeat){
                    p->next = r;
                    q = r;
                    r = r->next;
                    is_repeat = false;
                }
                else{
                    p = p->next;
                    q = q->next;
                    r = r->next;
                    is_repeat = false;
                }
            }
        }
        // 最后还要判断q节点之前是否有重复
        if(is_repeat){
            p->next = nullptr;
        }
        return new_head->next;
    }
};
```
## 总结
仔细画好图之后处理特殊情况，题目不算太难。