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
    vector<vector<int>> ans;
    void helper(TreeNode* root,int curr,vector<int> temp,int targetSum){
        if(root==NULL)
        return;
        temp.push_back(root->val);
        curr+=root->val;
        if(root->left==NULL&&root->right==NULL){
            if(curr==targetSum)
            {
                ans.push_back(temp);
            }
        }
        helper(root->left,curr,temp,targetSum);
        helper(root->right,curr,temp,targetSum);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        helper(root,0,temp,targetSum);
        return ans;
    }
};