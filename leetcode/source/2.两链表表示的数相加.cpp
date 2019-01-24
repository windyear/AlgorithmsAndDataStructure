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
