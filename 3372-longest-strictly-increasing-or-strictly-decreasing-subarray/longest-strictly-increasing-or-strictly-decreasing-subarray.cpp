class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        bool flag=false;
        int ans=0;
        flag=false;
        for(int i=0;i<n;i++)
        {
            flag=false;
            for(int j=i;j<n-1;j++)
            {
                if(nums[j]<=nums[j+1])
                {
                    ans=max(ans,(j-i+1));
                    flag=true;
                    // cout<<i<<j<<endl;
                    break;
                }
            }
            if(!flag)
            {
                // cout<<i<<endl;
                ans=max(ans,(n-i));

            }
        }
        // cout<<ans<<endl;
        flag=false;
        for(int i=0;i<n;i++)
        {
            flag=false;
            for(int j=i;j<n-1;j++)
            {
                if(nums[j]>=nums[j+1])
                {
                    ans=max(ans,(j-i+1));
                    flag=true;
                    // cout<<i<<j<<endl;
                    break;
                }
            }
            if(!flag)
            {
                // cout<<i<<endl;
                ans=max(ans,(n-i));

            }
        }
        return ans;
    }
};