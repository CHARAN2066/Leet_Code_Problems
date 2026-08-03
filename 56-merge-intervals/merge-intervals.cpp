class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), a = 0; 
        // for (auto i:intervals) {
        //     cout<< i[0]<< " "<< i[1]<<endl;
        // }
        for (int i = 1; i < n; i++) {
            if (intervals[a][1] >= intervals[i][0]) {
                // cout<<"s";
                intervals[a][1] = max(intervals[i][1], intervals[a][1]);
                intervals[i][0] = -1;
                intervals[i][1] = -1;
            }
            else {
                a = i;
            }
        }
        vector<vector<int>> ans;
        for (auto i:intervals) {
            if (i[0] == -1 && i[1] == -1)
            continue;
            ans.push_back({i[0], i[1]});
        }
        return ans;
    }
};