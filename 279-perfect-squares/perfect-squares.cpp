class Solution {
public:
    int root;
    int helper(int n, int i, vector<vector<int>> &dp) {
        if (i < 1 || n < 0)
        return 1e5;
        if (n == 0)
        {
            // cout<<"s"<<endl;
            return 0;
        }
        if (dp[n][i] != -1)
        return dp[n][i];
        int a = 1 + helper((n -  (i * i)), i, dp);
        int b = helper((n), i - 1, dp);
        return dp[n][i] = min(a, b);
    }
    int numSquares(int n) {
        double temp = sqrt(n);
        root = ceil(temp);
        // cout<<root<<endl;
        vector<vector<int>> dp(n + 1, vector<int> (root + 1, -1));
        int ans = helper(n, root, dp);
        return ans;
    }
};