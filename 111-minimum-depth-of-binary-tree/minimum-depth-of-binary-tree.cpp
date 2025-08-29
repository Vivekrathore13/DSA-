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

    // If left child is missing, take depth from right
    if (!root->left) return 1 + minDepth(root->right);

    // If right child is missing, take depth from left
    if (!root->right) return 1 + minDepth(root->left);

    // Both children exist → take the minimum
    return 1 + min(minDepth(root->left), minDepth(root->right));


    }
};