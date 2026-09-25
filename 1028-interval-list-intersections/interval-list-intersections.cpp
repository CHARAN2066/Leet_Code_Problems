class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i = 0, j = 0, n = firstList.size(), m = secondList.size(), a, b;
        while (i < n && j < m) {
            a = max(firstList[i][0], secondList[j][0]);
            b = min(firstList[i][1], secondList[j][1]);
            if (a <= b)
            ans.push_back({a, b});
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            }
            else {
                j++;
            }
        }
        return ans;
    }
};