class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visted(n, vector<bool> (m, false));
        vector<vector<int>> ans(n, vector<int> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0){
                    visted[i][j] = true;
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int a, b, s, level = 0;
        while (!q.empty()) {
            s = q.size();
            // level++;
            // cout<<s<<endl;
            for (int i = 0; i < s; i++)  {
                a = q.front().first;
                b = q.front().second;
                // cout<<a<<b<<" ";
                ans[a][b] = level;
                q.pop();
                if (a - 1 >= 0 && !visted[a - 1][b]) {
                    // ans[a - 1][b] = level;
                    visted[a - 1][b] = true;
                    q.push({a - 1, b});
                }
                if (b - 1 >= 0 && !visted[a][b - 1]) {
                    // ans[a][b - 1] = level;
                    visted[a][b - 1] = true;
                    q.push({a, b - 1});
                }
                if (a + 1 < n && !visted[a + 1][b]) {
                    // ans[a + 1][b] = level;
                    visted[a + 1][b] = true;
                    q.push({a + 1, b});
                }
                if (b + 1 < m && !visted[a][b + 1]) {
                    // ans[a][b + 1] = level;
                    visted[a][b + 1] = true;
                    q.push({a, b + 1});
                }
            }
            // cout<<endl;
            level++;
        }
        return ans;
    }
};