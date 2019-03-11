//
// Created by windyear_office on 19-3-11.
//
#include <cstdlib>
 //Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

// 快速排序，前后指针。归并需要额外空间，快排不用。但是指针很难操作，需要返回指针和它前一个指针。
// 此题太难先跳过。
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        quickSort(head, NULL);
        return head;
    }

    void swap(ListNode* a, ListNode* b){
        int tmp = a->val;
        a->val = b->val;
        b->val = tmp;
    }
    // 不能返回索引，所以只能返回节点指针，右边的指针表示结尾，不能到达
    ListNode* partition(ListNode* left, ListNode* right){
        if(left == NULL){
            return NULL;
        }
        ListNode* p = left;
        ListNode* q = p->next;
        int key = left->val;
        while(q != right){
            if(q->val <= key){
                p=p->next;
                swap(p, q);
            }
            q = q->next;
        }
        swap(left, p);
        return p;
    }
    void quickSort(ListNode* left, ListNode* right){
        if(left == right){
            return;
        }
        ListNode* part = partition(left, right);
        quickSort(left, part);
        quickSort(part->next, right);
        //quickSort
    }

};
