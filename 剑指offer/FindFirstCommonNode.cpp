/*
 *输入两个链表，找出它们的第一个公共节点。
 *先得到链表的长度，然后较长的链表先遍历，直到剩余长度等于短链表的总长度。
 *然后，两个链表同时遍历，直到两个链表的节点相等或链表遍历结束为止
 */
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        if(pHead1==nullptr || pHead2==nullptr)
            return nullptr;
        int length1 = 0;
        int length2 = 0;
        ListNode* pNode1=pHead1;
        ListNode* pNode2=pHead2;
        while(pNode1){
            length1++;
            pNode1=pNode1->next;
        }
        while(pNode2){
            length2++;
            pNode2=pNode2->next;
        }
        pNode1 = pHead1;
        pNode2 = pHead2;
        if(length2>length1){
            pNode1 = pHead2;
            pNode2 = pHead1;
        }
        for(int i=length2;i<length1;i++)
            pNode1 = pNode1->next;
        while(pNode1&&pNode2&&pNode1!=pNode2){
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        ListNode* result = pNode1;
        return result;
    }
};
