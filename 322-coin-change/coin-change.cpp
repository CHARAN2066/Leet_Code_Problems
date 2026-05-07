class Solution {
public:
    int helper(vector<int> &coins,int i,int n,int amount,int curr,vector<vector<int>> &dp){
        if(curr>amount)
        return 1e5;
        if(curr==amount)
        return 0;
        if(i==n)
        return INT_MAX;
        if(dp[i][curr]!=-1)
        return dp[i][curr];
        if(coins[i]>amount)
        return 1e5;
        int a=helper(coins,i,n,amount,curr+coins[i],dp);
        int b=helper(coins,i+1,n,amount,curr,dp);
        return dp[i][curr]=min(a+1,b);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        sort(coins.begin(),coins.end());
        int ans=helper(coins,0,n,amount,0,dp);
        if(ans>=1e5)
        return -1;
        return ans;
    }
};