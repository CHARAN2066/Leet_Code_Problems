class Solution {
public:
    int missingInteger(vector<int>& nums) {
        map<int, int> mp;
        for (auto i:nums) mp[i]++;
        int n = nums.size(), ans = 0, c = 1, s = nums[0], fs = 0;
        if (n == 1)
        return nums[0] + 1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] + 1 == nums[i + 1]) {
                c++;
                s += nums[i + 1];
            }
            else {
                break;
            }
        }
        if (ans < c) {
           ans = c;
            fs = s;
        }
        // cout<< c<< endl;
        while (true) {
            if (mp[fs] == 0)
            return fs;
            fs++;
        }
        return 0;
    }
};