class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& ne) {
        int n = arr.size(), l, a = INT_MAX, b = INT_MIN;
        vector<vector<int>> ans;
        if (n == 0)
        {
            ans.push_back(ne);
            return ans;
        }
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (arr[i][1] < ne[0]) {
                if (!flag && a != INT_MAX && b != INT_MIN) {
                    // cout<<a<<" "<<b<<endl;
                    flag = true;
                    ans.push_back({a, b});
                    a = INT_MAX;
                    b = INT_MIN;
                }
                ans.push_back({arr[i][0], arr[i][1]});
            }
            else if (arr[i][0] > ne[1]) {
                if (!flag && a != INT_MAX && b != INT_MIN) {
                    // cout<<a<<" "<<b<<endl;
                    flag = true;
                    ans.push_back({a, b});
                    a = INT_MAX;
                    b = INT_MIN;
                }
                else if (!flag){
                    flag = true;
                    ans.push_back({ne[0], ne[1]});
                }
                ans.push_back({arr[i][0], arr[i][1]});
            }
            else if (arr[i][0] <= ne[0] || arr[i][1] >= ne[1]){
                // cout<<i<<endl;
                a = min({a, arr[i][0], ne[0]});
                b = max({b, arr[i][1], ne[1]});
            }
        }
        if (a != INT_MAX && b != INT_MIN) {
            // cout<<a<<" "<<b<<endl;
            flag = true;
            ans.push_back({a, b});
            a = INT_MAX;
            b = INT_MIN;
        }
        if (!flag) {
            ans.push_back(ne);
        }
        return ans;
    }
};