/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空） 
class Solution {
public:
RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNodes(pHead);
        CloneRandom(pHead);
        return ReConnectNodes(pHead);
    }
       
    void CloneNodes(RandomListNode* pHead){
        RandomListNode* pCloned;
        while(pHead!=NULL){
            pCloned=new RandomListNode(pHead->label);
            pCloned->next=pHead->next;
            pHead->next=pCloned;
            pHead=pCloned->next;
        }
    }
       
    void CloneRandom(RandomListNode* pHead){
        RandomListNode* pCloned;
        while(pHead!=NULL){
            pCloned=pHead->next;
            if(pHead->random!=NULL){
                pCloned->random=pHead->random->next;
            }
            pHead=pCloned->next;
        }
    }
       
    RandomListNode* ReConnectNodes(RandomListNode* pHead){
        if(pHead==nullptr)
        return nullptr;
    RandomListNode* cloneHead = pHead->next;
    RandomListNode* cloneNode = cloneHead;
    RandomListNode* pNode = pHead;
    pNode->next = cloneNode->next;
    pNode = pNode->next;
      
    while(pNode){
        cloneNode->next = pNode->next;
        cloneNode = cloneNode->next;
        pNode->next = cloneNode->next;
        pNode = pNode->next;
    }
    return cloneHead;
    }
};
