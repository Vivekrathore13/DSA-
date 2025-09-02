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
    TreeNode* build(vector<int>& pre,int prelo,int prehi,vector<int>& post ,int postlo,int posthi){
        if(prelo>prehi) return NULL;
        TreeNode* root =new TreeNode(pre[prelo]);
        if(prelo==prehi) return root;
        int i=postlo;
        while(i<=posthi){
            if(post[i]==pre[prelo+1]) break;
            i++;
        }
        int lc=i-postlo+1;
        int rc=posthi-i;
        root->left=build(pre,prelo+1,prelo+lc,post,postlo,posthi-rc);
        root->right=build(pre,prelo+lc+1,prehi,post,i+1,posthi-1);
        return root;
        }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    int n=pre.size();
    return build(pre,0,n-1,post,0,n-1);    
    }
};