class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        int a, b, d, n = grid.size(), m = grid[0].size();
        vector<vector<int>> dis(n, vector<int> (m, INT_MAX));
        dis[0][0] = grid[0][0];
        while (!pq.empty()) {
            d = pq.top().first;
            a = pq.top().second.first;
            b = pq.top().second.second;
            pq.pop();
            for (int i = -1; i <= 1; i++) {
                if (i == 0)
                continue;
                if (a + i < n && a + i >= 0) {
                    if (dis[a + i][b] > max(d, grid[a + i][b]))
                    {
                        dis[a + i][b] = max(d, grid[a + i][b]);
                        pq.push({dis[a + i][b], {a + i, b}});
                    }
                }
                if (b + i < m && b + i >= 0) {
                    if (dis[a][b + i] > max(d, grid[a][b + i]))
                    {
                        dis[a][b + i] = max(d, grid[a][b + i]);
                        pq.push({dis[a][b + i], {a, b + i}});
                    }
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};