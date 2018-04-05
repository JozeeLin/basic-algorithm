/*
 * 题目:已知二叉树的先序遍历和中序遍历，构建出该二叉树，并返回它
 * 思路:
 * 构建二叉树，可以通过分别构建二叉树的左子树和右子树
 * 首先二叉树先序遍历数组的第一个数为当前二叉树的根节点，在中序遍历数组中，
 * 根节点的左边元素为左子树的元素，右边元素为右子树的元素。那么可以通过递归
 * 分别构造左子树和右子树
 */
BinaryTreeNode* Construct(int *preorder, int *inorder, int length){
    if(preorder==nullptr || inorder==nullptr || length<=0)
        return NULL;
    return ConstructCore(preorder, preorder+length-1, inorder, inorderlength-1);
}

BinaryTreeNode* ConstructCore(int* preorder, int* preEnd, int* inorder, int* inEnd){
    if(preorder==NULL || preEnd==NULL || inorder==NULL||inEnd==NULL)
        return NULL;
    int rootValue = preorder[0];
    int *mid = inorder;
    while(*mid != rootValue && mid-inEnd<=0){
        mid++;
    }
    int leftLength = mid-inorder;
    int rightLength = inEnd - mid;
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = nullptr;
    root->m_pRight =nullptr;
    if(*mid == rootValue){
        //左子树存在
        if(leftLength>0){
            root->m_pLeft = ConstructCore(preorder+1, preorder+leftLength, inorder,mid-1);
        }
        //右子树存在
        if(rightLength>0){
            root->m_pRight = ConstructCore(preorder+leftLength+1, preEnd, mid+1, inEnd);
        }
    }
    else
        return NULL; //中序遍历数组中不存在对应的根节点
    return root;
}
