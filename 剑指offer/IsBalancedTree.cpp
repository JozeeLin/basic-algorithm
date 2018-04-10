/*
 * 输入一棵树的根节点，判断该树是否是平衡二叉树
 */
/*
 *如果一颗二叉树的每个节点的左右子树的深度之差都不大于1，那么这颗二叉树就是平衡二叉树
 */
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==nullptr)
            return true;
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        if(left-right>1 || left-right<-1)
            return false;
        return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
    }

    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==nullptr)
            return 0;
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        return left>right?left+1:right+1;
    }
};
