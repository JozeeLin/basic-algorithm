/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL)
            return pHead2;
        if(pHead2==NULL)
            return pHead1;
        ListNode *pHead;
        if(pHead1->val <= pHead2->val){
            pHead = pHead1;
            pHead1 = pHead1->next;
        }
        else{
            pHead = pHead2;
            pHead2 = pHead->next;
        }
        ListNode *pNode = pHead;
        while(pHead1!=NULL && pHead2!=NULL){
            if(pHead1->val <= pHead2->val){
                pNode->next = pHead1;
                pHead1 = pHead1->next;
            }
            else{
                pNode->next = pHead2;
                pHead2 = pHead2->next;
            }
            pNode = pNode->next;
        }
        if(pHead1!=NULL)
            pNode->next = pHead1;
        else
            pNode->next = pHead2;
        return pHead;
    }
};
