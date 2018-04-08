/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==nullptr)
            return nullptr;
        std::stack<TreeNode*>nodes;
        TreeNode* pNode = pRootOfTree;
        TreeNode* pListHead = nullptr;
        TreeNode* pListCur = nullptr;
        while(pNode){
            nodes.push(pNode);
            pNode = pNode->left;
        }
        pNode = nodes.top();
        nodes.pop();
        pListHead = pListCur = pNode;
        pNode = pNode->right;
        while(!nodes.empty()||pNode!=nullptr){
            if(pNode){
                nodes.push(pNode);
                pNode = pNode->left;
            }
            else{
                pNode = nodes.top();
                nodes.pop();
                pListCur->right = pNode; //next
                pNode->left = pListCur; //pre
                pListCur = pNode;
                pNode = pNode->right;
            }
        }
        return pListHead;
    }
};
