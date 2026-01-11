class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size(),s=0,ans=0,low=0;
        vector<int> zero(n);
        int z=n;
        for(int i=n-1;i>=0;i--){
            zero[i]=z-1;
            if(nums[i]==1)
            z=i;
        }
        for(auto i:zero)
        cout<<i<<" ";
        cout<<endl;
        for(int end=0;end<n;end++){
            s+=nums[end];
            // if(s==goal)
            // ans+=(1+zero[end]-end);
            while(s>=goal&&low<=end){
                if(s==goal){
                    if(zero[end]!=-1)
                    ans+=(1+zero[end]-end);
                    else{
                        ans++;
                    }
                }
                cout<<ans<<endl;
                s-=nums[low];
                low++;
                
            }
        }
        return ans;
    }
};