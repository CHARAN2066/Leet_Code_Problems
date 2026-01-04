class Solution {
public:
    bool fun(vector<int> &nums,int o,int mid){
        long long int ans=0;
        for(auto i:nums){
            if(i%mid!=0)
            ans++;
            ans+=(static_cast<long long>(i)/static_cast<long long>(mid));
            ans--;
        }
        if(ans<=o)
        return true;
        return false;
    }
    int minimumSize(vector<int>& nums, int o) {
        long long int s=0;
        for(auto i:nums){
            s=max(static_cast<long long>(i),s);
        }
        long long int low=1,high=s,mid,ans;
        while(low<=high){
            mid=(low+high)/2;
            cout<<mid<<endl;
            if(fun(nums,o,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};