---
title: leetcode之两数相加
tags: 算法,C++, leetcode
grammar_cjkRuby: true
---

## 题目描述
- 给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。
- 示例：输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)；输出：7 -> 0 -> 8；原因：342 + 465 = 807。
## 思路
- 很容易想到按照位数从低位到高位开始遍历链表，进行相加，记录是否有进位。
- 难点在于链表长度不一，不知道哪个链表先结束。想到了如果有一个链表已经指向空时可以将相加的值变为0，继续进行相加知道两个链表都指向空。
- 一个容易忽略的地方就是如果最后还有进位，应该最后补上一个节点。
## 代码
```
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        // 保留一个结果头指针
        ListNode* result_head = result;
        // 将个位数相加
        result->val = l1->val + l2->val;
        // 用于保存进位的数字
        int add = 0;
        if(result->val >= 10){
            add = 1;
            result->val = result->val - 10;
        }
        // 指针指向下一位
        l1 = l1->next;
        l2 = l2->next;
        // 直到两个链表都指向空为止。
        while(!(l1==NULL && l2==NULL)){
            // 如果有一个节点是空节点将待加的值设置为0
            int val1 = 0;
            int val2 = 0;
            if(l1 != NULL){
                val1 = l1->val;
            }
            if(l2 != NULL){
                val2 = l2->val;
            }
            ListNode* new_node = new ListNode(0);
            new_node->val = val1 + val2 + add;
            // 更新进位
            if(new_node->val >= 10){
                add = 1;
                new_node->val = new_node->val - 10;
            }
            else{
                add = 0;
            }
            // 更新三个链表指针
            result->next = new_node;
            result = new_node;
            if(l1 != NULL){
                l1 = l1->next;
            }
            if(l2 != NULL){
                l2 = l2->next;
            }
        }
        // 最后还要判断是否还有进位
        if(add == 1){
            ListNode* new_node = new ListNode(1);
            result->next = new_node;
        }
        return result_head;
              
    }
};
```
## 总结
题目有一定的难度，主要在于链表指向空的判断和处理。