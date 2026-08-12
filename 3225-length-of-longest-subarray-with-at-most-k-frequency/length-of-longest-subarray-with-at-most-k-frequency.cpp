class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, n = nums.size(), st = 0;
        map<int, int> mp;
        for (int end = 0; end < n; end++) {
            mp[nums[end]]++;
            while (mp[nums[end]] > k) {
                mp[nums[st]]--;
                st++;
            }
            ans = max(ans, (end - st + 1));
        }
        return ans;
    }
};