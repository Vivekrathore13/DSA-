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
    void help(TreeNode* root,string s,vector<string>& ans){
        if(root==NULL) return ;
        //conversion of value to string to upend the value
        string a= to_string(root->val);
        if(root->left==NULL && root->right==NULL) {
            s+=a;
            ans.push_back(s);
            return;
        }
        help(root->left,s+a+"->",ans);
        help(root->right,s+a+"->",ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
    //intution is making a helper function which contain node,empty string ,vector string answer
    vector<string> ans;
    help(root,"",ans);
    return ans;   
    }
};