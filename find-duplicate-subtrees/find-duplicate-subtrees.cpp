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
    unordered_map<string,unordered_set<TreeNode *>> hashes;
    string hash(TreeNode * root){
        if(root == nullptr) return "";
        string code;
        code += to_string(root->val) + ",";
        code += hash(root->left) + ">";
        code += hash(root->right) + "<";
        hashes[code].insert(root);
        return code;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        hash(root);
        vector<TreeNode * > v;
        for (auto it : hashes){
            if(it.second.size()>1){
                cout<<it.first<<endl;
                v.push_back(*(it.second.begin()));
            }
        }
        return v;
    }
};