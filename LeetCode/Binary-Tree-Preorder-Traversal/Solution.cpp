class Solution {
public:
    void dfs(TreeNode* node, vector<int>& result) {
        if (!node) return;
        result.push_back(node->val);   
        dfs(node->left, result);       
        dfs(node->right, result);      
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
};
