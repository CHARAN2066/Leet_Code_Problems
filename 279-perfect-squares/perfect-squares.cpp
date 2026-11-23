class Solution {
public:
    int root;
    int helper(int n, int i, vector<vector<int>> &dp) {
        if (i > root || n < 0)
        return 1e5;
        if (n == 0)
        {
            // cout<<"s"<<endl;
            return 0;
        }
        if (dp[n][root] != -1)
        return dp[n][root];
        int a = 1 + helper((n -  (i * i)), i, dp);
        int b = helper((n), i + 1, dp);
        return dp[n][root] = min(a, b);
    }
    int numSquares(int n) {
        double temp = sqrt(n);
        root = ceil(temp);
        vector<vector<int>> dp(n + 1, vector<int> (root + 1, -1));
        int ans = helper(n, 1, dp);
        return ans;
    }
};