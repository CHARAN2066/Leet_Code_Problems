class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if (i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == 0 || grid[i][j] == -1)
        return;
        // cout<< i<< j<<endl;
        grid[i][j] = -1;
        dfs(grid, i + 1, j, n, m);
        dfs(grid, i, j + 1, n, m);
        dfs(grid, i - 1, j, n, m);
        dfs(grid, i, j - 1, n, m);
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(),ans = 0;
        for (int i = 0; i < m; i++) {
            if(grid[0][i] == 1)
            dfs(grid, 0, i, n, m);
            if(grid[n - 1][i] == 1)
            dfs(grid, n - 1, i, n, m);
        }
        for (int i = 0; i < n; i++) {
            if(grid[i][0] == 1)
            dfs(grid, i, 0, n, m);
            if(grid[i][m - 1] == 1)
            dfs(grid, i, m - 1, n, m);
        }
        for (auto i:grid) {
            for (auto j:i) {
                if (j == 1)
                ans++;
            }
        }
        return ans;
    }
};