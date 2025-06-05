/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    void inorder(TreeNode * root){
        if(root == nullptr)return;
        if(root->left)inorder(root->left);
        ans.push_back(root->val);
        if(root->right)inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        int mini = 1e9;
        inorder(root);
        for(int i = 1; i<ans.size(); ++i){
            mini = min(mini,ans[i]-ans[i-1]);
        }
        return mini;
    }
};