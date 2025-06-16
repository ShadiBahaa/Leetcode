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
    TreeNode * prev;
    void preOrder(TreeNode * root){
        //if(!prev)return;
        if(!root)return;
        //if(root->right)
        TreeNode * tmp1 = root->right;
        TreeNode * tmp2 = root->left;
        if(prev){
            prev->left = nullptr;
            prev->right = root;
        }
        
        prev = root;
        //if(root->left)
        preOrder(tmp2);
        //if(tmp)
        preOrder(tmp1);
    }
    void flatten(TreeNode* root) {
        prev = nullptr;
        preOrder(root);
    }
};
/*

*/