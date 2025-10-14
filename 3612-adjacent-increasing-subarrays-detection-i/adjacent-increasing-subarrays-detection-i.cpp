class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        bool flag=false;
        for(int i=0;i<=n-2*k;i++)
        {
            flag=true;
            for(int j=i;j<i+k-1;j++)
            {
                if(nums[j]>=nums[j+1])
                {
                flag=false;
                }
            }
            for(int j=i+k;j<i+2*k-1;j++)
            {
                if(nums[j]>=nums[j+1])
                {
                flag=false;
                }
            }
            if(flag==true)
                return true;
        }
        return false;
    }
};