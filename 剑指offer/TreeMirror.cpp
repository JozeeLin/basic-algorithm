/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
//操作给定的二叉树，将其变换为源二叉树的镜像
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot==NULL || (pRoot->left==NULL&&pRoot->right==NULL))
            return;
        std::stack<TreeNode*> nodes;
        TreeNode* lNode = NULL;
        TreeNode* rNode = NULL;
        TreeNode* pNode = pRoot;
        nodes.push(pRoot);
        while(!nodes.empty()){
            pNode = nodes.top();
            nodes.pop();
            lNode = pNode->left;
            rNode = pNode->right;
            if(lNode==NULL && rNode==NULL)
                continue;
            pNode->left = rNode;
            pNode->right = lNode;
            if(lNode)
                nodes.push(lNode);
            if(rNode)
                nodes.push(rNode);
        }
    }
};
