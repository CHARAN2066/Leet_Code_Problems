class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int l = 0, n = nums.size(), s = 0, ans = 1;
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] % k;
        }
        for (auto i:nums) 
        cout<<i<<" ";
        cout<<endl;
        for (int i = 0; i < n; i++) {
            map<int, int> mp;
            s = 0;
            for (int j = i; j < n; j++) {
                s += nums[j];
                mp[nums[j]]++;
                if ((((s - nums[j]) % k == 0) && mp.size() == 1) ||(s == 0))
                ans = max(ans, (j - i + 1));
            }
        }
        return ans;
    }
};