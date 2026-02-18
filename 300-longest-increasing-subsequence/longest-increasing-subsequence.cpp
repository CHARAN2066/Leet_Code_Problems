class Solution {
public:
    int helper(int n,int i,int prev,vector<int>& nums,vector<vector<int>> &dp){
        if(i==n)
        return 0;
        if(dp[i][prev+1]!=-1)
        return dp[i][prev+1];
        int pick=0,notpick=0;
        if(prev==-1||nums[i]>nums[prev]){
            pick=1+helper(n,i+1,i,nums,dp);
        }
        notpick=helper(n,i+1,prev,nums,dp); 
        return dp[i][prev+1]=max(pick,notpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return helper(n,0,-1,nums,dp);
    }
};