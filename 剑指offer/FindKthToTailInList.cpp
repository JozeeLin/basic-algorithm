//输入一个链表，输出该链表中倒数第k个结点
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL || k<=0)
            return NULL;
        ListNode* pNode = pListHead;
        ListNode* pKNode = NULL;
        unsigned int i=0;
        for(;i<k&&pNode!=NULL;i++){
            pNode = pNode->next;
        }
        if(i==k){
            pKNode = pListHead;
            while(pNode!=NULL){
                pNode = pNode->next;
                pKNode = pKNode->next;
            }
        }
        return pKNode;
    }
};
