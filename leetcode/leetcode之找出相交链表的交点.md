---
title: leetcode之找出相交链表的交点
tags: leetcode,算法, C++
grammar_cjkRuby: true
---
## 题目
- 编写一个程序，找到两个单链表相交的起始节点。
- 如果相交只会是y型相交，如果不想交就返回空指针。
- **O(1)空间和O(n)时间**
## 分析
- 直接采取暴力二重循环可以求解，但是超过时间限制。
- 一个思路是先找出两个链表长度相差的值，然后一个链表先走相差的步数，如果相交，可以找到相交的节点。
- 还有一个方法是建立hash表，但是超出存储的限制了。
- 一种比较巧妙的方法是人工构建环，如果从A的尾部接到B的头部后构成了环，说明相交，但是找出相交的节点还比较麻烦。
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
static int x = []() {
	ios::sync_with_stdio(false);    // cin与stdin禁止同步
	cin.tie(NULL);                  //cin与cout解除绑定
	return 0;
}();
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 排除两个节点有一个为空的情况
        if((headA == NULL) || (headB == NULL)){
            return NULL;
        }
        // 先遍历统计一个两个链表的长度，然后使指针同步。即更长的先走几步。
        int count_a = 0;
        int count_b = 0;
        ListNode* point_a = headA;
        ListNode* point_b = headB;
        while(point_a != NULL){
            count_a += 1;
            point_a = point_a->next;
        }
        while(point_b != NULL){
            count_b += 1;
            point_b = point_b->next;
        }
        if(count_a > count_b){
            int c = count_a - count_b;
            while(c > 0){
                headA = headA->next;
                c = c -1;
            }
            while(headA != NULL){
                if(headA == headB){
                    return headA;
                }else{
                    headA = headA->next;
                    headB = headB->next;
                }
            }
        }else if(count_a < count_b){
            int c = count_b - count_a;
            while(c > 0){
                headB = headB->next;
                c = c-1;
            }
            while(headA != NULL){
                if(headA == headB){
                    return headA;
                }else{
                    headA = headA->next;
                    headB = headB->next;
                }
            }
        }
        else{
            while(headA != NULL){
                if(headA == headB){
                    return headA;
                }else{
                    headA = headA->next;
                    headB = headB->next;
                }
            }
        }
        return NULL;
    }
};
```
## 总结
写的比较啰嗦，应该还可以简化。这道题不仅是判断相交，还要找出交点。还是通过画图得出相交后的节点都是相同的，所以将链表变为等长然后同时遍历即可。