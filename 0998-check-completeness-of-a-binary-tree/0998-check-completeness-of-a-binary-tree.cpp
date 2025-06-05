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
    vector<int> depth;
    void dfs(TreeNode * root, int cur){
        if(root == nullptr){
            depth.push_back(cur);
            return;
        }
        dfs(root->left,cur+1);
        dfs(root->right,cur+1);
    }
    static bool by(const int &a, const int &b){
        return a > b;
    }
    bool isCompleteTree(TreeNode* root) {
        dfs(root,0);
        int fund = depth[0];
        vector<int> other = depth;
        sort(other.begin(),other.end(),by);
        for(int ele : depth){
            cout<<ele<<" ";
        }
        cout<<endl;
        for(int ele : other){
            cout<<ele<<" ";
        }
        cout<<endl;
        set<int> s;
        for (int i = 0 ; i<other.size(); ++i){
            if(other[i]!=depth[i])return false;
            s.insert(other[i]);
        }
        if(s.size()>2)return false;
        int cur = *(s.begin());
        for(int ele : s){
            if (abs(cur-ele)>1)return false;
        }
        return true;
    }
};