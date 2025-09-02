class Solution {
public:
    TreeNode* build(vector<int>& pre,int prelo,int prehi, vector<int>& ino,int in,int inhi){
        //base case
        if(prelo>prehi) return NULL;
        //attach first root
    TreeNode* root=new TreeNode(pre[prelo]);
    if(prelo==prehi) return root;
    //find first root in the in order to find the length of left sub tree and right sub tree
    int i=in;
    while(i<=inhi){
        if(ino[i]==pre[prelo]) break;
        i++;
    }
    //leftcount
    int lc=i-in;
    //rightcount
    int rc=inhi-i;
    //using recursion build left and right of tree
    root->left=build(pre,prelo+1,prelo+lc,ino,in,i-1);
    root->right=build(pre,prelo+lc+1,prehi,ino,i+1,inhi);
    return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();
    return build(pre,0,n-1,in,0,n-1);    
    }
};