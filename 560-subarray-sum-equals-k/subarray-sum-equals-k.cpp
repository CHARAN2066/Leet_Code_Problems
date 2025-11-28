class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        map<int,int> mp;
        mp[0]=1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(mp[prefix[i]-k]>=1)
            {
                // cout<<i<<endl;
                ans+=mp[prefix[i]-k];
            }
            mp[prefix[i]]++;

        }
        return ans;
    }
};