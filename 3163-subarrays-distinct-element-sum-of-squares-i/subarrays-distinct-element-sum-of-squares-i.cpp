class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0, n = nums.size(), s;
        for (int i = 0; i < n; i++) {
            map<int, int> mp;
            for (int j = i; j < n; j++) {
                mp[nums[j]]++;
                s = mp.size();
                ans += (s * s);
            }
        }
        return ans;
    }
};