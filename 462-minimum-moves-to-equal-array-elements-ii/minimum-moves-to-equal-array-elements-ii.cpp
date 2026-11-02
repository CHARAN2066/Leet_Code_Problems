class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), a, b = -1;
        a = nums[(n / 2)];
        if (n % 2 == 0) {
            b = nums[(n / 2) - 1];
        }
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += abs(nums[i] - a);
        }
        if (b == -1)
        return s;
        int s2 = 0;
        for (int i = 0; i < n; i++) {
            s2 += abs(nums[i] - a);
        }
        return min(s, s2);
    }
};