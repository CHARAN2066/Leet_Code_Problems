class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int c=0,ans=0,n=nums.size(),low=0;
        vector<int> odd(n);
        int o=n;
        for(int i=n-1;i>=0;i--){
            odd[i]=o-1;
            if(nums[i]%2!=0)
            o=i;
        }
        // for(auto i:odd){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        for(int end=0;end<n;end++){
            if(nums[end]%2!=0)
            c++;
            if(c==k)
            ans+=(odd[end]-end+1);
            while(c>=k&&low<=end){
                if(nums[low]%2!=0)
                c--;
                low++;
                if(c==k)
                ans+=(odd[end]-end+1);
            }
        }
        return ans;

        
    }
};