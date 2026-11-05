class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int l, r, mid, ans = 0, n = arr2.size();
        bool flag = false;
        sort(arr2.begin(), arr2.end());
        for (auto i:arr1) {
            l = 0, r = n - 1;
            flag = false;
            while (l <= r) {
                mid = (l + r) / 2;
                if (arr2[mid] >= (i - d) && arr2[mid] <= (i + d)) {
                    flag = true;
                    break;
                }
                else if (arr2[mid] < (i - d)) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            if (!flag)
            ans++;

        }
        return ans;
    }
};