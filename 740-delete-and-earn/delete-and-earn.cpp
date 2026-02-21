class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mi=INT_MAX,m=0,n=nums.size();
        map<int,int> mp;
        for(auto i:nums){
            m=max(m,i);
            mi=min(mi,i);
            mp[i]++;
        }
        vector<int> dp(m+1,0);
        // cout<<m<<mi<<endl;
        dp[mi]=mp[mi]*mi;
        for(int i=mi+1;i<=m;i++){
            dp[i]=max(dp[i-1],dp[i-2]+mp[i]*(i));
        }
        int ans=0;
        for(auto i:dp)
        {
            // cout<<i<<" ";
            ans=max(i,ans);
        }
        return ans;
    }
};