class Solution {
public:
    int helper(int amount ,vector<int> &coins,int i,int n,vector<vector<int>> &dp)
    {
        if(i==n||amount<0)
        return 0;
        if(amount==0)
        return 1;
        if(dp[i][amount]!=-1)
        return dp[i][amount];
        int a=helper(amount-coins[i],coins,i,n,dp);
        int b=helper(amount,coins,i+1,n,dp);
        return dp[i][amount]=a+b;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=helper(amount,coins,0,n,dp);
        return ans;
    }
};