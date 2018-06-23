---
title: leetcode之删除链表的节点
tags: leetcode,C++,算法
grammar_cjkRuby: true
---
## 题目
- 只给出一个节点信息，删除该节点。
- 链表至少包含两个节点。
链表中所有节点的值都是唯一的。
给定的节点为非末尾节点并且一定是链表中的一个有效节点。
不要从你的函数中返回任何结果。
## 思路
这道题要比较巧妙的思路，一开始的时候没有想到。因为链表是不能向前走的，所以不能找到前面一个节点。那么应该如何删除当前的节点呢？其实可以理解链表的节点只是值不同，值替换了其实链表的节点的顺序也相当于替换了。所以可以删除下一个节点，然后保留其值到当前节点中即可。
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
    void deleteNode(ListNode* node) {
        // 由于不能找到前面的指针，所以只能删除后一个节点，将值保留。
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
```
## 总结
这道题比较巧妙，如果想的到可以两行代码解决，如果想不到就没办法了。