class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int a = -1, b = -1, m = 0;
        int n  = mat.size(), l = mat[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < l; j++) {
                if (mat[i][j] > m) {
                    m = mat[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        return {a, b};
    }
};