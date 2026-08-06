class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), p = nums[0], ans = 0;
        if (n == 1)
        {
            if (k == nums[0])
            return 1; 
            return 0;
        }
        map<int, int> mp;
        mp[p]++;
        // cout<< mp[0]<< endl;
        if (p == k)
            ans ++;
        for (int i = 1; i < n; i++) {
            p += nums[i];
            if (p == k)
            ans ++;
            if (mp[p - k] > 0)
            ans += mp[p - k];
            mp[p]++;
            // cout<< mp[0]<< endl;
        }
        return ans;

        
    }
};