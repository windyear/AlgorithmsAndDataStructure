---
title: leetcode之删除倒数第N个节点 
tags: leetcode,算法, C++
grammar_cjkRuby: true
---
## 题目
- 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
- 给定一个链表: 1->2->3->4->5, 和 n = 2。当删除了倒数第二个节点后，链表变为 1->2->3->5。
- 你能尝试使用一趟扫描实现吗？
## 分析
- 使用一遍扫描实现，需要计算倒数。很明显是使用快慢指针的问题。
- 快指针先走N步，然后一起走，到达最后的时候就能找到慢指针需要删除的节点。
- 添加一个头结点方便统一处理。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr){
            return head;
        }
        if(head->next == nullptr){
            return head->next;
        }
        // 单向链表特性不可反向搜索，使用快慢指针即可。
        // 增加一个头结点
        ListNode* new_node = new ListNode(0);
        new_node->next = head;
        int over_step = n;
        ListNode* p = new_node;
        ListNode* q = new_node;
        while(over_step != 0){
            p = p->next;
            over_step -= 1;
        }
        while(p->next != nullptr){
            p = p->next;
            q = q->next;
        }
        (q->next) = (q->next)->next;
        return new_node->next;
    }
};
```
## 总结
链表问题应用快慢指针和添加哨兵头结点非常有用。