class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int a, b, n = grid.size(), m = grid[0].size(), s, levels = 1;
        if (grid[0][0] == 1)
        return -1;
        queue<pair<int, int>> q;
        vector<vector<bool>> visted(n, vector<bool> (m, false));
        q.push({0, 0});
        while (!q.empty()) {
            s = q.size();
            for (int k = 0; k < s; k++)
            {
                a = q.front().first;
                b = q.front().second;
                if (a == n - 1 && b == m - 1)
                return levels;
                // visted[a][b] = true;
                q.pop();
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (i == 0 && j == 0)
                        continue;
                        if (a + i >= 0 && a + i < n && b + j >= 0 && b + j < n && !visted[i + a][j + b] && grid[i + a][j + b] == 0) {
                            visted[a + i][b + j] = true;
                            q.push({a + i, b + j});
                        }
                    }
                }
            }
            levels++;
        }
        return -1;
    }
};