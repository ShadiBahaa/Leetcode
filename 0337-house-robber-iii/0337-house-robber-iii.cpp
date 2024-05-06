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
    pair<int,int> dfs(TreeNode * root){
        if (root == NULL){
            return {0,0};
        }
        pair<int,int> lef = dfs(root->left);
        pair<int,int> rig = dfs(root->right);
        
        pair<int,int> res;
        res.first = root->val + lef.second + rig.second;
        res.second = max(lef.first,lef.second) + max(rig.first,rig.second);
        return res;
    }
    int rob(TreeNode* root){
        pair<int,int> ret = dfs(root);
        return max(ret.first,ret.second);
    }
};