---
title: leetcode之两种方法反转链表 
tags: leetcode,算法, C++
grammar_cjkRuby: true
---
## 题目
- 反转一个单链表。可以迭代或递归地反转链表。
- 示例：输入: 1->2->3->4->5->NULL；输出: 5->4->3->2->1->NULL。
## 分析
- 迭代的方法可以从头开始遍历，每次将一个指向反转。在草稿纸上画出草图，很明显需要三个临时指针。反转后所有指针向后移动一步。知道最后一个指针指向空。最后更新一下最后一个节点的指向。
- 别忘记了头结点要指向空。
- **递归的方法**：主要思想是调用反转函数反转子链表。将子链表和头结点合并。最后返回反转的链表的头结点。
## 代码
### 迭代版本
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
    ListNode* reverseList(ListNode* head) {
        if((head == NULL) || (head->next == NULL)){
            return head;
        }
        // 使用三个额外的指针记录
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* r = (head->next)->next;
        // 头节点变为尾节点，先将头结点指向NULL
        p->next = NULL;
        while(r != NULL){
            // 反向指针
            q->next = p;
            // 三个指针向后移动一步
            p = q;
            q = r;
            r = r->next;
        }
        // r为NULL时还要最后更改一个指向
        q->next = p;
        return q;
    }
};
```
### 递归版本
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
    ListNode* reverseList(ListNode* head) {
        // 采用递归的方法，就是使用反转函数反转子链表，直接当做已经反转了。
        if((head == NULL) || (head->next == NULL)){
            return head;
        }
        else{
            ListNode* son_list = reverseList(head->next);
            // 子链表的尾节点指向前一个节点
            head->next->next = head;
            head->next = NULL;
            return son_list;
        }
    }
};
```
## 总结
链表的问题注意画出草稿图，理清楚指针的操作步骤就可以了。写递归程序最重要是把调用函数当做已经执行完了返回了值，然后需要做的后续工作，不用管递归的函数是怎样做的。