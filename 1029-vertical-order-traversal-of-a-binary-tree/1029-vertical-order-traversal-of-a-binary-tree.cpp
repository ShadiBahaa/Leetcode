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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<tuple<TreeNode *, int, int>> q;
        q.push({root,0,0});
        while(!q.empty()){
            auto [cur , x , y] = q.front();
            q.pop();
            nodes[x][y].insert(cur->val);
            if(cur->left){
                q.push({cur->left,x-1,y+1});
            }
            if(cur->right){
                q.push({cur->right,x+1,y+1});
            }
        }
        vector<vector<int>> ans;
        for (auto it : nodes){
            vector<int> v;
            for (auto it2 : it.second){
                v.insert(v.end(),it2.second.begin(),it2.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};