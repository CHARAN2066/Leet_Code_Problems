class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long int n=nums.size();
        long long int r=nums[0];
        vector<bool> ans;
        ans.push_back(!(r%5));
        for(long long int i=1;i<n;i++)
        {
            r*=2;
            r+=nums[i];
            ans.push_back(!(r%5));
            r=r%5;
        }
        return ans;
    }
};