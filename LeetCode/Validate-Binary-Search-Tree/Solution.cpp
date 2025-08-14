class Solution {
public:
    bool helper(TreeNode* node, long long minVal, long long maxVal) {
        if (!node) return true;  

        if (node->val <= minVal || node->val >= maxVal) return false;

        return helper(node->left, minVal, node->val) &&
               helper(node->right, node->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};
