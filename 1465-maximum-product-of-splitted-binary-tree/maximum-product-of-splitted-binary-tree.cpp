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
    long long mod=1e9+7,total=0,res=0;
    void total_sum(TreeNode* root){
        if(root==NULL)
        return;
        total=(total+root->val);
        total_sum(root->left);
        total_sum(root->right);
    }
    long long  fun(TreeNode* root){
        if(root==NULL)
        return 0;
        long long le=fun(root->left);
        long long ri=fun(root->right);
        res=max(res,(le*(total-le)));
        res=max(res,(ri*(total-ri)));
        // res=res%mod;
        // cout<<res<<endl;
        // cout<<total<<end
        // cout<<le<<" "<<total-le<<endl;
        return root->val+le+ri;
    }
    int maxProduct(TreeNode* root) {
        total_sum(root);
        // total%=mod;
        int a=fun(root);
        return res%mod;
    }
};