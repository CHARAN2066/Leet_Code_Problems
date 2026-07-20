class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> ans;
        for (auto i:grid) {
            for (auto j:i) {
                ans.push_back(j);
            }
        }
        int n = ans.size();
        k = k % n;
        n = grid.size(); 
        int l = ans.size() - k;
        int m = grid[0].size();
        vector<vector<int>> res(n, vector<int> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (l >= ans.size())
                l = 0;
                // cout<< l<< endl;
                res[i][j] = ans[l];
                // cout<< ans[l]<< endl;
                l++;
            }
        }
        return res;
    }
};