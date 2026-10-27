class Solution {
public:
    long long int helper(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<bool>>& visted) {
        if (i == n || j == m || i == -1 || j == -1)
        return 0;
        if (grid[i][j] == 0 || visted[i][j])
        return 0;
        visted[i][j] = true;
        long long int a = helper(grid, i + 1, j, n, m, visted);
        long long int b = helper(grid, i, j + 1, n, m, visted);
        long long int c = helper(grid, i - 1, j, n, m, visted);
        long long int d = helper(grid, i, j - 1, n, m, visted);
        return grid[i][j] + a + b + c + d;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        long long int n = grid.size(), m = grid[0].size(), ans, res = 0;
        vector<vector<bool>> visted(n, vector<bool> (m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visted[i][j]) {
                    ans = helper(grid, i, j, n, m, visted);
                    // cout<<ans<<endl;
                    if (ans != 0 && ans % k == 0)
                    res++;
                }
            }
        }
        return res;
    }
};