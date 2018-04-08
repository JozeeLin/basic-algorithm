//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size()<=0 || vin.size()<=0)
            return NULL;
        int length = pre.size();
        return ConstructCore(pre,0, length-1,vin,0,length-1);
    }
     
    TreeNode *ConstructCore(vector<int> &pre, int preStart, int preEnd, vector<int>&vin, int inStart, int inEnd){
        int preLen = preEnd-preStart;
        int inLen = inEnd-inStart;
        if(preStart>preEnd || inStart>inEnd || preLen!=inLen)
            return nullptr;
        int rootValue = pre[preStart];
        int mid = inStart;
        while(inStart<=inEnd && vin[mid]!=rootValue){
            mid++;
        }
        int leftLen = mid-inStart;
        int rightLen = inEnd-mid;
        TreeNode *root = new TreeNode(rootValue);
        if(vin[mid]==rootValue){
            if(leftLen > 0){
                root->left = ConstructCore(pre,preStart+1,preStart+leftLen,vin,inStart,mid-1);
            }
            if(rightLen>0){
                root->right = ConstructCore(pre, preStart+leftLen+1, preEnd, vin, mid+1,inEnd);
            }
        }else
            return nullptr;//在中序遍历中没有对应的根节点
        return root;
    }
};
