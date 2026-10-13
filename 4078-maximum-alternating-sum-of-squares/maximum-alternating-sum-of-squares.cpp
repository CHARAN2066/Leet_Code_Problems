class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end(), greater<int> ());
        // for (auto i:nums) {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        int a;
        if (n % 2 == 0)
        a = (n / 2);
        else 
        a = (n / 2) + 1;
        // int a = (n / 2) ? (n % 2 == 0) : ((n / 2) + 1);
        cout<<a<<endl;
        for (int i = 0; i < a; i++) {
            ans += nums[i];
        }
        for (int i = a; i < n; i++) {
            ans -= nums[i];
        }
        return ans;
    }
};