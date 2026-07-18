class Solution {
public:
    int findGCD(vector<int>& nums) {
        int m = 0, mi = INT_MAX, ans;
        for (auto i:nums) {
            m = max(m, i);
            mi = min(mi, i);
        }
        for (int i = 1; i <= min(m, mi); i++) {
            if (m % i == 0 && mi % i == 0)
            ans = i;
        }
        return ans;
    }
};