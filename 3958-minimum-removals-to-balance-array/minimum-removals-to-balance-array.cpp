class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long int ans=INT_MAX,n=nums.size(),j=0;
        for(long long int i=0;i<n;i++){
            while(j<n&&nums[j]<=static_cast<long long>(nums[i])*static_cast<long long>(k)){
                ans=min(ans,(n-(j-i+1)));
                j++;
                // cout<<i<<" "<<j<<endl;
            }
        }
        return ans;
        
    }
};