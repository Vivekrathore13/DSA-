class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;

        currentSum = currentSum * 10 + node->val;

        // If it's a leaf node, return the number formed
        if (!node->left && !node->right)
            return currentSum;

        // Recur for left and right subtrees
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};
