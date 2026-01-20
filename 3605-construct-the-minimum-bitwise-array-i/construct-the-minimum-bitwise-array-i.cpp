class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            flag=false;
            for(int j=0;j<nums[i];j++)
            {
                if((j|(j+1))==nums[i])
                {
                    ans[i]=j;
                    flag=true;
                    break;
                }
            }
            if(!flag)
            ans[i]=-1;
        }
        return ans;
    }
};