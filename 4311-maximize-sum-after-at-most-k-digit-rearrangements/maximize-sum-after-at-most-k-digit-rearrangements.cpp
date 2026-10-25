class Solution {
public:
    long long helper(int n) {
        vector<int> digits;
        int r;
        while (n > 0) {
            r = n % 10;
            digits.push_back(r);
            n = n / 10;
        }
        sort(digits.begin(), digits.end(), greater<int>());
        int ans = 0;
        for (auto i:digits) {
            ans = ans * 10 + i;
        }
        return ans;

    }
    long long maximizeSum(vector<int>& nums, int k) {
        vector<pair<long long int,long long int>> arr;
        long long int n = nums.size();
        vector<bool> flag(n, false); 
        for (long long int i = 0; i < n; i++) {
            arr.push_back({(helper(nums[i]) - nums[i]), i});
        }
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());
        long long int i = 0, ans = 0; 
        for (long long int i = 0; i < k; i++) {
            // cout<<nums[arr[i].second]<<" ";
            flag[arr[i].second] = true;
            ans += helper(nums[arr[i].second]);
        }
        for (long long int i = 0; i < n; i++) {
            if (!flag[i])
            ans += nums[i];
        }
        return ans;
    }
};