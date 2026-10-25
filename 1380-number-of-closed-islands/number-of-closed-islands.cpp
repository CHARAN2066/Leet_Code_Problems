class Solution {
public:
    bool helper(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<bool>> &visted) {
        if (grid[i][j] == 0 && (i == 0 || j == 0 || i == n - 1 || j == m - 1))
        {
            visted[i][j] = true;
            return false;
        }
        if (i < 0 || j < 0 || i >= n || j >= m || visted[i][j] || grid[i][j] == 1)
        return true;
        visted[i][j] = true;
        bool ans = true, a, b, c, d;
        ans = ans & helper(grid, i + 1, j, n, m, visted);
        ans = ans & helper(grid, i, j + 1, n, m, visted);
        ans = ans & helper(grid, i - 1, j, n, m, visted);
        ans = ans & helper(grid, i, j - 1, n, m, visted);
        return ans;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<bool>> visted(n, vector<bool> (m, false));
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0 && !visted[i][j] && helper(grid, i, j, n, m, visted)) {
                    // cout<<i<<" "<<j<<endl;
                    ans++;
                }
            }
        }
        
        return ans;
    }

        // [0,0,1,1,0,1,0,0,1,0],
        // [1,1,*,1,1,0,1,1,1,0],
        // [1,*,1,1,1,0,0,1,1,0],
        // [0,1,1,0,0,0,0,1,*,1],
        // [0,0,0,0,0,0,1,1,1,0],
        // [0,1,0,1,0,1,0,1,1,1],
        // [1,*,1,*,1,1,0,0,0,1],
        // [1,1,1,1,1,1,0,0,0,0],
        // [1,1,1,0,0,1,0,1,0,1],
        // [1,1,1,0,1,1,0,1,1,0]
};