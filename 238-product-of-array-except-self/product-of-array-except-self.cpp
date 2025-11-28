class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int z=0,n=nums.size();
        for(auto i:nums)
        {
            if(i==0)
            z++;
        }
        vector<int> ans(n,0);
        int pr=1;
        for(auto i:nums)
        {
            if(i==0)
            continue;
            pr*=i;
        }
        if(z>=2)
        return ans;
        else if(z==1)
        {   
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                ans[i]=pr;
                else
                ans[i]=0;
            }
            return ans;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                ans[i]=pr/nums[i];
            }
            return ans;
        }
        return ans;
    }
};