class Solution {
public:
    bool helper(vector<int> &nums, int i, int n, vector<int> &dp) {
        if (i >= n)
        return false;
        if (i == n - 1)
        return true;
        if (dp[i] != -1)
        return dp[i];
        int ans = false;
        for (int j = i + 1; j <= i + nums[i] && j < n; j++) {
            ans = ans || (helper(nums, j, n, dp));
        }
        return dp[i] = ans;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(nums, 0, n, dp);
    }
};