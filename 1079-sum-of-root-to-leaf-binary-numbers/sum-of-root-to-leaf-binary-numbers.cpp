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
    void helper(TreeNode* root,int temp,int &ans){
        if(root==NULL)
        return;
        if(root->left==NULL&&root->right==NULL){
            temp=(temp<<1);
            if(root->val==1)
            temp+=1;
            // cout<<temp<<endl;
            ans+=temp;
            return;
        }
        // cout<<temp<<endl;
        temp=(temp<<1);
        if(root->val==1)
        temp+=1;
        helper(root->left,temp,ans);
        helper(root->right,temp,ans);
        
    }
    int sumRootToLeaf(TreeNode* root) {
        int temp=0,ans=0;
        helper(root,temp,ans);
        return ans;
        
    }
};