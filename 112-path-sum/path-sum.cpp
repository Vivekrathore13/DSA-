class Solution {
public:
bool dfs(TreeNode* root, int sum, int targetSum) {
    if (!root) return false;

    sum += root->val;   // add current node value

    // If it's a leaf, check the sum
    if (!root->left && !root->right) {
        return (sum == targetSum);
    }

    // Explore left or right
    return dfs(root->left, sum, targetSum) ||
           dfs(root->right, sum, targetSum);
}
bool hasPathSum(TreeNode* root, int targetSum) {
     return dfs(root, 0, targetSum);
    }
};