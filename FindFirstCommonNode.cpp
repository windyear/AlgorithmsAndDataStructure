/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
       /*  if(pHead1 == NULL || pHead2 == NULL)
            return NULL;
        while(pHead1 != NULL && pHead2 != NULL){
            if(pHead1->next == pHead2->next)
                return pHead1->next;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return NULL; */
        //上述思路严重错误，因为链表不是一样长的，所以从头到尾遍历下去不一定能发现，
        //因为两个链表都是同步
        if(pHead1 == NULL || pHead2 == NULL)
            return NULL;
        //一种十分神奇的做法是将两个链表连起来走，每次都是走一步，总会走到共同节点或者都是空的那里。
        //关键的代码是当遍历到一个链表的结尾的时候，继续从另个一链表的头部开始遍历，所以要保存好链表头
        ListNode * pNode1 = pHead1;
        ListNode * pNode2 = pHead2;
        //只要两个结点指针不相等就向前遍历一次，知道链表尾，再从另一个链表开始遍历
        while(pNode1 != pNode2){
            pNode1 = (pNode1 == NULL) ? (pNode1 = pHead2) : (pNode1 = pNode1->next);
            pNode2 = (pNode2 == NULL) ? (pNode2 = pHead1) : (pNode2 = pNode2->next);
        }
        return pNode1;
    }
    
    ListNode* FindFirstCommonNode2(ListNode* pHead1, ListNode* pHead2){
        //如果有共同结点，之后的结点肯定相同，可以先让一个链表走长度差值的步数，之后共同遍历，有公共结点的
        //必然会找到公共结点
        if(pHead1 == NULL || pHead2 == NULL)
            return NULL;
        int len1 = 0, len2 = 0;
        ListNode* pNode1 = pHead1;
        ListNode* pNode2 = pHead2;
        while(pNode1 != NULL){
            len1++;
            pNode1 = pNode1->next;
        }
        while(pNode2 != NULL){
            len2++;
            pNode2 = pNode2->next;
        }
        int dif = len1 - len2;
        if(dif >= 0){
            while(dif > 0){
                pHead1 = pHead1->next;
                dif--;
            }
        }
        else{
            while(dif < 0){
                pHead2 = pHead2->next;
                dif++;
            }
        }
        while(pHead1 != NULL){
            if(pHead1 == pHead2)
                return pHead1;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead1;
    }
};