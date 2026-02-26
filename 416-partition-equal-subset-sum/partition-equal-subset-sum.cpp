class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s=0,n=nums.size();
        for(auto i:nums) s+=i;
        if(s%2!=0)
        return false;
        vector<vector<int>> dp(n,vector<int>(s+1));
        dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=s;j++){
                if(dp[i-1][j]==true)
                {
                    dp[i][j]=true;
                    dp[i][j+nums[i]]=true;
                }
            }
        }
        return dp[n-1][s/2];
    }
};