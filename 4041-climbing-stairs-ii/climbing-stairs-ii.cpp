class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        int a, b, c;
        for (int i = 1; i <= n; i++) {
            if (i - 1 >= 0) {
                a = dp[i - 1] + cost[i - 1] + 1;
                dp[i] = min(dp[i], a);
            }
            if (i - 2 >= 0) {
                a = dp[i - 2] + cost[i - 1] + 4;
                dp[i] = min(dp[i], a);
            }
            if (i - 3 >= 0) {
                a = dp[i - 3] + cost[i - 1] + 9;
                dp[i] = min(dp[i], a);
            }
        }
        // for (auto i:dp) {
        //     cout<<i<<" ";
        // }
        return dp[n];
    }
};