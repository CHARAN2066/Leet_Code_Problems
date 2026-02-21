class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        map<int,bool> mp;
        if(amount==0)
        return 0;
        int n=coins.size();
        for(auto i:coins){
            mp[i]=true;
        }
        vector<int> dp(amount+1,INT_MAX);
        if(mp.find(1)!=mp.end())
        dp[1]=1;
        else
        dp[1]=INT_MAX;
        for(int i=2;i<=amount;i++){
            if(mp.find(i)!=mp.end())
            dp[i]=1;
            for(int j=0;j<n;j++){
                if(coins[j]<i&&dp[i-coins[j]]!=INT_MAX)
                dp[i]=min(dp[i-coins[j]]+1,dp[i]);
            }
        }
        // for(auto i:dp)
        // cout<<i<<" ";
        // cout<<endl;
        // cout<<dp[amount];
        if(dp[amount]==INT_MAX)
        return -1;
        else
        return dp[amount];
    }
};