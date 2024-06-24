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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr)return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()){
            int sz = q.size();
            TreeNode * cur = nullptr;
            while (sz--){
                cur = q.front();
                q.pop();
                if (cur->left)q.push(cur->left);
                if (cur->right)q.push(cur->right);
            }
            if (cur != nullptr){
                ans.push_back(cur->val);
            }
        }
        return ans;
    }
};