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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)return {};
        vector<vector<int>> ans;
        queue<TreeNode * > q;
        q.push(root);
        bool left = true;
        while(!q.empty()){
            int sz = q.size();
            vector<int> v;
            while(sz--){
                TreeNode* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            if(!left){
                reverse(v.begin(),v.end());
                left = true;
            }else {
                left = false;
            }
            ans.push_back(v);
        }
        return ans;
    }
};