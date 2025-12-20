class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size(),low=0,high=n-1,mid;
        auto it=upper_bound(nums.begin(),nums.end(),0);
        int f=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]>0){
                high=mid-1;
                f=mid;
            }
            else{
                low=mid+1;
            }
        }
        low=0,high=n-1,mid;
        int s=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]<0){
                low=mid+1;
                s=mid;
            }
            else{
                high=mid-1;
            }
        }
        if(s==-1&&f==-1)
        return 0;
        else if(s==-1)
        return n-f;
        else if(f==-1)
        return s+1;
        else
        return max((n-f),(s+1));
    }
};