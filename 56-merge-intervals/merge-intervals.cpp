class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back({intervals[0][0], intervals[0][1]});
        int s, n = intervals.size();
        for (int i = 1; i < n; i++) {
            // cout<<'s';
            s = ans.size();
            if (ans[s - 1][1] >= intervals[i][0]) {
                ans[s - 1][1] = max(ans[s - 1][1], intervals[i][1]);
            }
            else
            ans.push_back({intervals[i][0], intervals[i][1]});
        }
        return ans;
    }
};