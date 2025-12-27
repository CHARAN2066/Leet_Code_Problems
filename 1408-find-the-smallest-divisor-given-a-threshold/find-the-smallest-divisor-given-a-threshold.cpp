class Solution {
public:
    int fun(vector<int> &nums,int k){
        int ans=0;
        for(auto i:nums){
            if(i%k!=0)
            ans+=((i/k)+1);
            else
            ans+=(i/k);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int h=0,l=1,mid;
        for(auto i:nums){
            h=max(h,i);
        }
        int ans=-1;
        while(l<=h){
            mid=(l+h)/2;
            if(fun(nums,mid)<=threshold){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};