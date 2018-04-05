/*
 * 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值
 * 思路:
 * 方案1：改变链表的结构，然后，遍历一遍新链表，输出结点的值
 * 方案2：使用栈，遍历整个链表，然后把链表节点值出栈打印
 * 方案3：使用递归
 *
 * 测试用例：输入链表有多个结点，只有一个结点，链表为null
 *
 * OJ:https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?rp=1&ru=/ta/coding-interviews
 */
struct ListNode{
    int m_nValue;
    int m_pNext;
}

//方案一:
void PrintReversingly_1(ListNode *pHead){
    ListNode *pPred = NULL;
    ListNode *pNode = pHead;
    ListNode *pNext = NULL;
    if(pHead == NULL)
        return;
    while(pNode!=NULL){
        pNext = pNode->m_pNext;
        pNode->m_pNext = pPred;
        pPred = pNode;
        pNode = pNext;
    }

    pNode = pPred;
    while(pNode != NULL){
        cout<<pNode->m_nValue<<'  '<<endl;
        pNode = pNode->m_pNext;
    }
    pHead = pPred;
}

//方案二
void PrintReversingly_2(ListNode* pHead){

    if(pHead == NULL)
        return;
    std::stack<ListNode *> nodes;
    ListNode *pNode = pHead;
    while(pNode != NULL){
        nodes.push(pNode->m_nValue);
        pNode = pNode->m_pNext;
    }

    while(!nodes.empty())
    {
        pNode = nodes.top();
        cout<<pNode->m_nValue<<'  '<<endl;
        nodes.pop();
    }
}

//方案三
void PrintReversingly_3(ListNode* pHead){
    if(pHead == NULL)
        return;
    PrintReversingly_3(pHead->m_nNext);
    cout<<pHead->m_nValue<<'  ';
}
