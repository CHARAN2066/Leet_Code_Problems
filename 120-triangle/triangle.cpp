class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        dp[0][0]=triangle[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i==0&&j==0)
                continue;
                if(j==0)
                dp[i][j]=(triangle[i][j]+dp[i-1][j]);
                else if(j==i)
                dp[i][j]=(triangle[i][j]+dp[i-1][j-1]);
                else
                dp[i][j]=(triangle[i][j]+min(dp[i-1][j-1],dp[i-1][j]));
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            // cout<<dp[n-1][i]<<endl;
            ans=min(ans,dp[n-1][i]);
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=i;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};