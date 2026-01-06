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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        int s=0,ans=INT_MIN,l,id,level=1;
        while(!q.empty()){
            s=0;
            l=q.size();
            for(int j=0;j<l;j++){
                temp=q.front();
                q.pop();
                s+=temp->val;
                if(temp->left!=NULL)
                q.push(temp->left);
                if(temp->right!=NULL)
                q.push(temp->right);
            }
            cout<<s<<endl;
            if(ans<s){
                ans=s;
                id=level;
            }
            level++;
        }
        return id;
    }
};