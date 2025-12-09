class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        map<long long int,long long int> pre;
        map<long long int,long long int> next;
        int mod=1e9+7;
        int n=nums.size();
        for(auto i:nums){
            next[i]++;
        }
        int ans=0;
        long long int w,t; 
        for(auto i:nums){
            next[i]--;
            next[i]=next[i]%mod;
            // if(i%2==0){
            t=1LL*i;
            if(pre[t*2]>=1&&next[t*2]>=1)
            {
                w=(pre[t*2]%mod)*(next[t*2]%mod)%mod;
                ans=(ans+w)%mod;
            }
            // }
            pre[i]++;
            pre[i]=pre[i]%mod;
            
        }
        return ans;
    }
};