class Solution {
public:
    int maxdia = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        // update diameter at this node
        maxdia = max(maxdia, left + right);

        // return height
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxdia;
    }
};
