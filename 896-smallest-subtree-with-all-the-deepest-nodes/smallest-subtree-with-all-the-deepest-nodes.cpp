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
    int h=0,f=0;
    int d=0;
    int fun(TreeNode* root){
        if(root==NULL)
        return 0;
        int a=1+fun(root->left);
        int b=1+fun(root->right);
        return max(a,b);
    }
    int fun2(TreeNode* root,int l){
        if(root==NULL)
        return 0;
        int a=1+fun2(root->left,l+1);
        int b=1+fun2(root->right,l+1);
        if(l==h-1){
            d++;
            // cout<<root->val<<endl;
        }
        return max(a,b);
    }
    // int f=d;
    TreeNode* ans=NULL;
    void fin(TreeNode* root,int l){
        if(root==NULL)
        return;
        d=0;
        int a=fun2(root,l);
        if(d==f)
        {
            // cout<<f<<endl;
            ans=root;
        }
        fin(root->left,l+1);
        fin(root->right,l+1);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        h=fun(root);
        int a=fun2(root,0);
        f=d;
        fin(root,0);
        if(ans!=NULL)
        cout<<ans->val<<endl;
        return ans;
    }
};