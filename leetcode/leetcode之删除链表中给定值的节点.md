---
title: leetcode之删除链表中给定值的节点
tags: C++,leetcode,算法
grammar_cjkRuby: true
---
## 题目
- 删除链表中等于给定值 val 的所有节点。
- 示例：输入: 1->2->6->3->4->5->6, val = 6；输出: 1->2->3->4->5
## 分析
- 比较简单，直接遍历一遍链表，将值相等的删除即可。删除时要保留前一个节点的指针，直接指向下一个节点。
- 重点注意的地方是，如果从头节点开始就是要删除的节点，会使得算法的操作边麻烦。
- 可以采用添加一个头结点的方法。最后返回头结点指向的那个节点。
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return head;
        }
        if((head->next == NULL) && (head->val == val)){
            return NULL;
        }
        // 删除节点
        ListNode* result = head;
        // 排除头结点就是val的情况
        while(result != NULL){
            if(result->val == val){
                result = result->next;
            }
            else{
                break;
            }
        }
        if(result == NULL){
            return result;
        }
        ListNode* p = result;
        ListNode* q = result->next;
        while(q != NULL){
            if(q->val == val){
                p->next = q->next;
                q = q->next;
            }
            else{
                p = p->next;
                q = q->next;
            }
        }
        return result;
    }
};
```
**增加头结点的版本**
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return head;
        }
        if((head->next == NULL) && (head->val == val)){
            return NULL;
        }
        // 删除节
        // 排除头结点就是val的情况
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* p = new_head;
        ListNode* q = new_head->next;
        while(q != NULL){
            if(q->val == val){
                p->next = q->next;
                q = q->next;
            }
            else{
                p = p->next;
                q = q->next;
            }
        }
        return new_head->next;
    }
};
```
## 总结
题目并不难，主要是特殊情况的处理要注意。在链表的头增加一个哨兵节点是非常重要的一个方法，这样就可以解放头结点的作用，方便进行处理。