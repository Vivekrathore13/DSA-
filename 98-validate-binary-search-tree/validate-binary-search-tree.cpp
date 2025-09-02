class Solution {
public:
    bool helper(TreeNode* root, long long min, long long max) {
        if (!root) return true;
        
        // value must lie strictly between low and high
        if (root->val <= min || root->val >= max) return false;

        // left must be < root, right must be > root
        return helper(root->left, min, root->val) &&
               helper(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};
