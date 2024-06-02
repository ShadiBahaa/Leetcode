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
    vector<int> post;
    vector<int> inor;
    TreeNode * insert(vector<int> v){
        if (v.size()==0){
            return nullptr;
        }
        TreeNode * root = nullptr;
        int cur = post[post.size()-1];
        post.pop_back();
        for (int i = 0; i<v.size(); i++){
            if (v[i]==cur){
                root = new TreeNode(cur);
                vector<int> rv,lv;
                for (int j = i+1; j<v.size(); ++j){
                    rv.push_back(v[j]);
                }
                for (int j = 0; j<i; ++j){
                    lv.push_back(v[j]);
                }
                root->right = insert(rv);
                root->left = insert(lv);
                break;
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post = postorder;
        inor = inorder;
        return insert(inorder);
    }
};