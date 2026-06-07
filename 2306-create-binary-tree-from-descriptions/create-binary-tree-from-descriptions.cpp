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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        map<int,pair<int,int>> mp;
        TreeNode *arr[100001]={NULL};
        int a[100001]={0};
        int n=descriptions.size();
        for(int i=0;i<n;i++)
        {
            if(descriptions[i][2]==1)
            mp[descriptions[i][0]].first=descriptions[i][1];
            else
            mp[descriptions [i][0]].second=descriptions[i][1];
            if(a[descriptions[i][0]]==0)
            a[descriptions[i][0]]=1;
            if(a[descriptions[i][1]]==0)
            a[descriptions[i][1]]=1;
            a[descriptions[i][1]]++;
        }
        int r=0;
        for(int i=1;i<=100000;i++)
        {
            TreeNode *node=new TreeNode(i);
            arr[i]=node;
            if(a[i]==1)
            r=i;
        }
        for(int i=0;i<n;i++)
        {
            arr[descriptions[i][0]]->left=arr[mp[descriptions[i][0]].first];
            arr[descriptions[i][0]]->right=arr[mp[descriptions[i][0]].second];
        } 
        return arr[r];
    }
};