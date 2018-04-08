/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
//从上往下打印出二叉树的每个节点，同层节点从左至右打印
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        std::deque<TreeNode *>nodes;
        vector<int> result;
        TreeNode* pNode = nullptr;
        if(root==nullptr)
            return result;
        nodes.push_back(root);
        while(nodes.size()){
            pNode = nodes.front();
            nodes.pop_front();
            result.push_back(pNode->val);
            if(pNode->left)
                nodes.push_back(pNode->left);
            if(pNode->right)
                nodes.push_back(pNode->right);
        }
        return result;
    }
};
