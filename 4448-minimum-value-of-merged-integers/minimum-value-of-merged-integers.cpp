class Solution {
public:
    int helper(int n1, int n2) {
        vector<int> digits, digits2;
        int r;
        while (n1 > 0) {
            r = n1 % 10;
            digits.push_back(r);
            n1 = n1 / 10;
        }
        reverse(digits.begin(), digits.end());
        while (n2 > 0) {
            r = n2 % 10;
            digits2.push_back(r);
            n2 = n2 / 10;
        }
        reverse(digits2.begin(), digits2.end());
        int ans = 0;
        for (auto i:digits) {
            ans = ans * 10 + i;
        }
        for (auto i:digits2) {
            ans = ans * 10 + i;
        }
        return ans;
    }
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX, a;
        for (int i = 0; i < n; i += 2) {
            a = helper(nums[i], nums[i + 1]);
            ans = min(ans, a);
        }
        return ans;
    }
};