/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
//输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> result;
        if(root==nullptr)
            return result;
        std::stack<TreeNode*>nodes;
        vector<int>path;
        int curSum = 0;
        TreeNode *pNode = root;
        nodes.push(root);
        while(!nodes.empty()){
            pNode = nodes.top();
            nodes.pop();
            curSum+=pNode->val;
            path.push_back(pNode->val);
             
            if(pNode->right)
                nodes.push(pNode->right);
             
            if(pNode->left)
                nodes.push(pNode->left);
             
            if(pNode->left==nullptr&&pNode->right==nullptr)
            {
                if(curSum == expectNumber)
                    result.push_back(path);
                     
                while(path.size()>(nodes.size()/2+1)){
                    int val = path.back();
                    path.pop_back();
                    curSum -= val;
                }
            }
        }
        return result;
    }
};
