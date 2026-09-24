class Solution {
public:
    int sum_of_digits(int n) {
        int ans = 0, r;
        while (n > 0) {
            r = n % 10;
            ans += r;
            n = n / 10;
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            if (sum_of_digits(nums[i]) == i)
            return i;
        }
        return -1;
    }
};