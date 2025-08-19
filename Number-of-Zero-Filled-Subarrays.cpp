class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        long long z=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            z++;
            else
            {
                ans+=((z*(z+1))/2);
                z=0;
            }
        }
        ans+=((z*(z+1))/2);
        return ans;
    }
};