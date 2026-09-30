class Solution {
public:
    bool helper(vector<vector<char>>& grid, int i, int j, int n, int m, int balance,vector<vector<vector<int>>> &dp) {
        if (i == n - 1 && j == m - 1) {
            if (balance == 0)
            return true;
            else
            return false;
        }
        if (dp[i][j][balance] != -1)
        return dp[i][j][balance];
        bool a = false, b = false; 
        if (i + 1 < n && grid[i + 1][j] == '(') {
            a = helper(grid, i + 1, j, n, m, balance + 1, dp);
        }
        else if (i + 1 < n && grid[i + 1][j] == ')' && balance > 0) {
            a = helper(grid, i + 1, j, n, m,  balance - 1, dp);
        }
        if (j + 1 < m && grid[i][j + 1] == '(') {
            b = helper(grid, i, j + 1, n, m,  balance + 1, dp);
        }
        else if (j + 1 < m && grid[i][j + 1] == ')' && balance > 0) {
            b = helper(grid, i, j + 1, n, m,  balance - 1, dp);
        }
        return dp[i][j][balance] = (a | b);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), l = 0, r = 0, balance = (n + m);
        for (auto i:grid) {
            for (auto j:i) {
                if (j == '(')
                l++;
                else
                r++;
            }
        }
        vector<vector<bool>> visted(n, vector<bool> (m, false));
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (balance + 1, -1)));
        int a = 0, b = 0;
        if (grid[0][0] == '(') a++;
        else return false;
        return helper(grid, 0, 0, n, m, a, dp);
    }
};