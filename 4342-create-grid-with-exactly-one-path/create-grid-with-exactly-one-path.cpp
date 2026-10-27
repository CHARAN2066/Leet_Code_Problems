class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string temp;
        for (int i = 0;i < m; i++) {
            temp = "";
            for (int j = 0; j < n; j++) {
                temp.push_back('#');
            }
            ans.push_back(temp);
        }
        for (int i = 0; i < m; i++) {
            ans[i][0] = '.';
        }
        for (int i = 0; i < n; i++) {
            ans[m - 1][i] = '.';
        }
        return ans;
    }
};