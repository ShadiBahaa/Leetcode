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
    int test(TreeNode* root, int max_val){
        if (root == nullptr)return 0;
        int res = 0;
        if (root->val >= max_val){
            res ++;
        }
        res += test(root->left, max(root->val,max_val));
        res += test(root->right, max(root->val,max_val));
        return res;
    }
    int goodNodes(TreeNode* root) {
        return test(root,-1e9);
    }
};