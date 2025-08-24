class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int n=nums.size(),o=0,z=0,ans=0,s=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            o++;
            else
            z++;
            while(z>=2)
            {
                if(nums[s]==1)
                o--;
                else
                z--;
                s++;
            }
            ans=max(ans,(i-s));
        }
        return ans;
    }
};