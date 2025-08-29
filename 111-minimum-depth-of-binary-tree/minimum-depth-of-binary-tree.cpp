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
    int minDepth(TreeNode* root) {
     if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int depth = 1;  // start at root level

    while (!q.empty()) {
        int levelSize = q.size();  // number of nodes in this level

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();

            // If it's a leaf → return immediately it is level 1 after depth is increment
            if (!node->left && !node->right) {
                return depth;
            }

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        depth++;  // move to next level
    }

    return depth;
    }
};