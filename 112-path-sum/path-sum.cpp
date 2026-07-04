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
    bool helper(TreeNode* root,int curr,int targetSum){
        if(root==NULL)
        return false;
        curr+=root->val;
        if(root->left==NULL&&root->right==NULL){
            if(curr==targetSum)
            return true;
        }
        return helper(root->left,curr,targetSum)|helper(root->right,curr,targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root,0,targetSum);
    }
};