class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffix_max (n,0);
        suffix_max[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffix_max[i] = max(suffix_max[i+1], nums[i]);
        }
        // for(int i=0;i<n;i++)
        // cout<<suffix_min[i]<<" ";
        // cout<<endl;
        int ans = 0;
        for (int i = 0; i < n-k; i++) {
            ans = max(ans, nums[i] + suffix_max[i+k]);
        }
        return ans;
    }
};