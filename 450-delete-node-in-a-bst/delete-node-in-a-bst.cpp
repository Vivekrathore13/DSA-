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
    TreeNode* iop(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right!=NULL){
            pred=pred->right;
        }
        return pred;
    }
    TreeNode* ios(TreeNode* root){
        TreeNode* suc = root->right;
        while(root->left!=NULL){
            suc=suc->left;
        }
        return suc;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==NULL) return NULL;
    if(root->val==key){
    //Case 1 : No Child

    if(root->left==NULL && root->right==NULL) return NULL;
    // leaf node
    // case 2: 1 child
    if(root->left==NULL || root->right==NULL){
        if(root->left!=NULL) return root->left;
        else return root->right;
      }

      //case 3 : 2 child nodes
         if(root->left!=NULL && root->right!=NULL){
            // replace the root with its inorder predecsser or a successor
            //after the replacing delete the pre/suc
            TreeNode* pred=iop(root);
            root->val=pred->val;
            root->left=deleteNode(root->left,pred->val);
         }
    }
    else if(root->val>key){ //go left
    root->left=deleteNode(root->left,key);
    }   
    else { // root->val<key : go right
        root->right=deleteNode(root->right,key);
    }
    return root;
    }
};