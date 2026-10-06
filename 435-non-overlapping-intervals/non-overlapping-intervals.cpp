class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), l = 0, ans = 0;
        if (n == 1)
        return 0;
        l = arr[0][1];
        for (int i = 1; i < n; i++) {
            if (arr[i][0] < l)
            {
                ans++;
                l = min(l, arr[i][1]);
            }
            else
            l = arr[i][1];
        }
        return ans;
    }
};